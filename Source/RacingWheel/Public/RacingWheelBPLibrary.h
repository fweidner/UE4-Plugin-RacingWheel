#pragma once
#include "Engine.h"
#include "WheelInterface.h"
#include "RacingWheelBPLibrary.generated.h"

/*
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu.
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class URacinWheelBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	/***** Management Functions *****/

	UFUNCTION(BlueprintPure, Category = "Input|Thrustmaster Plugin", meta = (DisplayName = "Wheel isConnected", Keywords = "Wheel management"))
		static bool Wheel_isConnected();

	UFUNCTION(BlueprintPure, Category = "Input|Thrustmaster Plugin", meta = (DisplayName = "Wheel isGamepad", Keywords = "Wheel management"))
		static bool Wheel_isGamepad();

	/***** feedback and Force Feedback Functions *****/
	UFUNCTION(BlueprintCallable, Category = "Input|Thrustmaster Plugin", meta = (DisplayName = "CreateRumbleEffect", Keywords = "Wheel feedback"))
		static bool Wheel_CreateRumbleEffect();

	UFUNCTION(BlueprintCallable, Category = "Input|Thrustmaster Plugin", meta = (DisplayName = "PlayRumbleEffect", Keywords = "Wheel feedback"))
		static void Wheel_PlayRumbleEffect(float Strength = 1.0, int32 Length = 2000);

	// Only Wheel

	UFUNCTION(BlueprintCallable, Category = "Input|Thrustmaster Plugin", meta = (DisplayName = "Wheel Create CostantEffect", Keywords = "Wheel Forcefeedback"))
		static int32 Wheel_CreateEffect(int32 Strength = 15000, int32 Length = 2000);

	UFUNCTION(BlueprintCallable, Category = "Input|Thrustmaster Plugin", meta = (DisplayName = "Wheel Create LeftRightEffect", Keywords = "Wheel Forcefeedback"))
		static int32 Wheel_CreateLeftRightEffect(int32 Left = 15000, int32 Right = 800, int32 Length = 2000);

	UFUNCTION(BlueprintCallable, Category = "Input|Thrustmaster Plugin", meta = (DisplayName = "Wheel UpdateEffect", Keywords = "Wheel Forcefeedback"))
		static int32 Wheel_UpdateEffect(int32 Index = 0, int32 Strength = 15000, int32 Length = 2000);

	UFUNCTION(BlueprintCallable, Category = "Input|Thrustmaster Plugin", meta = (DisplayName = "Wheel PlayEffect", Keywords = "Wheel Forcefeedback"))
		static bool Wheel_RunEffect(int32 Index = 0, int32 Iterations = 1);

	UFUNCTION(BlueprintCallable, Category = "Input|Thrustmaster Plugin", meta = (DisplayName = "Wheel DeleteEffect", Keywords = "Wheel Forcefeedback"))
		static bool Wheel_DeleteEffect(int32 Index = 0);

};
