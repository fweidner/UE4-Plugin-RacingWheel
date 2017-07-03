// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Private/RacingWheelPrivatePCH.h"
#include "RacingWheel.generated.dep.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCode1RacingWheel() {}
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();

	RACINGWHEEL_API class UFunction* Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_CreateEffect();
	RACINGWHEEL_API class UFunction* Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_CreateLeftRightEffect();
	RACINGWHEEL_API class UFunction* Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_CreateRumbleEffect();
	RACINGWHEEL_API class UFunction* Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_DeleteEffect();
	RACINGWHEEL_API class UFunction* Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_isConnected();
	RACINGWHEEL_API class UFunction* Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_isGamepad();
	RACINGWHEEL_API class UFunction* Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_PlayRumbleEffect();
	RACINGWHEEL_API class UFunction* Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_RunEffect();
	RACINGWHEEL_API class UFunction* Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_UpdateEffect();
	RACINGWHEEL_API class UClass* Z_Construct_UClass_URacinWheelBPLibrary_NoRegister();
	RACINGWHEEL_API class UClass* Z_Construct_UClass_URacinWheelBPLibrary();
	RACINGWHEEL_API class UPackage* Z_Construct_UPackage__Script_RacingWheel();
	void URacinWheelBPLibrary::StaticRegisterNativesURacinWheelBPLibrary()
	{
		UClass* Class = URacinWheelBPLibrary::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "Wheel_CreateEffect", (Native)&URacinWheelBPLibrary::execWheel_CreateEffect },
			{ "Wheel_CreateLeftRightEffect", (Native)&URacinWheelBPLibrary::execWheel_CreateLeftRightEffect },
			{ "Wheel_CreateRumbleEffect", (Native)&URacinWheelBPLibrary::execWheel_CreateRumbleEffect },
			{ "Wheel_DeleteEffect", (Native)&URacinWheelBPLibrary::execWheel_DeleteEffect },
			{ "Wheel_isConnected", (Native)&URacinWheelBPLibrary::execWheel_isConnected },
			{ "Wheel_isGamepad", (Native)&URacinWheelBPLibrary::execWheel_isGamepad },
			{ "Wheel_PlayRumbleEffect", (Native)&URacinWheelBPLibrary::execWheel_PlayRumbleEffect },
			{ "Wheel_RunEffect", (Native)&URacinWheelBPLibrary::execWheel_RunEffect },
			{ "Wheel_UpdateEffect", (Native)&URacinWheelBPLibrary::execWheel_UpdateEffect },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, 9);
	}
	UFunction* Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_CreateEffect()
	{
		struct RacinWheelBPLibrary_eventWheel_CreateEffect_Parms
		{
			int32 Strength;
			int32 Length;
			int32 ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URacinWheelBPLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("Wheel_CreateEffect"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04022401, 65535, sizeof(RacinWheelBPLibrary_eventWheel_CreateEffect_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(ReturnValue, RacinWheelBPLibrary_eventWheel_CreateEffect_Parms), 0x0010000000000580);
			UProperty* NewProp_Length = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Length"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(Length, RacinWheelBPLibrary_eventWheel_CreateEffect_Parms), 0x0010000000000080);
			UProperty* NewProp_Strength = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Strength"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(Strength, RacinWheelBPLibrary_eventWheel_CreateEffect_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Input|Thrustmaster Plugin"));
			MetaData->SetValue(ReturnFunction, TEXT("CPP_Default_Length"), TEXT("2000"));
			MetaData->SetValue(ReturnFunction, TEXT("CPP_Default_Strength"), TEXT("15000"));
			MetaData->SetValue(ReturnFunction, TEXT("DisplayName"), TEXT("Wheel Create CostantEffect"));
			MetaData->SetValue(ReturnFunction, TEXT("Keywords"), TEXT("Wheel Forcefeedback"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RacingWheelBPLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Only Wheel"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_CreateLeftRightEffect()
	{
		struct RacinWheelBPLibrary_eventWheel_CreateLeftRightEffect_Parms
		{
			int32 Left;
			int32 Right;
			int32 Length;
			int32 ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URacinWheelBPLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("Wheel_CreateLeftRightEffect"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04022401, 65535, sizeof(RacinWheelBPLibrary_eventWheel_CreateLeftRightEffect_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(ReturnValue, RacinWheelBPLibrary_eventWheel_CreateLeftRightEffect_Parms), 0x0010000000000580);
			UProperty* NewProp_Length = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Length"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(Length, RacinWheelBPLibrary_eventWheel_CreateLeftRightEffect_Parms), 0x0010000000000080);
			UProperty* NewProp_Right = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Right"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(Right, RacinWheelBPLibrary_eventWheel_CreateLeftRightEffect_Parms), 0x0010000000000080);
			UProperty* NewProp_Left = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Left"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(Left, RacinWheelBPLibrary_eventWheel_CreateLeftRightEffect_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Input|Thrustmaster Plugin"));
			MetaData->SetValue(ReturnFunction, TEXT("CPP_Default_Left"), TEXT("15000"));
			MetaData->SetValue(ReturnFunction, TEXT("CPP_Default_Length"), TEXT("2000"));
			MetaData->SetValue(ReturnFunction, TEXT("CPP_Default_Right"), TEXT("800"));
			MetaData->SetValue(ReturnFunction, TEXT("DisplayName"), TEXT("Wheel Create LeftRightEffect"));
			MetaData->SetValue(ReturnFunction, TEXT("Keywords"), TEXT("Wheel Forcefeedback"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RacingWheelBPLibrary.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_CreateRumbleEffect()
	{
		struct RacinWheelBPLibrary_eventWheel_CreateRumbleEffect_Parms
		{
			bool ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URacinWheelBPLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("Wheel_CreateRumbleEffect"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04022401, 65535, sizeof(RacinWheelBPLibrary_eventWheel_CreateRumbleEffect_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, RacinWheelBPLibrary_eventWheel_CreateRumbleEffect_Parms, bool);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, RacinWheelBPLibrary_eventWheel_CreateRumbleEffect_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, RacinWheelBPLibrary_eventWheel_CreateRumbleEffect_Parms), sizeof(bool), true);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Input|Thrustmaster Plugin"));
			MetaData->SetValue(ReturnFunction, TEXT("DisplayName"), TEXT("CreateRumbleEffect"));
			MetaData->SetValue(ReturnFunction, TEXT("Keywords"), TEXT("Wheel feedback"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RacingWheelBPLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("** feedback and Force Feedback Functions ****"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_DeleteEffect()
	{
		struct RacinWheelBPLibrary_eventWheel_DeleteEffect_Parms
		{
			int32 Index;
			bool ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URacinWheelBPLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("Wheel_DeleteEffect"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04022401, 65535, sizeof(RacinWheelBPLibrary_eventWheel_DeleteEffect_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, RacinWheelBPLibrary_eventWheel_DeleteEffect_Parms, bool);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, RacinWheelBPLibrary_eventWheel_DeleteEffect_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, RacinWheelBPLibrary_eventWheel_DeleteEffect_Parms), sizeof(bool), true);
			UProperty* NewProp_Index = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Index"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(Index, RacinWheelBPLibrary_eventWheel_DeleteEffect_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Input|Thrustmaster Plugin"));
			MetaData->SetValue(ReturnFunction, TEXT("CPP_Default_Index"), TEXT("0"));
			MetaData->SetValue(ReturnFunction, TEXT("DisplayName"), TEXT("Wheel DeleteEffect"));
			MetaData->SetValue(ReturnFunction, TEXT("Keywords"), TEXT("Wheel Forcefeedback"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RacingWheelBPLibrary.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_isConnected()
	{
		struct RacinWheelBPLibrary_eventWheel_isConnected_Parms
		{
			bool ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URacinWheelBPLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("Wheel_isConnected"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x14022401, 65535, sizeof(RacinWheelBPLibrary_eventWheel_isConnected_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, RacinWheelBPLibrary_eventWheel_isConnected_Parms, bool);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, RacinWheelBPLibrary_eventWheel_isConnected_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, RacinWheelBPLibrary_eventWheel_isConnected_Parms), sizeof(bool), true);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Input|Thrustmaster Plugin"));
			MetaData->SetValue(ReturnFunction, TEXT("DisplayName"), TEXT("Wheel isConnected"));
			MetaData->SetValue(ReturnFunction, TEXT("Keywords"), TEXT("Wheel management"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RacingWheelBPLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("** Management Functions ****"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_isGamepad()
	{
		struct RacinWheelBPLibrary_eventWheel_isGamepad_Parms
		{
			bool ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URacinWheelBPLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("Wheel_isGamepad"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x14022401, 65535, sizeof(RacinWheelBPLibrary_eventWheel_isGamepad_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, RacinWheelBPLibrary_eventWheel_isGamepad_Parms, bool);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, RacinWheelBPLibrary_eventWheel_isGamepad_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, RacinWheelBPLibrary_eventWheel_isGamepad_Parms), sizeof(bool), true);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Input|Thrustmaster Plugin"));
			MetaData->SetValue(ReturnFunction, TEXT("DisplayName"), TEXT("Wheel isGamepad"));
			MetaData->SetValue(ReturnFunction, TEXT("Keywords"), TEXT("Wheel management"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RacingWheelBPLibrary.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_PlayRumbleEffect()
	{
		struct RacinWheelBPLibrary_eventWheel_PlayRumbleEffect_Parms
		{
			float Strength;
			int32 Length;
		};
		UObject* Outer=Z_Construct_UClass_URacinWheelBPLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("Wheel_PlayRumbleEffect"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04022401, 65535, sizeof(RacinWheelBPLibrary_eventWheel_PlayRumbleEffect_Parms));
			UProperty* NewProp_Length = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Length"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(Length, RacinWheelBPLibrary_eventWheel_PlayRumbleEffect_Parms), 0x0010000000000080);
			UProperty* NewProp_Strength = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Strength"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(Strength, RacinWheelBPLibrary_eventWheel_PlayRumbleEffect_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Input|Thrustmaster Plugin"));
			MetaData->SetValue(ReturnFunction, TEXT("CPP_Default_Length"), TEXT("2000"));
			MetaData->SetValue(ReturnFunction, TEXT("CPP_Default_Strength"), TEXT("1.000000"));
			MetaData->SetValue(ReturnFunction, TEXT("DisplayName"), TEXT("PlayRumbleEffect"));
			MetaData->SetValue(ReturnFunction, TEXT("Keywords"), TEXT("Wheel feedback"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RacingWheelBPLibrary.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_RunEffect()
	{
		struct RacinWheelBPLibrary_eventWheel_RunEffect_Parms
		{
			int32 Index;
			int32 Iterations;
			bool ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URacinWheelBPLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("Wheel_RunEffect"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04022401, 65535, sizeof(RacinWheelBPLibrary_eventWheel_RunEffect_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, RacinWheelBPLibrary_eventWheel_RunEffect_Parms, bool);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, RacinWheelBPLibrary_eventWheel_RunEffect_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, RacinWheelBPLibrary_eventWheel_RunEffect_Parms), sizeof(bool), true);
			UProperty* NewProp_Iterations = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Iterations"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(Iterations, RacinWheelBPLibrary_eventWheel_RunEffect_Parms), 0x0010000000000080);
			UProperty* NewProp_Index = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Index"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(Index, RacinWheelBPLibrary_eventWheel_RunEffect_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Input|Thrustmaster Plugin"));
			MetaData->SetValue(ReturnFunction, TEXT("CPP_Default_Index"), TEXT("0"));
			MetaData->SetValue(ReturnFunction, TEXT("CPP_Default_Iterations"), TEXT("1"));
			MetaData->SetValue(ReturnFunction, TEXT("DisplayName"), TEXT("Wheel PlayEffect"));
			MetaData->SetValue(ReturnFunction, TEXT("Keywords"), TEXT("Wheel Forcefeedback"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RacingWheelBPLibrary.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_UpdateEffect()
	{
		struct RacinWheelBPLibrary_eventWheel_UpdateEffect_Parms
		{
			int32 Index;
			int32 Strength;
			int32 Length;
			int32 ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URacinWheelBPLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("Wheel_UpdateEffect"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04022401, 65535, sizeof(RacinWheelBPLibrary_eventWheel_UpdateEffect_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(ReturnValue, RacinWheelBPLibrary_eventWheel_UpdateEffect_Parms), 0x0010000000000580);
			UProperty* NewProp_Length = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Length"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(Length, RacinWheelBPLibrary_eventWheel_UpdateEffect_Parms), 0x0010000000000080);
			UProperty* NewProp_Strength = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Strength"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(Strength, RacinWheelBPLibrary_eventWheel_UpdateEffect_Parms), 0x0010000000000080);
			UProperty* NewProp_Index = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Index"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(Index, RacinWheelBPLibrary_eventWheel_UpdateEffect_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Input|Thrustmaster Plugin"));
			MetaData->SetValue(ReturnFunction, TEXT("CPP_Default_Index"), TEXT("0"));
			MetaData->SetValue(ReturnFunction, TEXT("CPP_Default_Length"), TEXT("2000"));
			MetaData->SetValue(ReturnFunction, TEXT("CPP_Default_Strength"), TEXT("15000"));
			MetaData->SetValue(ReturnFunction, TEXT("DisplayName"), TEXT("Wheel UpdateEffect"));
			MetaData->SetValue(ReturnFunction, TEXT("Keywords"), TEXT("Wheel Forcefeedback"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RacingWheelBPLibrary.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_URacinWheelBPLibrary_NoRegister()
	{
		return URacinWheelBPLibrary::StaticClass();
	}
	UClass* Z_Construct_UClass_URacinWheelBPLibrary()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UBlueprintFunctionLibrary();
			Z_Construct_UPackage__Script_RacingWheel();
			OuterClass = URacinWheelBPLibrary::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20000080;

				OuterClass->LinkChild(Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_CreateEffect());
				OuterClass->LinkChild(Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_CreateLeftRightEffect());
				OuterClass->LinkChild(Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_CreateRumbleEffect());
				OuterClass->LinkChild(Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_DeleteEffect());
				OuterClass->LinkChild(Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_isConnected());
				OuterClass->LinkChild(Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_isGamepad());
				OuterClass->LinkChild(Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_PlayRumbleEffect());
				OuterClass->LinkChild(Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_RunEffect());
				OuterClass->LinkChild(Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_UpdateEffect());

				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_CreateEffect(), "Wheel_CreateEffect"); // 116610112
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_CreateLeftRightEffect(), "Wheel_CreateLeftRightEffect"); // 3338873918
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_CreateRumbleEffect(), "Wheel_CreateRumbleEffect"); // 3451711732
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_DeleteEffect(), "Wheel_DeleteEffect"); // 2821151822
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_isConnected(), "Wheel_isConnected"); // 2571332658
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_isGamepad(), "Wheel_isGamepad"); // 459696725
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_PlayRumbleEffect(), "Wheel_PlayRumbleEffect"); // 3826783036
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_RunEffect(), "Wheel_RunEffect"); // 2380514726
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URacinWheelBPLibrary_Wheel_UpdateEffect(), "Wheel_UpdateEffect"); // 4103396002
				static TCppClassTypeInfo<TCppClassTypeTraits<URacinWheelBPLibrary> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("RacingWheelBPLibrary.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/RacingWheelBPLibrary.h"));
				MetaData->SetValue(OuterClass, TEXT("ToolTip"), TEXT("*      Function library class.\n*      Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.\n*\n*      When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.\n*      BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.\n*      BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.\n*      DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.\n*                              Its lets you name the node using characters not allowed in C++ function names.\n*      CompactNodeTitle - the word(s) that appear on the node.\n*      Keywords -      the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu.\n*                              Good example is \"Print String\" node which you can find also by using keyword \"log\".\n*      Category -      the category your node will be under in the Blueprint drop-down menu.\n*\n*      For more info on custom blueprint nodes visit documentation:\n*      https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(URacinWheelBPLibrary, 2446524566);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URacinWheelBPLibrary(Z_Construct_UClass_URacinWheelBPLibrary, &URacinWheelBPLibrary::StaticClass, TEXT("/Script/RacingWheel"), TEXT("URacinWheelBPLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URacinWheelBPLibrary);
	UPackage* Z_Construct_UPackage__Script_RacingWheel()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), nullptr, FName(TEXT("/Script/RacingWheel")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000000);
			FGuid Guid;
			Guid.A = 0x08F11A30;
			Guid.B = 0x4CA268DD;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
