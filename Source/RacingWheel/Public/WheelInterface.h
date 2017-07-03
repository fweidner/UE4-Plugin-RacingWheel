/************************************************************************************
* Copyright (c) 2015-2016, TU-Ilmenau
* VWDS - Projekt Vista4F
* ===================================================================================
* ===================================================================================
* Authors:  Luis Rojas (luis-alejandro.rojas-vargas@tu-ilmenau.de)
*************************************************************************************/

#ifndef _WHEELINTERFACE_H
#define _WHEELINTERFACE_H

#include "Controller.h"

namespace ThrustmasterWheel
{
	class WheelLib
	{
	private:


	public:
		static Controller* getMyControl();

		static void WheelUpdate();
		static bool isWheelConnected();
		static bool ActivateWheel();
		static bool isGamepad();

		//Input
		static int getSteeringValue();
		static int getBrakeValue();
		static int getGasValue();
		static int getClutchValue();
		static bool getButtonStates(int Button);
		static int getActualGear();

		//Feedback / ForceFeedback
		static bool CreateRumbleEffect();
		static void PlayRumbleEffect(float Strength, int Length);

		static int CreateConstantEffect(int Level, int Length);
		static int CreateLeftRightEffect(int Left, int Right, int Length);

		static int UpdateConstantEffect(int Idx, int Level, int Length);
		static bool RunEffect(int Idx, int Iterations);
		static bool DeleteEffect(int Idx);
	};
}

#endif //_WHEELINTERFACE_H
