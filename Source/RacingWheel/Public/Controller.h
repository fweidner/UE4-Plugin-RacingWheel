/************************************************************************************
* Copyright (c) 2015-2016, TU-Ilmenau
* VWDS - Projekt Vista4F
* ===================================================================================
* ===================================================================================
* Authors:  Luis Rojas (luis-alejandro.rojas-vargas@tu-ilmenau.de)
*************************************************************************************/

#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include <SDL.h>
#include <SDL_haptic.h>
#include <SDL_gamecontroller.h>
#include <iostream>

#include "ForceFeedBack.h"

#define THRUSTMASTER_IDX 0
#define SHIFTER_PID 0x60

enum RacingWheelAxes
{
	Steering = 0,
	Brakes,
	Gas,
	Clutch,
	RacingWheeCountAxis
};

enum XboxControllerAxes
{
	LeftStickX = 0,
	LeftStickY,
	LeftTrigger,
	RightStickX,
	RightStickY,
	RightTrigger,
	XboxControllerAxesCount
};

enum RacingWheelButtons
{
	GearDown = 0,
	GearUp,
	LeftGreen,
	LeftPurple,
	RightRed,
	LeftWhite,
	KnobLeft,
	KnobRight,
	RightYellow,
	LeftYellow,
	Special_Xbox,
	SpecialYellow,
	KnobPush,
	RacingWheelButtonsCount
};

enum XboxControllerButtons
{
	Button_A = 0,
	Button_B,
	Button_X,
	Button_Y,
	Button_LB,
	Button_RB,
	Button_Select,
	Button_Start,
	Button_LStick,
	Button_RStick,
	Button_Xbox,
	XboxControllerButtonsCount
};

enum ShifterButtons
{
	Neutral = 0,
	FirstGear,
	SecondGear,
	ThirdGear,
	FourthGear,
	FifthGear,
	SixthGear,
	SeventhGear,
	Reverse,
	ShifterButtonsCount
};

class Controller
{
private:
	bool _SDLIsInit = false;						// Flag for the SDL Init
	bool _JoystickAttached = false;					// Flag if the Device is Attached
	bool _ShifterAttached = false;					// Flag if the Shifter is Attached

	SDL_GameController *_Controller = NULL;			// Handle from the Controller in Gamepad Mode
	SDL_Joystick *_Joystick = NULL;					// Handle from the Controller in Joy / Wheel Mode
	SDL_Joystick *_Shifter = NULL;					// Handle from the Shifter
	ForceFeedback *_FeedBack = NULL;				// Handle from the Feedback and Force feedback

	bool _JoyMode = false;							// Joystick = false / GamePad = True

public:

	Controller();
	~Controller();

	bool InitLibrary();
	void CloseLibrary();
	bool OpenDevice();
	void CloseDevice();
	void UpDateDevices();
	ForceFeedback* InitFeedBack();
	bool InitShifter();
	void CloseShifter();
	void PrintDeviceProperties();

	int getAxisValue(int Axis, bool IsTrigger);
	bool getButtonState(int Button);
	bool getShifterState(int Gear);
	int getGear();

	static float ShortToNormalizedFloat(short AxisVal);
	static float intToNormalizedFloat(int AxisVal);

	/******* Properties *******/
	bool isSDLInit() { return _SDLIsInit; }
	bool isControllerInit() { return _JoystickAttached; }

	SDL_Joystick* GetJoystickCtrl() { return _Joystick; }
	ForceFeedback* GetFeedBackCtrl() { return _FeedBack; }
	int GetNumDevices() { return SDL_NumJoysticks(); }
	bool isGamepad() { return _JoyMode; }

	bool IsHaptic() { if (SDL_JoystickIsHaptic(_Joystick) == 1) return true; else return false; }

	unsigned int GetPad() { return SDL_JoystickGetHat(_Joystick, 0); }

	inline int getTriggerFormat(int Value, bool Inverted)
	{
		if (Inverted)
			return (0x7FFF - Value);
		else
			return (Value + 0x8000);
	}
};


#endif //_CONTROLLER_H