/************************************************************************************
* Copyright (c) 2015-2016, TU-Ilmenau
* VWDS - Projekt Vista4F
* ===================================================================================
* ===================================================================================
* Authors:  Luis Rojas (luis-alejandro.rojas-vargas@tu-ilmenau.de)
*************************************************************************************/

#include "Controller.h"

#include "RacingWheelPrivatePCH.h"


#include <iostream>

Controller::Controller()
{
	//Init SDL
	if (!InitLibrary())
		return;

	//Search and Open the First Devide
	OpenDevice();

	//Deactivate the Joystick Events
	SDL_JoystickEventState(SDL_DISABLE);
}

Controller::~Controller()
{
	//Close The Opened Device
	CloseDevice();
	//Close Shiffter
	CloseShifter();
	//Close The Libray
	CloseLibrary();
}

bool Controller::InitLibrary()
{
	if (SDL_Init(SDL_INIT_GAMECONTROLLER | SDL_INIT_HAPTIC) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

	_SDLIsInit = true;
	return true;
}

void Controller::CloseLibrary()
{
	SDL_Quit();
}

bool Controller::OpenDevice()
{
	int _NumDevices = SDL_NumJoysticks();

	for (int i = 0; i < _NumDevices; ++i)
	{
		//Get PID of the Device
		SDL_JoystickGUID ID = SDL_JoystickGetDeviceGUID(i);

		if (ID.data[2] != SHIFTER_PID) // Diferent from Shifter
		{
			//Test if the Device is Gamepad or Joystick
			if (SDL_IsGameController(i))
			{
				_JoyMode = true;
				_Controller = SDL_GameControllerOpen(i);
				if (_Controller)
				{
					_Joystick = SDL_GameControllerGetJoystick(_Controller);
					//std::cout << SDL_GameControllerMapping(_Controller) << std::endl;
					_JoystickAttached = true;
					return true;
				}
				else
				{
					std::cout << "Could not open gamecontroller: " << i << SDL_GetError() << std::endl;
					return false;
				}
			}
			else
			{
				_JoyMode = false;
				_Joystick = SDL_JoystickOpen(i);

				if (!_Joystick)
				{
					std::cout << "Could not open Joystick: " << i << SDL_GetError() << std::endl;
					return false;
				}
				else
				{
					_JoystickAttached = true;
					return true;
				}
			}
		}
	}

	return false;
}

void Controller::CloseDevice()
{
	if (_JoyMode)
	{
		if (_Controller != NULL)
			SDL_GameControllerClose(_Controller);
	}
	else
	{
		if (_Joystick != NULL)
			SDL_JoystickClose(_Joystick);
	}
	_JoystickAttached = false;
	printf("Device Disconnected");
}

void Controller::UpDateDevices()
{
	SDL_JoystickUpdate();

	if (SDL_JoystickGetAttached(_Joystick) != SDL_TRUE)
	{
		if (_JoystickAttached)
			CloseDevice();
		else
		{
			if (OpenDevice())
				printf("New Device Attached and Opened\n");
		}
	}
}

ForceFeedback* Controller::InitFeedBack()
{
	_FeedBack = new ForceFeedback(_Joystick);

	if (_FeedBack)
		return _FeedBack;
	else
		return NULL;
}

bool Controller::InitShifter()
{
	int _NumDevices = SDL_NumJoysticks();

	for (int i = 0; i < _NumDevices; ++i)
	{
		//Get PID of the Device
		SDL_JoystickGUID ID = SDL_JoystickGetDeviceGUID(i);

		if (ID.data[2] == SHIFTER_PID) // PID from TH8a Shifter
		{
			_Shifter = SDL_JoystickOpen(i);

			if (!_Shifter)
			{
				std::cout << "Could not open Shifter: " << i << SDL_GetError() << std::endl;
				return false;
			}
			else
			{
				_ShifterAttached = true;
				return true;
			}
		}
	}

	return false;
}

void Controller::CloseShifter()
{
	if (_Shifter != NULL)
		SDL_JoystickClose(_Shifter);
}

void Controller::PrintDeviceProperties()
{
	if (_Joystick != NULL)
	{
		std::cout << "Num Axis" << SDL_JoystickNumAxes(_Joystick) << std::endl;
		std::cout << "Num Balls" << SDL_JoystickNumBalls(_Joystick) << std::endl;
		std::cout << "Num Buttons" << SDL_JoystickNumButtons(_Joystick) << std::endl;
		std::cout << "Num Hats" << SDL_JoystickNumHats(_Joystick) << std::endl;

		/***** Haptic Properties *****/

		if (_FeedBack)
			_FeedBack->PrintHapticProperties();
	}

	if (_Shifter != NULL)
	{
		std::cout << "Num Axis" << SDL_JoystickNumAxes(_Shifter) << std::endl;
		std::cout << "Num Balls" << SDL_JoystickNumBalls(_Shifter) << std::endl;
		std::cout << "Num Buttons" << SDL_JoystickNumButtons(_Shifter) << std::endl;
		std::cout << "Num Hats" << SDL_JoystickNumHats(_Shifter) << std::endl;
	}
}

int Controller::getAxisValue(int Axis, bool IsTrigger)
{
	if (IsTrigger)
		return getTriggerFormat(SDL_JoystickGetAxis(_Joystick, Axis), true);
	else
		return SDL_JoystickGetAxis(_Joystick, Axis);
}

bool Controller::getButtonState(int Button)
{
	if (SDL_JoystickGetButton(_Joystick, Button) == 1)
		return true;
	else
		return false;
}

bool Controller::getShifterState(int Gear)
{
	if (SDL_JoystickGetButton(_Shifter, Gear - 1) == 1)
		return true;
	else
		return false;
}

int Controller::getGear()
{
	int x = 0;

	while (getShifterState(x) == false)
	{
		x++;
		if (x == ShifterButtonsCount)
			return 0;
	}
	return x;
}

float Controller::ShortToNormalizedFloat(short AxisVal)
{
	// normalize [-32768..32767] -> [-1..1]
	const float Norm = (AxisVal <= 0 ? 32768.f : 32767.f);
	return float(AxisVal) / Norm;
}

float Controller::intToNormalizedFloat(int AxisVal)
{
	// normalize [0..65535] -> [0..1]
	return float(AxisVal) / 65535;
}
