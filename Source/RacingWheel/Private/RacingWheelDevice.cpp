/************************************************************************************
* Copyright (c) 2015-2016, TU-Ilmenau
* VWDS - Projekt Vista4F
* ===================================================================================
* ===================================================================================
* Authors:  Luis Rojas (luis-alejandro.rojas-vargas@tu-ilmenau.de)
*************************************************************************************/

#include "RacingWheelDevice.h"

#include "RacingWheelPrivatePCH.h"
#include "Internationalization/Internationalization.h" // LOCTEXT

#include "IInputDevice.h"


using namespace ThrustmasterWheel;

DEFINE_LOG_CATEGORY_STATIC(LogRacingWheelDevice, Log, All);
#define LOCTEXT_NAMESPACE "InputKeys"


FRacingWheel::FRacingWheel(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler) :
MessageHandler(InMessageHandler)
{
	//Start Device
	if (WheelLib::ActivateWheel())
	{
		UE_LOG(LogRacingWheelDevice, Warning, TEXT("Thrustmaster: Started - OK"));
	}
	else
	{
		UE_LOG(LogRacingWheelDevice, Warning, TEXT("Thrustmaster: Started - ERROR"));
	}

	InitialButtonRepeatDelay = 0.2f;
	ButtonRepeatDelay = 0.1f;

	// set up mapping
	Buttons[0] = ThrustmasterKeyNames::GearDown;
	Buttons[1] = ThrustmasterKeyNames::GearUp;
	Buttons[2] = ThrustmasterKeyNames::LeftGreen;
	Buttons[3] = ThrustmasterKeyNames::LeftPurple;
	Buttons[4] = ThrustmasterKeyNames::RightRed;
	Buttons[5] = ThrustmasterKeyNames::LeftWhite;
	Buttons[6] = ThrustmasterKeyNames::KnobLeft;
	Buttons[7] = ThrustmasterKeyNames::KnobRight;
	Buttons[8] = ThrustmasterKeyNames::LeftYellow;
	Buttons[9] = ThrustmasterKeyNames::RightYellow;
	Buttons[10] = ThrustmasterKeyNames::Xbox;
	Buttons[11] = ThrustmasterKeyNames::SpecialYellow;
	Buttons[12] = ThrustmasterKeyNames::KnobPush;

	// set up Shifter mapping
	ShButtons[0] = ThrustmasterShifterKeyNames::GearN;
	ShButtons[1] = ThrustmasterShifterKeyNames::Gear1;
	ShButtons[2] = ThrustmasterShifterKeyNames::Gear2;
	ShButtons[3] = ThrustmasterShifterKeyNames::Gear3;
	ShButtons[4] = ThrustmasterShifterKeyNames::Gear4;
	ShButtons[5] = ThrustmasterShifterKeyNames::Gear5;
	ShButtons[6] = ThrustmasterShifterKeyNames::Gear6;
	ShButtons[7] = ThrustmasterShifterKeyNames::Gear7;
	ShButtons[8] = ThrustmasterShifterKeyNames::GearR;

	/******* Register the FKeys and Categoryy for the Controller Type *******/

	// Thrustmaster Category
	EKeys::AddMenuCategoryDisplayInfo("Thrustmaster", LOCTEXT("ThrustmasterSubCateogry", "Thrustmaster"), TEXT("GraphEditor.PadEvent_16x"));

	// Thrustmaster Axis
	EKeys::AddKey(FKeyDetails(ThrustmasterAxisNames::Steering, LOCTEXT("WSteering", "Steering"), FKeyDetails::FloatAxis, "Thrustmaster"));
	EKeys::AddKey(FKeyDetails(ThrustmasterAxisNames::Gas, LOCTEXT("WGas", "Gas"), FKeyDetails::FloatAxis, "Thrustmaster"));
	EKeys::AddKey(FKeyDetails(ThrustmasterAxisNames::Brake, LOCTEXT("WBrake", "Brakes"), FKeyDetails::FloatAxis, "Thrustmaster"));
	EKeys::AddKey(FKeyDetails(ThrustmasterAxisNames::Clutch, LOCTEXT("WClutch", "Clutch"), FKeyDetails::FloatAxis, "Thrustmaster"));

	// Thrustmaster Keys
	EKeys::AddKey(FKeyDetails(ThrustmasterKeyNames::GearDown, LOCTEXT("GearDown", "Gear Down"), FKeyDetails::GamepadKey, "Thrustmaster"));
	EKeys::AddKey(FKeyDetails(ThrustmasterKeyNames::GearUp, LOCTEXT("GearUp", "Gear Up"), FKeyDetails::GamepadKey, "Thrustmaster"));
	EKeys::AddKey(FKeyDetails(ThrustmasterKeyNames::LeftGreen, LOCTEXT("LeftGreen", "Left Green"), FKeyDetails::GamepadKey, "Thrustmaster"));
	EKeys::AddKey(FKeyDetails(ThrustmasterKeyNames::LeftPurple, LOCTEXT("LeftPurple", "Left Purple"), FKeyDetails::GamepadKey, "Thrustmaster"));
	EKeys::AddKey(FKeyDetails(ThrustmasterKeyNames::RightRed, LOCTEXT("RightRed", "Right Red"), FKeyDetails::GamepadKey, "Thrustmaster"));
	EKeys::AddKey(FKeyDetails(ThrustmasterKeyNames::LeftWhite, LOCTEXT("LeftWhite", "Left White"), FKeyDetails::GamepadKey, "Thrustmaster"));
	EKeys::AddKey(FKeyDetails(ThrustmasterKeyNames::KnobLeft, LOCTEXT("KnobLeft", "Knob Left"), FKeyDetails::GamepadKey, "Thrustmaster"));
	EKeys::AddKey(FKeyDetails(ThrustmasterKeyNames::KnobRight, LOCTEXT("KnobRight", "Knob Right"), FKeyDetails::GamepadKey, "Thrustmaster"));
	EKeys::AddKey(FKeyDetails(ThrustmasterKeyNames::LeftYellow, LOCTEXT("LeftYellow", "Left Yellow"), FKeyDetails::GamepadKey, "Thrustmaster"));
	EKeys::AddKey(FKeyDetails(ThrustmasterKeyNames::RightYellow, LOCTEXT("RightYellow", "Right Yellow"), FKeyDetails::GamepadKey, "Thrustmaster"));
	EKeys::AddKey(FKeyDetails(ThrustmasterKeyNames::Xbox, LOCTEXT("sXbox", "Special Xbox"), FKeyDetails::GamepadKey, "Thrustmaster"));
	EKeys::AddKey(FKeyDetails(ThrustmasterKeyNames::SpecialYellow, LOCTEXT("SpecialYellow", "Special Yellow"), FKeyDetails::GamepadKey, "Thrustmaster"));
	EKeys::AddKey(FKeyDetails(ThrustmasterKeyNames::KnobPush, LOCTEXT("KnobPush", "Knob Push"), FKeyDetails::GamepadKey, "Thrustmaster"));

	// Thrustmaster Shifter Keys
	EKeys::AddKey(FKeyDetails(ThrustmasterShifterKeyNames::GearN, LOCTEXT("GearN", "Gear Neutro"), FKeyDetails::GamepadKey, "Thrustmaster"));
	EKeys::AddKey(FKeyDetails(ThrustmasterShifterKeyNames::Gear1, LOCTEXT("Gear1", "Gear One"), FKeyDetails::GamepadKey, "Thrustmaster"));
	EKeys::AddKey(FKeyDetails(ThrustmasterShifterKeyNames::Gear2, LOCTEXT("Gear2", "Gear Two"), FKeyDetails::GamepadKey, "Thrustmaster"));
	EKeys::AddKey(FKeyDetails(ThrustmasterShifterKeyNames::Gear3, LOCTEXT("Gear3", "Gear Three"), FKeyDetails::GamepadKey, "Thrustmaster"));
	EKeys::AddKey(FKeyDetails(ThrustmasterShifterKeyNames::Gear4, LOCTEXT("Gear4", "Gear Four"), FKeyDetails::GamepadKey, "Thrustmaster"));
	EKeys::AddKey(FKeyDetails(ThrustmasterShifterKeyNames::Gear5, LOCTEXT("Gear5", "Gear Five"), FKeyDetails::GamepadKey, "Thrustmaster"));
	EKeys::AddKey(FKeyDetails(ThrustmasterShifterKeyNames::Gear6, LOCTEXT("Gear6", "Gear Six"), FKeyDetails::GamepadKey, "Thrustmaster"));
	EKeys::AddKey(FKeyDetails(ThrustmasterShifterKeyNames::Gear7, LOCTEXT("Gear7", "Gear Seven"), FKeyDetails::GamepadKey, "Thrustmaster"));
	EKeys::AddKey(FKeyDetails(ThrustmasterShifterKeyNames::GearR, LOCTEXT("GearR", "Gear Reverse"), FKeyDetails::GamepadKey, "Thrustmaster"));

	/****** Create Feedback Effects ******/

	if (WheelLib::isWheelConnected())
	{
		if (WheelLib::isGamepad())
		{
			FidxL = WheelLib::CreateLeftRightEffect(25000, 0, 200);
			FidxR = WheelLib::CreateLeftRightEffect(0, 25000, 200);
		}
		else
		{
			FidxL = WheelLib::CreateConstantEffect(-25000, 200);
			FidxR = WheelLib::CreateConstantEffect(-25000, 200);
		}
	}
}

FRacingWheel::~FRacingWheel()
{
	//Dummy
}

void FRacingWheel::Tick(float DeltaTime)
{
	// Nothing necessary to do (boilerplate code to complete the interface)
}

void FRacingWheel::SendControllerEvents()
{
	//Update The Events from the Controller/Joystick and
	//Check for New Devices or Connect/Disconnet 
	WheelLib::WheelUpdate();

	if (WheelLib::isWheelConnected())
	{
		const double CurrentTime = FPlatformTime::Seconds();

		/********* Axes **********/
		int WSteering = WheelLib::getSteeringValue();
		int WGas = WheelLib::getGasValue();
		int WBrakes = WheelLib::getBrakeValue();
		int WClutch = WheelLib::getClutchValue();

		if (WheelStates.Steering != WSteering)
		{
			MessageHandler->OnControllerAnalog(ThrustmasterAxisNames::Steering, THRUSTMASTER_IDX, Controller::ShortToNormalizedFloat(WSteering));
			WheelStates.Steering = WSteering;
		}

		if (WheelStates.Gas != WGas)
		{
			MessageHandler->OnControllerAnalog(ThrustmasterAxisNames::Gas, THRUSTMASTER_IDX, Controller::intToNormalizedFloat(WGas));
			WheelStates.Gas = WGas;
		}

		if (WheelStates.Brake != WBrakes)
		{
			MessageHandler->OnControllerAnalog(ThrustmasterAxisNames::Brake, THRUSTMASTER_IDX, Controller::intToNormalizedFloat(WBrakes));
			WheelStates.Brake = WBrakes;
		}

		if (WheelStates.Clutch != WClutch)
		{
			MessageHandler->OnControllerAnalog(ThrustmasterAxisNames::Clutch, THRUSTMASTER_IDX, Controller::intToNormalizedFloat(WClutch));
			WheelStates.Clutch = WClutch;
		}

		/******* Buttons *******/

		// For each button check against the previous state and send the correct message if any
		for (int32 ButtonIndex = 0; ButtonIndex < RacingWheelButtons::RacingWheelButtonsCount; ++ButtonIndex)
		{
			bool CurrentStates = WheelLib::getButtonStates(ButtonIndex);

			if (CurrentStates != WheelStates.ButtonStates[ButtonIndex])
			{
				if (CurrentStates)
				{
					MessageHandler->OnControllerButtonPressed(Buttons[ButtonIndex], THRUSTMASTER_IDX, false);
				}
				else
				{
					MessageHandler->OnControllerButtonReleased(Buttons[ButtonIndex], THRUSTMASTER_IDX, false);
				}

				if (CurrentStates != 0)
				{
					// this button was pressed - set the button's NextRepeatTime to the InitialButtonRepeatDelay
					WheelStates.NextRepeatTime[ButtonIndex] = CurrentTime + InitialButtonRepeatDelay;
				}
			}

			// Update the state for next time
			WheelStates.ButtonStates[ButtonIndex] = CurrentStates;
		}

		/******* Shifter *******/
		int AuxGear = WheelLib::getActualGear();

		if (AuxGear != ActualGear)
		{
			MessageHandler->OnControllerButtonReleased(ShButtons[ActualGear], THRUSTMASTER_IDX, false);
			MessageHandler->OnControllerButtonPressed(ShButtons[AuxGear], THRUSTMASTER_IDX, false);
			//Save Actual State
			ActualGear = AuxGear;
		}
	}
}

void FRacingWheel::SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value)
{
	if (WheelLib::isWheelConnected())
	{
		if (Value > 0.9f)
		{
			WheelLib::RunEffect(FidxL, 1);
			if (FidxL != -1)
				FidxL = WheelLib::UpdateConstantEffect(FidxL, Value * 65000, 30);
		}
	}
}

void FRacingWheel::SetChannelValues(int32 ControllerId, const FForceFeedbackValues &Values)
{
	int x = 20;

	if (WheelLib::isWheelConnected())
	{
		if (Values.LeftLarge > 0.0f)
		{
			
			if (FidxL != -1)
				FidxL = WheelLib::UpdateConstantEffect(FidxL, Values.LeftLarge * 32767, 30);

			WheelLib::RunEffect(FidxL, 1);
		}
		
		if (Values.RightLarge > 0.0f)
		{
			if (FidxR != -1)
				FidxR = WheelLib::UpdateConstantEffect(FidxR, Values.RightLarge * -32767, 30);

			WheelLib::RunEffect(FidxR, 1);
		}
	}

	/*if (Values.LeftLarge != 0.0f)
	{
		WheelLib::PlayRumbleEffect(32767 * Values.LeftLarge, 1);
	}*/
}

void FRacingWheel::UpdateVibration(int32 ControllerId)
{
		
}

void FRacingWheel::SetMessageHandler(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler)
{
	MessageHandler = InMessageHandler;
}

bool FRacingWheel::Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar)
{
	return false;
}


#undef LOCTEXT_NAMESPACE
