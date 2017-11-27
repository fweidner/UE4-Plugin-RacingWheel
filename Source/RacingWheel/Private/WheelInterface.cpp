 /************************************************************************************
* Copyright (c) 2015-2016, TU-Ilmenau
* VWDS - Projekt Vista4F
* ===================================================================================
* ===================================================================================
* Authors:  Luis Rojas (luis-alejandro.rojas-vargas@tu-ilmenau.de)
*************************************************************************************/
#include "WheelInterface.h"

#include "RacingWheelPrivatePCH.h"


static Controller *MyControl;
static ForceFeedback* myfeedBack;

namespace ThrustmasterWheel
{
	//Instance of the Library
	Controller* WheelLib::getMyControl()
	{
		return MyControl;
	}

	/***** Wheel Management *****/
	void WheelLib::WheelUpdate()
	{
		return MyControl->UpDateDevices();
	}

	bool WheelLib::isWheelConnected()
	{
		return MyControl->isControllerInit();
	}

	bool WheelLib::ActivateWheel()
	{
		MyControl = new Controller();
		myfeedBack = MyControl->InitFeedBack();
		MyControl->InitShifter();

		return MyControl->isControllerInit();
	}

	bool WheelLib::isGamepad()
	{
		return MyControl->isGamepad();
	}

	/***** Input ******/

	//Axes
	int WheelLib::getSteeringValue()
	{
		return MyControl->getAxisValue(RacingWheelAxes::Steering, false);
	}

	int WheelLib::getBrakeValue()
	{
		return MyControl->getAxisValue(RacingWheelAxes::Brakes, true);
	}

	int WheelLib::getGasValue()
	{
		return MyControl->getAxisValue(RacingWheelAxes::Gas, true);
	}

	int WheelLib::getClutchValue()
	{
		return MyControl->getAxisValue(RacingWheelAxes::Clutch, true);
	}

	//Buttons
	bool WheelLib::getButtonStates(int Button)
	{
		return MyControl->getButtonState(Button);
	}

	//Shifter
	int WheelLib::getActualGear()
	{
		return MyControl->getGear();
	}

	//Feedback / ForceFeedback
	bool WheelLib::CreateRumbleEffect()
	{
		return myfeedBack->CreateRumbleEffect();
	}

	void WheelLib::PlayRumbleEffect(float Strength, int Length)
	{
		myfeedBack->RunRumbleEffect(Strength, Length);
	}

	int WheelLib::CreateConstantEffect(int Level, int Length)
	{
		return myfeedBack->CreateConstantEffect(Level, Length);
	}

	int WheelLib::CreateLeftRightEffect(int Left, int Right, int Length)
	{
		return myfeedBack->CreateLeftRightEffect(Left, Right, Length);
	}

	int WheelLib::UpdateConstantEffect(int Idx, int Level, int Length)
	{
		return myfeedBack->UpdateEffect(Idx, Level, Length);
	}

	bool WheelLib::RunEffect(int Idx, int Iterations)
	{
		return myfeedBack->RunEffect(Idx, Iterations);
	}

	bool WheelLib::DeleteEffect(int Idx)
	{
		return myfeedBack->DeleteEffect(Idx);
	}
}
