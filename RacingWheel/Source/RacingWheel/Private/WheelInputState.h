#pragma once

#include "InputCoreTypes.h"
#include "NameTypes.h"

enum class EWheelAxes
{
	Steering = 0,
	Gas,
	Brakes,
	Clutch,
	TotalAxisCount
};

struct FWheelKey
{
	/*static const FKey Steering;
	static const FKey Gas;
	static const FKey Brakes;
	static const FKey Clutch;

	static const FKey GearUp;
	static const FKey GearDown;
	static const FKey LeftYellow;
	static const FKey RightYellow;

	static const FKey DPadUp;
	static const FKey DPadDown;
	static const FKey DPadRight;
	static const FKey DPadLeft;*/
};

struct FWheelKeyNames
{
	/*typedef FName Type;

	static const FName Steering;
	static const FName Gas;
	static const FName Brakes;
	static const FName Clutch;

	static const FName GearUp;
	static const FName GearDown;
	static const FName LeftYellow;
	static const FName RightYellow;

	static const FName DPadUp;
	static const FName DPadDown;
	static const FName DPadRight;
	static const FName DPadLeft;*/
};

/**
* Capacitive Axis State
*/
struct FWheelSensorState
{
	/** The axis that this sensor state maps to */
	FName Axis;

	/** The zero value (no additional weight) */
	unsigned short int Zero;

	/** What is the current sensor reading, from 0.f to 1.f */
	float Scale;

	/** What is the current sensor reading, from 0.f to 1.f */
	unsigned short int State;

	FWheelSensorState()
		: Axis(NAME_None)
		, Zero(900)
		, Scale(100.f)
		, State(0)
	{
	}

	float GetValue() {
		if (State < Zero) {
			return 0.f;
		}

		return (float)(State - Zero) * Scale;
	}
};

/**
* Input state for an pseudo controller
*/
struct FWheelState
{
	/** Weight axes */
	FWheelSensorState WeightAxes[(int32)EWheelAxes::TotalAxisCount];

	/** Default constructor */
	FWheelState()
	{
		//WeightAxes[(int32)EWheelAxes::Steering].Axis = FWheelKeyNames::WheelKey1;
	}
};