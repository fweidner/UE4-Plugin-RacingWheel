/************************************************************************************
* Copyright (c) 2015-2016, TU-Ilmenau
* VWDS - Projekt Vista4F
* ===================================================================================
* ===================================================================================
* Authors:  Luis Rojas (luis-alejandro.rojas-vargas@tu-ilmenau.de)
*************************************************************************************/

#include "RacingWheelPrivatePCH.h"

#include "SlateBasics.h"

#include "IInputDeviceModule.h"
#include "GenericPlatform/IInputInterface.h"
#include "IInputDevice.h"

#include "WheelInterface.h"
#include "Controller.h"


//
// Gamepad thresholds
//
#define LEFT_THUMBPAD_DEADZONE  0
#define RIGHT_THUMBPAD_DEADZONE 0

#ifndef _RACINGWHEELDEVICE_H_
#define _RACINGWHEELDEVICE_H_

//namespace ThrustmasterKeyNames
//{
//	inline float ShortToNormalizedFloat(short AxisVal)
//	{
//		// normalize [-32768..32767] -> [-1..1]
//		const float Norm = (AxisVal <= 0 ? 32768.f : 32767.f);
//		return float(AxisVal) / Norm;
//	}
//
//	inline float intToNormalizedFloat(int AxisVal)
//	{
//		// normalize [0..65535] -> [-1..1]
//		//const float Norm = (AxisVal <= 0 ? 32768.f : 32767.f);
//		return float(AxisVal) / 65535;
//	}
//}

namespace ThrustmasterKeyNames
{
	const FGamepadKeyNames::Type GearDown("RacingWheel_GearDown");
	const FGamepadKeyNames::Type GearUp("RacingWheel_GearUp");
	const FGamepadKeyNames::Type LeftGreen("RacingWheel_LeftGreen");
	const FGamepadKeyNames::Type LeftPurple("RacingWheel_LeftPurple");
	const FGamepadKeyNames::Type RightRed("RacingWheel_RightRed");
	const FGamepadKeyNames::Type LeftWhite("RacingWheel_LeftWhite");
	const FGamepadKeyNames::Type KnobLeft("RacingWheel_KnobLeft");
	const FGamepadKeyNames::Type KnobRight("RacingWheel_KnobRight");
	const FGamepadKeyNames::Type LeftYellow("RacingWheel_LeftYellow");
	const FGamepadKeyNames::Type RightYellow("RacingWheel_RightYellow");
	const FGamepadKeyNames::Type Xbox("RacingWheel_Xbox");
	const FGamepadKeyNames::Type SpecialYellow("Racing_SpecialYellow");
	const FGamepadKeyNames::Type KnobPush("Racing_KnobPush");
}

namespace ThrustmasterAxisNames
{
	const FGamepadKeyNames::Type Steering("RacingWheel_Stering");
	const FGamepadKeyNames::Type Gas("RacingWheel_Gas");
	const FGamepadKeyNames::Type Brake("RacingWheel_Brake");
	const FGamepadKeyNames::Type Clutch("RacingWheel_Clutch");
}

namespace ThrustmasterShifterKeyNames
{
	const FGamepadKeyNames::Type GearN("RacingWheel_Neutro");
	const FGamepadKeyNames::Type Gear1("RacingWheel_Gear1");
	const FGamepadKeyNames::Type Gear2("RacingWheel_Gear2");
	const FGamepadKeyNames::Type Gear3("RacingWheel_Gear3");
	const FGamepadKeyNames::Type Gear4("RacingWheel_Gear4");
	const FGamepadKeyNames::Type Gear5("RacingWheel_Gear5");
	const FGamepadKeyNames::Type Gear6("RacingWheel_Gear6");
	const FGamepadKeyNames::Type Gear7("RacingWheel_Gear7");
	const FGamepadKeyNames::Type GearR("RacingWheel_GearR");
}

class FRacingWheel : public IInputDevice
{

public:

	FRacingWheel(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler);
	virtual ~FRacingWheel();

	/** Tick the interface (e.g. check for new controllers) */
	virtual void Tick(float DeltaTime) override;

	/** Poll for controller state and send events if needed */
	virtual void SendControllerEvents() override;

	/** Set which MessageHandler will get the events from SendControllerEvents. */
	virtual void SetMessageHandler(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler) override;

	/** Exec handler to allow console commands to be passed through for debugging */
	virtual bool Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar) override;

	/** IForceFeedbackSystem pass through functions **/
	void SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value) override;
	void SetChannelValues(int32 ControllerId, const FForceFeedbackValues &Values) override;


	/** Private Function **/
	void UpdateVibration(int32 ControllerId);

private:

	struct FControllerState
	{
		//Old Values from the Axis

		/** Raw Axis 0 analog value */
		short Steering;

		/** Raw Axis 2 analog value */
		short Gas;

		/** Raw Axis 1 analog value */
		short Brake;

		/** Raw Axis 2 analog value */
		short Clutch;

		/** Last frame's button states, so we only send events on edges */
		bool ButtonStates[RacingWheelButtons::RacingWheelButtonsCount];

		/** Next time a repeat event should be generated for each button */
		double NextRepeatTime[RacingWheelButtons::RacingWheelButtonsCount];

		/** Values for force feedback on this controller.  We only consider the LEFT_LARGE channel for SteamControllers */
		FForceFeedbackValues VibeValues;
	};

	/** Feedback Effec Index **/
	int FidxL = -1;
	int FidxR = -1;

	/** Actual Gear **/
	int ActualGear = 8;

	/** Controller states */
	FControllerState WheelStates;

	/** Delay before sending a repeat message after a button was first pressed */
	float InitialButtonRepeatDelay;

	/** Delay before sending a repeat message after a button has been pressed for a while */
	float ButtonRepeatDelay;

	/** Mapping of controller buttons */
	FGamepadKeyNames::Type Buttons[RacingWheelButtons::RacingWheelButtonsCount];

	/** Mapping of Shifter buttons */
	FGamepadKeyNames::Type ShButtons[ShifterButtons::ShifterButtonsCount];

	/** handler to send all messages to */
	TSharedRef<FGenericApplicationMessageHandler> MessageHandler;
};

#endif // _RACINGWHEELDEVICE_H_

