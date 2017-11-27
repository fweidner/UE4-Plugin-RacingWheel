/************************************************************************************
* Copyright (c) 2015-2016, TU-Ilmenau
* VWDS - Projekt Vista4F
* ===================================================================================
* ===================================================================================
* Authors:  Luis Rojas (luis-alejandro.rojas-vargas@tu-ilmenau.de)
*************************************************************************************/
#include "ForceFeedBack.h"


#include "RacingWheelPrivatePCH.h"


#include <iostream>

ForceFeedback::ForceFeedback(SDL_Joystick *Joystick)
{
	if (Joystick == NULL)
		return;

	_Joystick = Joystick;
	_NumHaptic = SDL_NumHaptics();

	if (_NumHaptic < 1)
	{
		std::cout << "No Haptic Devices" << std::endl;
		return;
	}

	if (SDL_JoystickIsHaptic(_Joystick) == SDL_FALSE)
	{
		std::cout << "Joystick is Not Haptic" << std::endl;
		return;
	}

	InitHaptic();
}

ForceFeedback::~ForceFeedback()
{
	if (_Haptic)
		SDL_HapticClose(_Haptic);
}

bool ForceFeedback::InitHaptic()
{
	if (_NumHaptic > 0)
	{
		if (_Haptic)
			SDL_HapticClose(_Haptic);

		// Open the device
		_Haptic = SDL_HapticOpen(0);
		//if (_Joystick != NULL)
		//	_Haptic = SDL_HapticOpenFromJoystick(_Joystick);		//Error from SDL

		if (_Haptic == NULL)
		{
			std::cout << "SDL_HapticOpen failed : " << SDL_GetError() << std::endl;
			return false;
		}

		return true;
	}
	else
		return false;
}

bool ForceFeedback::CreateRumbleEffect()
{
	// test simple rumble
	if (SDL_HapticRumbleSupported(_Haptic))
	{
		if (SDL_HapticRumbleInit(_Haptic) < 0)
		{
			std::cout << "SDL_HapticRumbleInit failed: " << SDL_GetError() << std::endl;
			return false;
		}

		return true;
	}

	return false;
}

void ForceFeedback::RunRumbleEffect(float strength, int Length)
{
	SDL_HapticRumblePlay(_Haptic, strength, Length);
	return;
}

int ForceFeedback::CreateConstantEffect(int Level, int Length)
{
	// See if it can do sine waves
	if ((SDL_HapticQuery(_Haptic) & SDL_HAPTIC_CONSTANT) == 0)
		return -1;

	// Create the effect.
	memset(&_Effect, 0, sizeof(SDL_HapticEffect)); // 0 is safe default
	_Effect.type = SDL_HAPTIC_CONSTANT;
	_Effect.constant.direction.type = SDL_HAPTIC_CARTESIAN; // Using cartesian direction encoding.
	_Effect.constant.direction.dir[0] = 0; // X position
	_Effect.constant.direction.dir[1] = 0; // Y position
	_Effect.constant.length = Length;
	_Effect.constant.level = Level;
	//_Effect.constant.attack_length = 500;
	//_Effect.constant.attack_level = 500;

	// Upload the effect
	_Effect_Id = SDL_HapticNewEffect(_Haptic, &_Effect);
	if (_Effect_Id < 0)
	{
		std::cout << "Failed to initialize force feedback effect: " << SDL_GetError() << std::endl;
		return -1;
	}

	return _Effect_Id;
}

int ForceFeedback::CreateSineEffect(int Level, int Length)
{
	// See if it can do sine waves
	if ((SDL_HapticQuery(_Haptic) & SDL_HAPTIC_SINE) == 0)
		return false;

	// Create the effect
	memset(&_Effect, 0, sizeof(SDL_HapticEffect)); // 0 is safe default
	_Effect.type = SDL_HAPTIC_SINE;
	_Effect.periodic.direction.type = SDL_HAPTIC_CARTESIAN; // Polar coordinates
	_Effect.periodic.direction.dir[0] = 0; // Force comes from south
	_Effect.periodic.direction.dir[1] = 1; // Force comes from south
	_Effect.periodic.period = 1000; // 1000 ms
	_Effect.periodic.magnitude = 20000; // 20000/32767 strength
	_Effect.periodic.length = 5000; // 5 seconds long
	_Effect.periodic.attack_length = 1000; // Takes 1 second to get max strength
	_Effect.periodic.fade_length = 1000; // Takes 1 second to fade away

	// Upload the effect
	_Effect_Id = SDL_HapticNewEffect(_Haptic, &_Effect);
	if (_Effect_Id < 0)
	{
		std::cout << "Failed to initialize force feedback effect: " << SDL_GetError() << std::endl;
		return -1;
	}

	return _Effect_Id;
}

int ForceFeedback::CreateLeftRightEffect(int LevelRight, int LevelLeft, int Length)
{
	// See if it can do sine waves
	if ((SDL_HapticQuery(_Haptic) & SDL_HAPTIC_LEFTRIGHT) == 0)
		return false;

	// Create the effect in Struct.
	memset(&_Effect, 0, sizeof(SDL_HapticEffect)); // 0 is safe default
	_Effect.type = SDL_HAPTIC_LEFTRIGHT;
	_Effect.leftright.type = SDL_HAPTIC_LEFTRIGHT;
	_Effect.leftright.length = Length;
	_Effect.leftright.small_magnitude = LevelRight;
	_Effect.leftright.large_magnitude = LevelLeft;

	// Create the effect
	_Effect_Id = SDL_HapticNewEffect(_Haptic, &_Effect);
	if (_Effect_Id < 0)
	{
		std::cout << "Failed to initialize force feedback effect: " << SDL_GetError() << std::endl;
		return -1;
	}

	return _Effect_Id;
}

int ForceFeedback::UpdateEffect(int Idx, int Level, int Length)
{
	_Effect.constant.length = Length;
	_Effect.constant.level = Level;

	_Effect_Id = SDL_HapticUpdateEffect(_Haptic, Idx, &_Effect);
	if (_Effect_Id < 0)
	{
		std::cout << "Failed to Update force feedback effect: " << SDL_GetError() << std::endl;
		return _Effect_Id;
	}

	//RunEffect(Idx, 1);
	return _Effect_Id;
}

bool ForceFeedback::RunEffect(int Idx, int Iterations)
{
	if (Idx < 0)
		return false;

	// Run the effect
	int Ret = SDL_HapticRunEffect(_Haptic, Idx, Iterations);
	if (Ret == 0)
		return true;
	else
		return false;
}

bool ForceFeedback::DeleteEffect(int Idx)
{
	// Delete the Effect
	SDL_HapticDestroyEffect(_Haptic, Idx);
	return false;
}

void ForceFeedback::PrintHapticProperties()
{
	if (_Haptic != NULL)
	{
		// Check the propertiies of the Haptic device
		printf("Num Effects Stored: %d\n", SDL_HapticNumEffects(_Haptic));
		printf("Num Effects Playing same Time: %d\n", SDL_HapticNumEffectsPlaying(_Haptic));

		unsigned int haptic_query = 0;
		haptic_query = SDL_HapticQuery(_Haptic);

		if (haptic_query & SDL_HAPTIC_CONSTANT)
			printf("SDL_HAPTIC_CONSTANT OK:\n");
		if (haptic_query & SDL_HAPTIC_SINE)
			printf("SDL_HAPTIC_SINE OK:\n");
		if (haptic_query & SDL_HAPTIC_LEFTRIGHT)
			printf("SDL_HAPTIC_LEFTRIGHT OK:\n");
		if (haptic_query & SDL_HAPTIC_TRIANGLE)
			printf("SDL_HAPTIC_TRIANGLE OK:\n");

		if (haptic_query & SDL_HAPTIC_SAWTOOTHUP)
			printf("SDL_HAPTIC_SAWTOOTHUP OK:\n");
		if (haptic_query & SDL_HAPTIC_SAWTOOTHDOWN)
			printf("SDL_HAPTIC_SAWTOOTHDOWN OK:\n");
		if (haptic_query & SDL_HAPTIC_RAMP)
			printf("SDL_HAPTIC_RAMP OK:\n");
		if (haptic_query & SDL_HAPTIC_SPRING)
			printf("SDL_HAPTIC_SPRING OK:\n");

		if (haptic_query & SDL_HAPTIC_DAMPER)
			printf("SDL_HAPTIC_DAMPER OK:\n");
		if (haptic_query & SDL_HAPTIC_INERTIA)
			printf("SDL_HAPTIC_INERTIA OK:\n");
		if (haptic_query & SDL_HAPTIC_FRICTION)
			printf("SDL_HAPTIC_FRICTION OK:\n");
		if (haptic_query & SDL_HAPTIC_CUSTOM)
			printf("SDL_HAPTIC_CUSTOM OK:\n");

		if (haptic_query & SDL_HAPTIC_GAIN)
			printf("SDL_HAPTIC_GAIN OK:\n");
		if (haptic_query & SDL_HAPTIC_AUTOCENTER)
			printf("SDL_HAPTIC_AUTOCENTER OK:\n");
		if (haptic_query & SDL_HAPTIC_STATUS)
			printf("SDL_HAPTIC_STATUS OK:\n");
		if (haptic_query & SDL_HAPTIC_PAUSE)
			printf("SDL_HAPTIC_PAUSE OK:\n");
	}
}