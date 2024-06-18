// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LiesOfM/Public/YoruPlayer/Yoru.h"
#include "../../Source/Runtime/Engine/Classes/Engine/HitResult.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYoru() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	LIESOFM_API UClass* Z_Construct_UClass_AItemBase_NoRegister();
	LIESOFM_API UClass* Z_Construct_UClass_AWeaponBase_NoRegister();
	LIESOFM_API UClass* Z_Construct_UClass_AYoru();
	LIESOFM_API UClass* Z_Construct_UClass_AYoru_NoRegister();
	LIESOFM_API UClass* Z_Construct_UClass_UDamageInteractions_NoRegister();
	LIESOFM_API UClass* Z_Construct_UClass_UTOMGameInstance_NoRegister();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruAttackComponent_NoRegister();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruDefenceComponent_NoRegister();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruLockonComponent_NoRegister();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruMoveComponent_NoRegister();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruStatComponent_NoRegister();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruWidgetComponent_NoRegister();
	LIESOFM_API UEnum* Z_Construct_UEnum_LiesOfM_EPlayerState();
	LIESOFM_API UEnum* Z_Construct_UEnum_LiesOfM_EUseWeaponState();
	UMG_API UClass* Z_Construct_UClass_UWidgetComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_LiesOfM();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPlayerState;
	static UEnum* EPlayerState_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPlayerState.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPlayerState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_LiesOfM_EPlayerState, (UObject*)Z_Construct_UPackage__Script_LiesOfM(), TEXT("EPlayerState"));
		}
		return Z_Registration_Info_UEnum_EPlayerState.OuterSingleton;
	}
	template<> LIESOFM_API UEnum* StaticEnum<EPlayerState>()
	{
		return EPlayerState_StaticEnum();
	}
	struct Z_Construct_UEnum_LiesOfM_EPlayerState_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_LiesOfM_EPlayerState_Statics::Enumerators[] = {
		{ "EPlayerState::NONE", (int64)EPlayerState::NONE },
		{ "EPlayerState::Running", (int64)EPlayerState::Running },
		{ "EPlayerState::Rolling", (int64)EPlayerState::Rolling },
		{ "EPlayerState::StepBack", (int64)EPlayerState::StepBack },
		{ "EPlayerState::Crouch", (int64)EPlayerState::Crouch },
		{ "EPlayerState::LightAttack", (int64)EPlayerState::LightAttack },
		{ "EPlayerState::HeavyAttack", (int64)EPlayerState::HeavyAttack },
		{ "EPlayerState::RunningAttack", (int64)EPlayerState::RunningAttack },
		{ "EPlayerState::RollingAttack", (int64)EPlayerState::RollingAttack },
		{ "EPlayerState::BackStab", (int64)EPlayerState::BackStab },
		{ "EPlayerState::Riposte", (int64)EPlayerState::Riposte },
		{ "EPlayerState::Blocking", (int64)EPlayerState::Blocking },
		{ "EPlayerState::SIZE", (int64)EPlayerState::SIZE },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_LiesOfM_EPlayerState_Statics::Enum_MetaDataParams[] = {
		{ "BackStab.DisplayName", "BackStab" },
		{ "BackStab.Name", "EPlayerState::BackStab" },
		{ "Blocking.DisplayName", "Blocking" },
		{ "Blocking.Name", "EPlayerState::Blocking" },
		{ "BlueprintType", "true" },
		{ "Crouch.DisplayName", "Crouch" },
		{ "Crouch.Name", "EPlayerState::Crouch" },
		{ "HeavyAttack.DisplayName", "HeavyAttack" },
		{ "HeavyAttack.Name", "EPlayerState::HeavyAttack" },
		{ "LightAttack.DisplayName", "LightAttack" },
		{ "LightAttack.Name", "EPlayerState::LightAttack" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
		{ "NONE.DisplayName", "NONE" },
		{ "NONE.Name", "EPlayerState::NONE" },
		{ "Riposte.DisplayName", "Riposte" },
		{ "Riposte.Name", "EPlayerState::Riposte" },
		{ "Rolling.DisplayName", "Rolling" },
		{ "Rolling.Name", "EPlayerState::Rolling" },
		{ "RollingAttack.DisplayName", "RollingAttack" },
		{ "RollingAttack.Name", "EPlayerState::RollingAttack" },
		{ "Running.DisplayName", "Running" },
		{ "Running.Name", "EPlayerState::Running" },
		{ "RunningAttack.DisplayName", "RunningAttack" },
		{ "RunningAttack.Name", "EPlayerState::RunningAttack" },
		{ "ScriptName", "EPlayerStateEnum" },
		{ "SIZE.Name", "EPlayerState::SIZE" },
		{ "StepBack.DisplayName", "StepBack" },
		{ "StepBack.Name", "EPlayerState::StepBack" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_LiesOfM_EPlayerState_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_LiesOfM,
		nullptr,
		"EPlayerState",
		"EPlayerState",
		Z_Construct_UEnum_LiesOfM_EPlayerState_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_LiesOfM_EPlayerState_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_LiesOfM_EPlayerState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_LiesOfM_EPlayerState_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_LiesOfM_EPlayerState()
	{
		if (!Z_Registration_Info_UEnum_EPlayerState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPlayerState.InnerSingleton, Z_Construct_UEnum_LiesOfM_EPlayerState_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPlayerState.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EUseWeaponState;
	static UEnum* EUseWeaponState_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EUseWeaponState.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EUseWeaponState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_LiesOfM_EUseWeaponState, (UObject*)Z_Construct_UPackage__Script_LiesOfM(), TEXT("EUseWeaponState"));
		}
		return Z_Registration_Info_UEnum_EUseWeaponState.OuterSingleton;
	}
	template<> LIESOFM_API UEnum* StaticEnum<EUseWeaponState>()
	{
		return EUseWeaponState_StaticEnum();
	}
	struct Z_Construct_UEnum_LiesOfM_EUseWeaponState_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_LiesOfM_EUseWeaponState_Statics::Enumerators[] = {
		{ "EUseWeaponState::NONE", (int64)EUseWeaponState::NONE },
		{ "EUseWeaponState::GREATSWORD", (int64)EUseWeaponState::GREATSWORD },
		{ "EUseWeaponState::SIZE", (int64)EUseWeaponState::SIZE },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_LiesOfM_EUseWeaponState_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "GREATSWORD.DisplayName", "GREATSWORD" },
		{ "GREATSWORD.Name", "EUseWeaponState::GREATSWORD" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
		{ "NONE.DisplayName", "NONE" },
		{ "NONE.Name", "EUseWeaponState::NONE" },
		{ "SIZE.Name", "EUseWeaponState::SIZE" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_LiesOfM_EUseWeaponState_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_LiesOfM,
		nullptr,
		"EUseWeaponState",
		"EUseWeaponState",
		Z_Construct_UEnum_LiesOfM_EUseWeaponState_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_LiesOfM_EUseWeaponState_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_LiesOfM_EUseWeaponState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_LiesOfM_EUseWeaponState_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_LiesOfM_EUseWeaponState()
	{
		if (!Z_Registration_Info_UEnum_EUseWeaponState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EUseWeaponState.InnerSingleton, Z_Construct_UEnum_LiesOfM_EUseWeaponState_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EUseWeaponState.InnerSingleton;
	}
	DEFINE_FUNCTION(AYoru::execFallingDie)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->FallingDie();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AYoru::execChangeCamera)
	{
		P_GET_UBOOL(Z_Param_isLockonMove);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ChangeCamera(Z_Param_isLockonMove);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AYoru::execSetIsLockon)
	{
		P_GET_UBOOL(Z_Param_lockon);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetIsLockon(Z_Param_lockon);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AYoru::execGetIsLockon)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetIsLockon();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AYoru::execReceiveDamage)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_damageAmount);
		P_GET_OBJECT(AActor,Z_Param_attackingActor);
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_hitResult);
		P_GET_UBOOL(Z_Param_isRedAttack);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ReceiveDamage(Z_Param_damageAmount,Z_Param_attackingActor,Z_Param_Out_hitResult,Z_Param_isRedAttack);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AYoru::execSetPlayerState)
	{
		P_GET_ENUM_REF(EPlayerState,Z_Param_Out_state);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetPlayerState((EPlayerState&)(Z_Param_Out_state));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AYoru::execSetisPressedMovementInput)
	{
		P_GET_UBOOL(Z_Param_isPressed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetisPressedMovementInput(Z_Param_isPressed);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AYoru::execGetisPressedMovementInput)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetisPressedMovementInput();
		P_NATIVE_END;
	}
	void AYoru::StaticRegisterNativesAYoru()
	{
		UClass* Class = AYoru::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ChangeCamera", &AYoru::execChangeCamera },
			{ "FallingDie", &AYoru::execFallingDie },
			{ "GetIsLockon", &AYoru::execGetIsLockon },
			{ "GetisPressedMovementInput", &AYoru::execGetisPressedMovementInput },
			{ "ReceiveDamage", &AYoru::execReceiveDamage },
			{ "SetIsLockon", &AYoru::execSetIsLockon },
			{ "SetisPressedMovementInput", &AYoru::execSetisPressedMovementInput },
			{ "SetPlayerState", &AYoru::execSetPlayerState },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AYoru_ChangeCamera_Statics
	{
		struct Yoru_eventChangeCamera_Parms
		{
			bool isLockonMove;
		};
		static void NewProp_isLockonMove_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isLockonMove;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AYoru_ChangeCamera_Statics::NewProp_isLockonMove_SetBit(void* Obj)
	{
		((Yoru_eventChangeCamera_Parms*)Obj)->isLockonMove = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AYoru_ChangeCamera_Statics::NewProp_isLockonMove = { "isLockonMove", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Yoru_eventChangeCamera_Parms), &Z_Construct_UFunction_AYoru_ChangeCamera_Statics::NewProp_isLockonMove_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AYoru_ChangeCamera_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AYoru_ChangeCamera_Statics::NewProp_isLockonMove,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AYoru_ChangeCamera_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AYoru_ChangeCamera_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AYoru, nullptr, "ChangeCamera", nullptr, nullptr, Z_Construct_UFunction_AYoru_ChangeCamera_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_ChangeCamera_Statics::PropPointers), sizeof(Z_Construct_UFunction_AYoru_ChangeCamera_Statics::Yoru_eventChangeCamera_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_ChangeCamera_Statics::Function_MetaDataParams), Z_Construct_UFunction_AYoru_ChangeCamera_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_ChangeCamera_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AYoru_ChangeCamera_Statics::Yoru_eventChangeCamera_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AYoru_ChangeCamera()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AYoru_ChangeCamera_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AYoru_FallingDie_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AYoru_FallingDie_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AYoru_FallingDie_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AYoru, nullptr, "FallingDie", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_FallingDie_Statics::Function_MetaDataParams), Z_Construct_UFunction_AYoru_FallingDie_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AYoru_FallingDie()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AYoru_FallingDie_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AYoru_GetIsLockon_Statics
	{
		struct Yoru_eventGetIsLockon_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AYoru_GetIsLockon_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Yoru_eventGetIsLockon_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AYoru_GetIsLockon_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Yoru_eventGetIsLockon_Parms), &Z_Construct_UFunction_AYoru_GetIsLockon_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AYoru_GetIsLockon_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AYoru_GetIsLockon_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AYoru_GetIsLockon_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AYoru_GetIsLockon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AYoru, nullptr, "GetIsLockon", nullptr, nullptr, Z_Construct_UFunction_AYoru_GetIsLockon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_GetIsLockon_Statics::PropPointers), sizeof(Z_Construct_UFunction_AYoru_GetIsLockon_Statics::Yoru_eventGetIsLockon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_GetIsLockon_Statics::Function_MetaDataParams), Z_Construct_UFunction_AYoru_GetIsLockon_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_GetIsLockon_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AYoru_GetIsLockon_Statics::Yoru_eventGetIsLockon_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AYoru_GetIsLockon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AYoru_GetIsLockon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics
	{
		struct Yoru_eventGetisPressedMovementInput_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Yoru_eventGetisPressedMovementInput_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Yoru_eventGetisPressedMovementInput_Parms), &Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AYoru, nullptr, "GetisPressedMovementInput", nullptr, nullptr, Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::PropPointers), sizeof(Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::Yoru_eventGetisPressedMovementInput_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::Function_MetaDataParams), Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::Yoru_eventGetisPressedMovementInput_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AYoru_GetisPressedMovementInput()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AYoru_ReceiveDamage_Statics
	{
		struct Yoru_eventReceiveDamage_Parms
		{
			float damageAmount;
			AActor* attackingActor;
			FHitResult hitResult;
			bool isRedAttack;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_damageAmount;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_attackingActor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_hitResult_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_hitResult;
		static void NewProp_isRedAttack_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isRedAttack;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AYoru_ReceiveDamage_Statics::NewProp_damageAmount = { "damageAmount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Yoru_eventReceiveDamage_Parms, damageAmount), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AYoru_ReceiveDamage_Statics::NewProp_attackingActor = { "attackingActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Yoru_eventReceiveDamage_Parms, attackingActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AYoru_ReceiveDamage_Statics::NewProp_hitResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AYoru_ReceiveDamage_Statics::NewProp_hitResult = { "hitResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Yoru_eventReceiveDamage_Parms, hitResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_ReceiveDamage_Statics::NewProp_hitResult_MetaData), Z_Construct_UFunction_AYoru_ReceiveDamage_Statics::NewProp_hitResult_MetaData) }; // 1891709922
	void Z_Construct_UFunction_AYoru_ReceiveDamage_Statics::NewProp_isRedAttack_SetBit(void* Obj)
	{
		((Yoru_eventReceiveDamage_Parms*)Obj)->isRedAttack = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AYoru_ReceiveDamage_Statics::NewProp_isRedAttack = { "isRedAttack", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Yoru_eventReceiveDamage_Parms), &Z_Construct_UFunction_AYoru_ReceiveDamage_Statics::NewProp_isRedAttack_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AYoru_ReceiveDamage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AYoru_ReceiveDamage_Statics::NewProp_damageAmount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AYoru_ReceiveDamage_Statics::NewProp_attackingActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AYoru_ReceiveDamage_Statics::NewProp_hitResult,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AYoru_ReceiveDamage_Statics::NewProp_isRedAttack,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AYoru_ReceiveDamage_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AYoru_ReceiveDamage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AYoru, nullptr, "ReceiveDamage", nullptr, nullptr, Z_Construct_UFunction_AYoru_ReceiveDamage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_ReceiveDamage_Statics::PropPointers), sizeof(Z_Construct_UFunction_AYoru_ReceiveDamage_Statics::Yoru_eventReceiveDamage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_ReceiveDamage_Statics::Function_MetaDataParams), Z_Construct_UFunction_AYoru_ReceiveDamage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_ReceiveDamage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AYoru_ReceiveDamage_Statics::Yoru_eventReceiveDamage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AYoru_ReceiveDamage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AYoru_ReceiveDamage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AYoru_SetIsLockon_Statics
	{
		struct Yoru_eventSetIsLockon_Parms
		{
			bool lockon;
		};
		static void NewProp_lockon_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_lockon;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AYoru_SetIsLockon_Statics::NewProp_lockon_SetBit(void* Obj)
	{
		((Yoru_eventSetIsLockon_Parms*)Obj)->lockon = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AYoru_SetIsLockon_Statics::NewProp_lockon = { "lockon", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Yoru_eventSetIsLockon_Parms), &Z_Construct_UFunction_AYoru_SetIsLockon_Statics::NewProp_lockon_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AYoru_SetIsLockon_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AYoru_SetIsLockon_Statics::NewProp_lockon,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AYoru_SetIsLockon_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AYoru_SetIsLockon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AYoru, nullptr, "SetIsLockon", nullptr, nullptr, Z_Construct_UFunction_AYoru_SetIsLockon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_SetIsLockon_Statics::PropPointers), sizeof(Z_Construct_UFunction_AYoru_SetIsLockon_Statics::Yoru_eventSetIsLockon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_SetIsLockon_Statics::Function_MetaDataParams), Z_Construct_UFunction_AYoru_SetIsLockon_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_SetIsLockon_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AYoru_SetIsLockon_Statics::Yoru_eventSetIsLockon_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AYoru_SetIsLockon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AYoru_SetIsLockon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics
	{
		struct Yoru_eventSetisPressedMovementInput_Parms
		{
			bool isPressed;
		};
		static void NewProp_isPressed_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isPressed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::NewProp_isPressed_SetBit(void* Obj)
	{
		((Yoru_eventSetisPressedMovementInput_Parms*)Obj)->isPressed = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::NewProp_isPressed = { "isPressed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Yoru_eventSetisPressedMovementInput_Parms), &Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::NewProp_isPressed_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::NewProp_isPressed,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AYoru, nullptr, "SetisPressedMovementInput", nullptr, nullptr, Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::PropPointers), sizeof(Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::Yoru_eventSetisPressedMovementInput_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::Function_MetaDataParams), Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::Yoru_eventSetisPressedMovementInput_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AYoru_SetisPressedMovementInput()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AYoru_SetPlayerState_Statics
	{
		struct Yoru_eventSetPlayerState_Parms
		{
			EPlayerState state;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_state_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_state;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AYoru_SetPlayerState_Statics::NewProp_state_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AYoru_SetPlayerState_Statics::NewProp_state = { "state", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Yoru_eventSetPlayerState_Parms, state), Z_Construct_UEnum_LiesOfM_EPlayerState, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_SetPlayerState_Statics::NewProp_state_MetaData), Z_Construct_UFunction_AYoru_SetPlayerState_Statics::NewProp_state_MetaData) }; // 1802911681
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AYoru_SetPlayerState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AYoru_SetPlayerState_Statics::NewProp_state,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AYoru_SetPlayerState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Test" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AYoru_SetPlayerState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AYoru, nullptr, "SetPlayerState", nullptr, nullptr, Z_Construct_UFunction_AYoru_SetPlayerState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_SetPlayerState_Statics::PropPointers), sizeof(Z_Construct_UFunction_AYoru_SetPlayerState_Statics::Yoru_eventSetPlayerState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_SetPlayerState_Statics::Function_MetaDataParams), Z_Construct_UFunction_AYoru_SetPlayerState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_SetPlayerState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AYoru_SetPlayerState_Statics::Yoru_eventSetPlayerState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AYoru_SetPlayerState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AYoru_SetPlayerState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AYoru);
	UClass* Z_Construct_UClass_AYoru_NoRegister()
	{
		return AYoru::StaticClass();
	}
	struct Z_Construct_UClass_AYoru_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_mainSpringArmComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_mainSpringArmComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_mainCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_mainCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_moveComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_moveComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_statComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_statComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_widgetComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_widgetComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_attackComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_attackComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_defenceComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_defenceComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_lockonComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_lockonComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_lockonWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_lockonWidget;
		static const UECodeGen_Private::FBytePropertyParams NewProp_currentPlayerState_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_currentPlayerState_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_currentPlayerState;
		static const UECodeGen_Private::FBytePropertyParams NewProp_currentRightWeaponState_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_currentRightWeaponState_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_currentRightWeaponState;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_equippedWeapon_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_equippedWeapon;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_equippedItem_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_equippedItem;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_defaultInputMappingContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_defaultInputMappingContext;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_singleGameInstance_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_singleGameInstance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_isDie_MetaData[];
#endif
		static void NewProp_isDie_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isDie;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_isCanJump_MetaData[];
#endif
		static void NewProp_isCanJump_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isCanJump;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_isPressedMovementInput_MetaData[];
#endif
		static void NewProp_isPressedMovementInput_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isPressedMovementInput;
		static const UECodeGen_Private::FNamePropertyParams NewProp_dataTableRowNames_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_dataTableRowNames_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_dataTableRowNames;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_isLockon_MetaData[];
#endif
		static void NewProp_isLockon_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isLockon;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AYoru_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_LiesOfM,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AYoru_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AYoru_ChangeCamera, "ChangeCamera" }, // 2083668526
		{ &Z_Construct_UFunction_AYoru_FallingDie, "FallingDie" }, // 89723923
		{ &Z_Construct_UFunction_AYoru_GetIsLockon, "GetIsLockon" }, // 210853662
		{ &Z_Construct_UFunction_AYoru_GetisPressedMovementInput, "GetisPressedMovementInput" }, // 3997279820
		{ &Z_Construct_UFunction_AYoru_ReceiveDamage, "ReceiveDamage" }, // 2174197963
		{ &Z_Construct_UFunction_AYoru_SetIsLockon, "SetIsLockon" }, // 584351737
		{ &Z_Construct_UFunction_AYoru_SetisPressedMovementInput, "SetisPressedMovementInput" }, // 2097408035
		{ &Z_Construct_UFunction_AYoru_SetPlayerState, "SetPlayerState" }, // 1816874815
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYoru_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "YoruPlayer/Yoru.h" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYoru_Statics::NewProp_mainSpringArmComp_MetaData[] = {
		{ "Category", "Yoru|Compoent" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_mainSpringArmComp = { "mainSpringArmComp", nullptr, (EPropertyFlags)0x001400000008000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYoru, mainSpringArmComp), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::NewProp_mainSpringArmComp_MetaData), Z_Construct_UClass_AYoru_Statics::NewProp_mainSpringArmComp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYoru_Statics::NewProp_mainCamera_MetaData[] = {
		{ "Category", "Yoru|Compoent" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_mainCamera = { "mainCamera", nullptr, (EPropertyFlags)0x001400000008000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYoru, mainCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::NewProp_mainCamera_MetaData), Z_Construct_UClass_AYoru_Statics::NewProp_mainCamera_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYoru_Statics::NewProp_moveComp_MetaData[] = {
		{ "Category", "Yoru|Component" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//UPROPERTY(BlueprintReadWrite, Category = \"Yoru|Compoent\")\n//TObjectPtr<class USkeletalMeshComponent> rightWeapon{};\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UPROPERTY(BlueprintReadWrite, Category = \"Yoru|Compoent\")\nTObjectPtr<class USkeletalMeshComponent> rightWeapon{};" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_moveComp = { "moveComp", nullptr, (EPropertyFlags)0x001400000008000c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYoru, moveComp), Z_Construct_UClass_UYoruMoveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::NewProp_moveComp_MetaData), Z_Construct_UClass_AYoru_Statics::NewProp_moveComp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYoru_Statics::NewProp_statComp_MetaData[] = {
		{ "Category", "Yoru|Component" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_statComp = { "statComp", nullptr, (EPropertyFlags)0x001400000008000c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYoru, statComp), Z_Construct_UClass_UYoruStatComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::NewProp_statComp_MetaData), Z_Construct_UClass_AYoru_Statics::NewProp_statComp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYoru_Statics::NewProp_widgetComp_MetaData[] = {
		{ "Category", "Yoru|Component" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_widgetComp = { "widgetComp", nullptr, (EPropertyFlags)0x001400000008000c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYoru, widgetComp), Z_Construct_UClass_UYoruWidgetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::NewProp_widgetComp_MetaData), Z_Construct_UClass_AYoru_Statics::NewProp_widgetComp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYoru_Statics::NewProp_attackComp_MetaData[] = {
		{ "Category", "Yoru|Component" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_attackComp = { "attackComp", nullptr, (EPropertyFlags)0x001400000008000c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYoru, attackComp), Z_Construct_UClass_UYoruAttackComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::NewProp_attackComp_MetaData), Z_Construct_UClass_AYoru_Statics::NewProp_attackComp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYoru_Statics::NewProp_defenceComp_MetaData[] = {
		{ "Category", "Yoru|Component" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_defenceComp = { "defenceComp", nullptr, (EPropertyFlags)0x001400000008000c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYoru, defenceComp), Z_Construct_UClass_UYoruDefenceComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::NewProp_defenceComp_MetaData), Z_Construct_UClass_AYoru_Statics::NewProp_defenceComp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYoru_Statics::NewProp_lockonComp_MetaData[] = {
		{ "Category", "Yoru|Component" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_lockonComp = { "lockonComp", nullptr, (EPropertyFlags)0x001400000008000c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYoru, lockonComp), Z_Construct_UClass_UYoruLockonComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::NewProp_lockonComp_MetaData), Z_Construct_UClass_AYoru_Statics::NewProp_lockonComp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYoru_Statics::NewProp_lockonWidget_MetaData[] = {
		{ "Category", "Yoru|Component" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_lockonWidget = { "lockonWidget", nullptr, (EPropertyFlags)0x001400000008000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYoru, lockonWidget), Z_Construct_UClass_UWidgetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::NewProp_lockonWidget_MetaData), Z_Construct_UClass_AYoru_Statics::NewProp_lockonWidget_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_currentPlayerState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYoru_Statics::NewProp_currentPlayerState_MetaData[] = {
		{ "Category", "Yoru" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_currentPlayerState = { "currentPlayerState", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYoru, currentPlayerState), Z_Construct_UEnum_LiesOfM_EPlayerState, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::NewProp_currentPlayerState_MetaData), Z_Construct_UClass_AYoru_Statics::NewProp_currentPlayerState_MetaData) }; // 1802911681
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_currentRightWeaponState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYoru_Statics::NewProp_currentRightWeaponState_MetaData[] = {
		{ "Category", "Yoru" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_currentRightWeaponState = { "currentRightWeaponState", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYoru, currentRightWeaponState), Z_Construct_UEnum_LiesOfM_EUseWeaponState, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::NewProp_currentRightWeaponState_MetaData), Z_Construct_UClass_AYoru_Statics::NewProp_currentRightWeaponState_MetaData) }; // 2514565648
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYoru_Statics::NewProp_equippedWeapon_MetaData[] = {
		{ "Category", "Yoru|Weapon" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_equippedWeapon = { "equippedWeapon", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYoru, equippedWeapon), Z_Construct_UClass_AWeaponBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::NewProp_equippedWeapon_MetaData), Z_Construct_UClass_AYoru_Statics::NewProp_equippedWeapon_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYoru_Statics::NewProp_equippedItem_MetaData[] = {
		{ "Category", "Yoru|Item" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_equippedItem = { "equippedItem", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYoru, equippedItem), Z_Construct_UClass_AItemBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::NewProp_equippedItem_MetaData), Z_Construct_UClass_AYoru_Statics::NewProp_equippedItem_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYoru_Statics::NewProp_defaultInputMappingContext_MetaData[] = {
		{ "Category", "Yoru|Input" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_defaultInputMappingContext = { "defaultInputMappingContext", nullptr, (EPropertyFlags)0x0014000000020001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYoru, defaultInputMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::NewProp_defaultInputMappingContext_MetaData), Z_Construct_UClass_AYoru_Statics::NewProp_defaultInputMappingContext_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYoru_Statics::NewProp_singleGameInstance_MetaData[] = {
		{ "Category", "Yoru|Utility" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_singleGameInstance = { "singleGameInstance", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYoru, singleGameInstance), Z_Construct_UClass_UTOMGameInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::NewProp_singleGameInstance_MetaData), Z_Construct_UClass_AYoru_Statics::NewProp_singleGameInstance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYoru_Statics::NewProp_isDie_MetaData[] = {
		{ "Category", "Yoru" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	void Z_Construct_UClass_AYoru_Statics::NewProp_isDie_SetBit(void* Obj)
	{
		((AYoru*)Obj)->isDie = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_isDie = { "isDie", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AYoru), &Z_Construct_UClass_AYoru_Statics::NewProp_isDie_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::NewProp_isDie_MetaData), Z_Construct_UClass_AYoru_Statics::NewProp_isDie_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYoru_Statics::NewProp_isCanJump_MetaData[] = {
		{ "Category", "Yoru" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	void Z_Construct_UClass_AYoru_Statics::NewProp_isCanJump_SetBit(void* Obj)
	{
		((AYoru*)Obj)->isCanJump = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_isCanJump = { "isCanJump", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AYoru), &Z_Construct_UClass_AYoru_Statics::NewProp_isCanJump_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::NewProp_isCanJump_MetaData), Z_Construct_UClass_AYoru_Statics::NewProp_isCanJump_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYoru_Statics::NewProp_isPressedMovementInput_MetaData[] = {
		{ "Category", "Yoru|Input" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	void Z_Construct_UClass_AYoru_Statics::NewProp_isPressedMovementInput_SetBit(void* Obj)
	{
		((AYoru*)Obj)->isPressedMovementInput = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_isPressedMovementInput = { "isPressedMovementInput", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AYoru), &Z_Construct_UClass_AYoru_Statics::NewProp_isPressedMovementInput_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::NewProp_isPressedMovementInput_MetaData), Z_Construct_UClass_AYoru_Statics::NewProp_isPressedMovementInput_MetaData) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_dataTableRowNames_Inner = { "dataTableRowNames", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYoru_Statics::NewProp_dataTableRowNames_MetaData[] = {
		{ "Category", "Yoru|DataTable" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_dataTableRowNames = { "dataTableRowNames", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYoru, dataTableRowNames), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::NewProp_dataTableRowNames_MetaData), Z_Construct_UClass_AYoru_Statics::NewProp_dataTableRowNames_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYoru_Statics::NewProp_isLockon_MetaData[] = {
		{ "Category", "Yoru|Input" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	void Z_Construct_UClass_AYoru_Statics::NewProp_isLockon_SetBit(void* Obj)
	{
		((AYoru*)Obj)->isLockon = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_isLockon = { "isLockon", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AYoru), &Z_Construct_UClass_AYoru_Statics::NewProp_isLockon_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::NewProp_isLockon_MetaData), Z_Construct_UClass_AYoru_Statics::NewProp_isLockon_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AYoru_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_mainSpringArmComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_mainCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_moveComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_statComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_widgetComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_attackComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_defenceComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_lockonComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_lockonWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_currentPlayerState_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_currentPlayerState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_currentRightWeaponState_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_currentRightWeaponState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_equippedWeapon,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_equippedItem,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_defaultInputMappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_singleGameInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_isDie,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_isCanJump,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_isPressedMovementInput,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_dataTableRowNames_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_dataTableRowNames,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_isLockon,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AYoru_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UDamageInteractions_NoRegister, (int32)VTABLE_OFFSET(AYoru, IDamageInteractions), false },  // 807609110
		};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::InterfaceParams) < 64);
	const FCppClassTypeInfoStatic Z_Construct_UClass_AYoru_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AYoru>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AYoru_Statics::ClassParams = {
		&AYoru::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AYoru_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::Class_MetaDataParams), Z_Construct_UClass_AYoru_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AYoru()
	{
		if (!Z_Registration_Info_UClass_AYoru.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AYoru.OuterSingleton, Z_Construct_UClass_AYoru_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AYoru.OuterSingleton;
	}
	template<> LIESOFM_API UClass* StaticClass<AYoru>()
	{
		return AYoru::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AYoru);
	AYoru::~AYoru() {}
	struct Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_Statics::EnumInfo[] = {
		{ EPlayerState_StaticEnum, TEXT("EPlayerState"), &Z_Registration_Info_UEnum_EPlayerState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1802911681U) },
		{ EUseWeaponState_StaticEnum, TEXT("EUseWeaponState"), &Z_Registration_Info_UEnum_EUseWeaponState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2514565648U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AYoru, AYoru::StaticClass, TEXT("AYoru"), &Z_Registration_Info_UClass_AYoru, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AYoru), 2406423933U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_481723082(TEXT("/Script/LiesOfM"),
		Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
