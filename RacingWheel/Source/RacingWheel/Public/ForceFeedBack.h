/************************************************************************************
* Copyright (c) 2015-2016, TU-Ilmenau
* VWDS - Projekt Vista4F
* ===================================================================================
* ===================================================================================
* Authors:  Luis Rojas (luis-alejandro.rojas-vargas@tu-ilmenau.de)
*************************************************************************************/

#ifndef _FORCEFEEDBACK_H
#define _FORCEFEEDBACK_H

#include <SDL.h>
#include <SDL_haptic.h>

#include <iostream>

class ForceFeedback
{
private:
	SDL_Joystick *_Joystick = NULL;
	SDL_Haptic *_Haptic = NULL;
	SDL_HapticEffect _Effect;
	int _Effect_Id = -1;
	int _NumHaptic = 0;

public:

	ForceFeedback(SDL_Joystick *Joystick);
	~ForceFeedback();

	bool InitHaptic();

	bool CreateRumbleEffect();
	void RunRumbleEffect(float strength, int Length);
	
	bool CreateConstatEffectPolar(int Level, int Length);
	int CreateSineEffect(int Level, int Length);
	int CreateLeftRightEffect(int LevelRight, int LevelLeft, int Length);
	int CreateConstantEffect(int Level, int Length);
	
	int UpdateEffect(int Idx, int Level, int Length);
	bool RunEffect(int Idx, int Iterations);
	
	bool DeleteEffect(int Idx);

	void PrintHapticProperties();

	/******* Properties *******/
	bool IsInit() { if (_Haptic) return true; else return false; }
	int GetNumHaptics() { return _NumHaptic; }

};


#endif //_FORCEFEEDBACK