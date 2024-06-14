// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "YoruPlayer/YoruMoveComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LIESOFM_YoruMoveComponent_generated_h
#error "YoruMoveComponent.generated.h already included, missing '#pragma once' in YoruMoveComponent.h"
#endif
#define LIESOFM_YoruMoveComponent_generated_h

#define FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_13_SPARSE_DATA
#define FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_13_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_13_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execStopRollMove); \
	DECLARE_FUNCTION(execCaculatePortion); \
	DECLARE_FUNCTION(execHiddenItem); \
	DECLARE_FUNCTION(execShowItem); \
	DECLARE_FUNCTION(execUnEquipRightWeapon); \
	DECLARE_FUNCTION(execEquipRightWeapon); \
	DECLARE_FUNCTION(execMovementInputHandler);


#define FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_13_ACCESSORS
#define FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUYoruMoveComponent(); \
	friend struct Z_Construct_UClass_UYoruMoveComponent_Statics; \
public: \
	DECLARE_CLASS(UYoruMoveComponent, UYoruBaseComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LiesOfM"), NO_API) \
	DECLARE_SERIALIZER(UYoruMoveComponent)


#define FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UYoruMoveComponent(UYoruMoveComponent&&); \
	NO_API UYoruMoveComponent(const UYoruMoveComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UYoruMoveComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UYoruMoveComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UYoruMoveComponent) \
	NO_API virtual ~UYoruMoveComponent();


#define FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_10_PROLOG
#define FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_13_SPARSE_DATA \
	FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_13_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_13_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_13_ACCESSORS \
	FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_13_INCLASS_NO_PURE_DECLS \
	FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LIESOFM_API UClass* StaticClass<class UYoruMoveComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
