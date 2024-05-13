// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "YoruPlayer/Yoru.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LIESOFM_Yoru_generated_h
#error "Yoru.generated.h already included, missing '#pragma once' in Yoru.h"
#endif
#define LIESOFM_Yoru_generated_h

#define FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_34_SPARSE_DATA
#define FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_34_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_34_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_34_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetPlayerState); \
	DECLARE_FUNCTION(execSetisPressedMovementInput); \
	DECLARE_FUNCTION(execGetisPressedMovementInput);


#define FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_34_ACCESSORS
#define FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_34_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAYoru(); \
	friend struct Z_Construct_UClass_AYoru_Statics; \
public: \
	DECLARE_CLASS(AYoru, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LiesOfM"), NO_API) \
	DECLARE_SERIALIZER(AYoru)


#define FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_34_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AYoru(AYoru&&); \
	NO_API AYoru(const AYoru&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AYoru); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AYoru); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AYoru) \
	NO_API virtual ~AYoru();


#define FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_31_PROLOG
#define FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_34_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_34_SPARSE_DATA \
	FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_34_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_34_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_34_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_34_ACCESSORS \
	FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_34_INCLASS_NO_PURE_DECLS \
	FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_34_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LIESOFM_API UClass* StaticClass<class AYoru>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h


#define FOREACH_ENUM_EPLAYERSTATE(op) \
	op(EPlayerState::NONE) \
	op(EPlayerState::Running) \
	op(EPlayerState::Rolling) \
	op(EPlayerState::StepBack) \
	op(EPlayerState::Crouch) \
	op(EPlayerState::SIZE) 

enum class EPlayerState : uint8;
template<> struct TIsUEnumClass<EPlayerState> { enum { Value = true }; };
template<> LIESOFM_API UEnum* StaticEnum<EPlayerState>();

#define FOREACH_ENUM_EUSEWEAPONSTATE(op) \
	op(EUseWeaponState::NONE) \
	op(EUseWeaponState::GREATSWORD) \
	op(EUseWeaponState::SIZE) 

enum class EUseWeaponState : uint8;
template<> struct TIsUEnumClass<EUseWeaponState> { enum { Value = true }; };
template<> LIESOFM_API UEnum* StaticEnum<EUseWeaponState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
