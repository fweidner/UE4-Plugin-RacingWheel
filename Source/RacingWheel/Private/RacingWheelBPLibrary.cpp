#include "RacingWheelBPLibrary.h"

#include "RacingWheelPrivatePCH.h"

using namespace ThrustmasterWheel;

typedef int(*_SDL_Init)(int Flags);

URacinWheelBPLibrary::URacinWheelBPLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

// My Functions from BluePrint

/***** Management Functions *****/

bool URacinWheelBPLibrary::Wheel_isConnected()
{
	return WheelLib::isWheelConnected();
}

bool URacinWheelBPLibrary::Wheel_isGamepad()
{
	return WheelLib::isGamepad();
}

/***** feedback and Force Feedback Functions *****/
bool URacinWheelBPLibrary::Wheel_CreateRumbleEffect()
{
	return WheelLib::CreateRumbleEffect();
}

void URacinWheelBPLibrary::Wheel_PlayRumbleEffect(float Strength, int32 Length)
{
	WheelLib::PlayRumbleEffect(Strength, Length);
}

// Only Wheel

int32 URacinWheelBPLibrary::Wheel_CreateEffect(int32 Strength, int32 Length)
{
	return (int32)WheelLib::CreateConstantEffect(Strength, Length);
}

int32 URacinWheelBPLibrary::Wheel_CreateLeftRightEffect(int32 Left, int32 Right, int32 Length)
{
	return (int32)WheelLib::CreateLeftRightEffect(Left, Right, Length);
}

int32 URacinWheelBPLibrary::Wheel_UpdateEffect(int32 Index, int32 Strength, int32 Length)
{
	return (int32)WheelLib::UpdateConstantEffect(Index, Strength, Length);
}

bool URacinWheelBPLibrary::Wheel_RunEffect(int32 Index, int32 Iterations)
{
	return WheelLib::RunEffect(Index, Iterations);
}

bool URacinWheelBPLibrary::Wheel_DeleteEffect(int32 Index)
{
	return WheelLib::DeleteEffect(Index);
}
