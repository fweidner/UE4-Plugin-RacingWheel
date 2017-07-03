// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef RACINGWHEEL_RacingWheelBPLibrary_generated_h
#error "RacingWheelBPLibrary.generated.h already included, missing '#pragma once' in RacingWheelBPLibrary.h"
#endif
#define RACINGWHEEL_RacingWheelBPLibrary_generated_h

#define Car2Simulate_Plugins_RacingWheel_Source_RacingWheel_Public_RacingWheelBPLibrary_h_26_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execWheel_DeleteEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URacinWheelBPLibrary::Wheel_DeleteEffect(Z_Param_Index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWheel_RunEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Iterations); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URacinWheelBPLibrary::Wheel_RunEffect(Z_Param_Index,Z_Param_Iterations); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWheel_UpdateEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Strength); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=URacinWheelBPLibrary::Wheel_UpdateEffect(Z_Param_Index,Z_Param_Strength,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWheel_CreateLeftRightEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Left); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Right); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=URacinWheelBPLibrary::Wheel_CreateLeftRightEffect(Z_Param_Left,Z_Param_Right,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWheel_CreateEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Strength); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=URacinWheelBPLibrary::Wheel_CreateEffect(Z_Param_Strength,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWheel_PlayRumbleEffect) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Strength); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URacinWheelBPLibrary::Wheel_PlayRumbleEffect(Z_Param_Strength,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWheel_CreateRumbleEffect) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URacinWheelBPLibrary::Wheel_CreateRumbleEffect(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWheel_isGamepad) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URacinWheelBPLibrary::Wheel_isGamepad(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWheel_isConnected) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URacinWheelBPLibrary::Wheel_isConnected(); \
		P_NATIVE_END; \
	}


#define Car2Simulate_Plugins_RacingWheel_Source_RacingWheel_Public_RacingWheelBPLibrary_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execWheel_DeleteEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URacinWheelBPLibrary::Wheel_DeleteEffect(Z_Param_Index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWheel_RunEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Iterations); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URacinWheelBPLibrary::Wheel_RunEffect(Z_Param_Index,Z_Param_Iterations); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWheel_UpdateEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Strength); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=URacinWheelBPLibrary::Wheel_UpdateEffect(Z_Param_Index,Z_Param_Strength,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWheel_CreateLeftRightEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Left); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Right); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=URacinWheelBPLibrary::Wheel_CreateLeftRightEffect(Z_Param_Left,Z_Param_Right,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWheel_CreateEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Strength); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=URacinWheelBPLibrary::Wheel_CreateEffect(Z_Param_Strength,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWheel_PlayRumbleEffect) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Strength); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Length); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URacinWheelBPLibrary::Wheel_PlayRumbleEffect(Z_Param_Strength,Z_Param_Length); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWheel_CreateRumbleEffect) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URacinWheelBPLibrary::Wheel_CreateRumbleEffect(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWheel_isGamepad) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URacinWheelBPLibrary::Wheel_isGamepad(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWheel_isConnected) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URacinWheelBPLibrary::Wheel_isConnected(); \
		P_NATIVE_END; \
	}


#define Car2Simulate_Plugins_RacingWheel_Source_RacingWheel_Public_RacingWheelBPLibrary_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURacinWheelBPLibrary(); \
	friend RACINGWHEEL_API class UClass* Z_Construct_UClass_URacinWheelBPLibrary(); \
public: \
	DECLARE_CLASS(URacinWheelBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RacingWheel"), NO_API) \
	DECLARE_SERIALIZER(URacinWheelBPLibrary) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Car2Simulate_Plugins_RacingWheel_Source_RacingWheel_Public_RacingWheelBPLibrary_h_26_INCLASS \
private: \
	static void StaticRegisterNativesURacinWheelBPLibrary(); \
	friend RACINGWHEEL_API class UClass* Z_Construct_UClass_URacinWheelBPLibrary(); \
public: \
	DECLARE_CLASS(URacinWheelBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RacingWheel"), NO_API) \
	DECLARE_SERIALIZER(URacinWheelBPLibrary) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Car2Simulate_Plugins_RacingWheel_Source_RacingWheel_Public_RacingWheelBPLibrary_h_26_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URacinWheelBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URacinWheelBPLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URacinWheelBPLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URacinWheelBPLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URacinWheelBPLibrary(URacinWheelBPLibrary&&); \
	NO_API URacinWheelBPLibrary(const URacinWheelBPLibrary&); \
public:


#define Car2Simulate_Plugins_RacingWheel_Source_RacingWheel_Public_RacingWheelBPLibrary_h_26_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URacinWheelBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URacinWheelBPLibrary(URacinWheelBPLibrary&&); \
	NO_API URacinWheelBPLibrary(const URacinWheelBPLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URacinWheelBPLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URacinWheelBPLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URacinWheelBPLibrary)


#define Car2Simulate_Plugins_RacingWheel_Source_RacingWheel_Public_RacingWheelBPLibrary_h_26_PRIVATE_PROPERTY_OFFSET
#define Car2Simulate_Plugins_RacingWheel_Source_RacingWheel_Public_RacingWheelBPLibrary_h_23_PROLOG
#define Car2Simulate_Plugins_RacingWheel_Source_RacingWheel_Public_RacingWheelBPLibrary_h_26_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Car2Simulate_Plugins_RacingWheel_Source_RacingWheel_Public_RacingWheelBPLibrary_h_26_PRIVATE_PROPERTY_OFFSET \
	Car2Simulate_Plugins_RacingWheel_Source_RacingWheel_Public_RacingWheelBPLibrary_h_26_RPC_WRAPPERS \
	Car2Simulate_Plugins_RacingWheel_Source_RacingWheel_Public_RacingWheelBPLibrary_h_26_INCLASS \
	Car2Simulate_Plugins_RacingWheel_Source_RacingWheel_Public_RacingWheelBPLibrary_h_26_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Car2Simulate_Plugins_RacingWheel_Source_RacingWheel_Public_RacingWheelBPLibrary_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Car2Simulate_Plugins_RacingWheel_Source_RacingWheel_Public_RacingWheelBPLibrary_h_26_PRIVATE_PROPERTY_OFFSET \
	Car2Simulate_Plugins_RacingWheel_Source_RacingWheel_Public_RacingWheelBPLibrary_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	Car2Simulate_Plugins_RacingWheel_Source_RacingWheel_Public_RacingWheelBPLibrary_h_26_INCLASS_NO_PURE_DECLS \
	Car2Simulate_Plugins_RacingWheel_Source_RacingWheel_Public_RacingWheelBPLibrary_h_26_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class RacinWheelBPLibrary."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Car2Simulate_Plugins_RacingWheel_Source_RacingWheel_Public_RacingWheelBPLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
