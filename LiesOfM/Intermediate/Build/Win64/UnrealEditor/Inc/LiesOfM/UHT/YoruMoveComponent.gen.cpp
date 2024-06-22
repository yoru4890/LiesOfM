// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LiesOfM/Public/YoruPlayer/YoruMoveComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYoruMoveComponent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruBaseComponent();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruMoveComponent();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruMoveComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_LiesOfM();
// End Cross Module References
	DEFINE_FUNCTION(UYoruMoveComponent::execStopBossEnter)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopBossEnter();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UYoruMoveComponent::execStopRollMove)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopRollMove();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UYoruMoveComponent::execCaculatePortion)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CaculatePortion();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UYoruMoveComponent::execHiddenItem)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HiddenItem();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UYoruMoveComponent::execShowItem)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ShowItem();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UYoruMoveComponent::execUnEquipRightWeapon)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UnEquipRightWeapon();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UYoruMoveComponent::execEquipRightWeapon)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EquipRightWeapon();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UYoruMoveComponent::execMovementInputHandler)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_duration);
		P_GET_UBOOL(Z_Param_isStopInput);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MovementInputHandler(Z_Param_duration,Z_Param_isStopInput);
		P_NATIVE_END;
	}
	void UYoruMoveComponent::StaticRegisterNativesUYoruMoveComponent()
	{
		UClass* Class = UYoruMoveComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CaculatePortion", &UYoruMoveComponent::execCaculatePortion },
			{ "EquipRightWeapon", &UYoruMoveComponent::execEquipRightWeapon },
			{ "HiddenItem", &UYoruMoveComponent::execHiddenItem },
			{ "MovementInputHandler", &UYoruMoveComponent::execMovementInputHandler },
			{ "ShowItem", &UYoruMoveComponent::execShowItem },
			{ "StopBossEnter", &UYoruMoveComponent::execStopBossEnter },
			{ "StopRollMove", &UYoruMoveComponent::execStopRollMove },
			{ "UnEquipRightWeapon", &UYoruMoveComponent::execUnEquipRightWeapon },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UYoruMoveComponent_CaculatePortion_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UYoruMoveComponent_CaculatePortion_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UYoruMoveComponent_CaculatePortion_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UYoruMoveComponent, nullptr, "CaculatePortion", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UYoruMoveComponent_CaculatePortion_Statics::Function_MetaDataParams), Z_Construct_UFunction_UYoruMoveComponent_CaculatePortion_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UYoruMoveComponent_CaculatePortion()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UYoruMoveComponent_CaculatePortion_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UYoruMoveComponent_EquipRightWeapon_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UYoruMoveComponent_EquipRightWeapon_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UYoruMoveComponent_EquipRightWeapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UYoruMoveComponent, nullptr, "EquipRightWeapon", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UYoruMoveComponent_EquipRightWeapon_Statics::Function_MetaDataParams), Z_Construct_UFunction_UYoruMoveComponent_EquipRightWeapon_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UYoruMoveComponent_EquipRightWeapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UYoruMoveComponent_EquipRightWeapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UYoruMoveComponent_HiddenItem_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UYoruMoveComponent_HiddenItem_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UYoruMoveComponent_HiddenItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UYoruMoveComponent, nullptr, "HiddenItem", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UYoruMoveComponent_HiddenItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UYoruMoveComponent_HiddenItem_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UYoruMoveComponent_HiddenItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UYoruMoveComponent_HiddenItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UYoruMoveComponent_MovementInputHandler_Statics
	{
		struct YoruMoveComponent_eventMovementInputHandler_Parms
		{
			float duration;
			bool isStopInput;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_duration;
		static void NewProp_isStopInput_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isStopInput;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UYoruMoveComponent_MovementInputHandler_Statics::NewProp_duration = { "duration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(YoruMoveComponent_eventMovementInputHandler_Parms, duration), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UYoruMoveComponent_MovementInputHandler_Statics::NewProp_isStopInput_SetBit(void* Obj)
	{
		((YoruMoveComponent_eventMovementInputHandler_Parms*)Obj)->isStopInput = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UYoruMoveComponent_MovementInputHandler_Statics::NewProp_isStopInput = { "isStopInput", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(YoruMoveComponent_eventMovementInputHandler_Parms), &Z_Construct_UFunction_UYoruMoveComponent_MovementInputHandler_Statics::NewProp_isStopInput_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UYoruMoveComponent_MovementInputHandler_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UYoruMoveComponent_MovementInputHandler_Statics::NewProp_duration,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UYoruMoveComponent_MovementInputHandler_Statics::NewProp_isStopInput,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UYoruMoveComponent_MovementInputHandler_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UYoruMoveComponent_MovementInputHandler_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UYoruMoveComponent, nullptr, "MovementInputHandler", nullptr, nullptr, Z_Construct_UFunction_UYoruMoveComponent_MovementInputHandler_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UYoruMoveComponent_MovementInputHandler_Statics::PropPointers), sizeof(Z_Construct_UFunction_UYoruMoveComponent_MovementInputHandler_Statics::YoruMoveComponent_eventMovementInputHandler_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UYoruMoveComponent_MovementInputHandler_Statics::Function_MetaDataParams), Z_Construct_UFunction_UYoruMoveComponent_MovementInputHandler_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UYoruMoveComponent_MovementInputHandler_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UYoruMoveComponent_MovementInputHandler_Statics::YoruMoveComponent_eventMovementInputHandler_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UYoruMoveComponent_MovementInputHandler()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UYoruMoveComponent_MovementInputHandler_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UYoruMoveComponent_ShowItem_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UYoruMoveComponent_ShowItem_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UYoruMoveComponent_ShowItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UYoruMoveComponent, nullptr, "ShowItem", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UYoruMoveComponent_ShowItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UYoruMoveComponent_ShowItem_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UYoruMoveComponent_ShowItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UYoruMoveComponent_ShowItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UYoruMoveComponent_StopBossEnter_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UYoruMoveComponent_StopBossEnter_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UYoruMoveComponent_StopBossEnter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UYoruMoveComponent, nullptr, "StopBossEnter", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UYoruMoveComponent_StopBossEnter_Statics::Function_MetaDataParams), Z_Construct_UFunction_UYoruMoveComponent_StopBossEnter_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UYoruMoveComponent_StopBossEnter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UYoruMoveComponent_StopBossEnter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UYoruMoveComponent_StopRollMove_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UYoruMoveComponent_StopRollMove_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UYoruMoveComponent_StopRollMove_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UYoruMoveComponent, nullptr, "StopRollMove", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UYoruMoveComponent_StopRollMove_Statics::Function_MetaDataParams), Z_Construct_UFunction_UYoruMoveComponent_StopRollMove_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UYoruMoveComponent_StopRollMove()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UYoruMoveComponent_StopRollMove_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UYoruMoveComponent_UnEquipRightWeapon_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UYoruMoveComponent_UnEquipRightWeapon_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UYoruMoveComponent_UnEquipRightWeapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UYoruMoveComponent, nullptr, "UnEquipRightWeapon", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UYoruMoveComponent_UnEquipRightWeapon_Statics::Function_MetaDataParams), Z_Construct_UFunction_UYoruMoveComponent_UnEquipRightWeapon_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UYoruMoveComponent_UnEquipRightWeapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UYoruMoveComponent_UnEquipRightWeapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UYoruMoveComponent);
	UClass* Z_Construct_UClass_UYoruMoveComponent_NoRegister()
	{
		return UYoruMoveComponent::StaticClass();
	}
	struct Z_Construct_UClass_UYoruMoveComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_moveAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_moveAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_lookAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_lookAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_jumpAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_jumpAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_moveChangeAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_moveChangeAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_runRollAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_runRollAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_crouchAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_crouchAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_changeWeaponAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_changeWeaponAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_useItemAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_useItemAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_interActAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_interActAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_rollingMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_rollingMontage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_stepBackMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_stepBackMontage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_equipMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_equipMontage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_unEquipMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_unEquipMontage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_useItemMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_useItemMontage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bossEnterMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_bossEnterMontage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bossEnterSound_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_bossEnterSound;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_mouseSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_mouseSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_canBeHit_MetaData[];
#endif
		static void NewProp_canBeHit_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_canBeHit;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_canBossEnter_MetaData[];
#endif
		static void NewProp_canBossEnter_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_canBossEnter;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_portionCount_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_portionCount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_rollDistance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_rollDistance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_rollMoveSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_rollMoveSpeed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UYoruMoveComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UYoruBaseComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_LiesOfM,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UYoruMoveComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UYoruMoveComponent_CaculatePortion, "CaculatePortion" }, // 2695019804
		{ &Z_Construct_UFunction_UYoruMoveComponent_EquipRightWeapon, "EquipRightWeapon" }, // 3050998919
		{ &Z_Construct_UFunction_UYoruMoveComponent_HiddenItem, "HiddenItem" }, // 2925751229
		{ &Z_Construct_UFunction_UYoruMoveComponent_MovementInputHandler, "MovementInputHandler" }, // 1628321773
		{ &Z_Construct_UFunction_UYoruMoveComponent_ShowItem, "ShowItem" }, // 1999823505
		{ &Z_Construct_UFunction_UYoruMoveComponent_StopBossEnter, "StopBossEnter" }, // 289148763
		{ &Z_Construct_UFunction_UYoruMoveComponent_StopRollMove, "StopRollMove" }, // 3181781862
		{ &Z_Construct_UFunction_UYoruMoveComponent_UnEquipRightWeapon, "UnEquipRightWeapon" }, // 2050398647
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruMoveComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "YoruPlayer/YoruMoveComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_moveAction_MetaData[] = {
		{ "Category", "Yoru|Input" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_moveAction = { "moveAction", nullptr, (EPropertyFlags)0x0044000000020001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruMoveComponent, moveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_moveAction_MetaData), Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_moveAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_lookAction_MetaData[] = {
		{ "Category", "Yoru|Input" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_lookAction = { "lookAction", nullptr, (EPropertyFlags)0x0044000000020001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruMoveComponent, lookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_lookAction_MetaData), Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_lookAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_jumpAction_MetaData[] = {
		{ "Category", "Yoru|Input" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_jumpAction = { "jumpAction", nullptr, (EPropertyFlags)0x0044000000020001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruMoveComponent, jumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_jumpAction_MetaData), Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_jumpAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_moveChangeAction_MetaData[] = {
		{ "Category", "Yoru|Input" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_moveChangeAction = { "moveChangeAction", nullptr, (EPropertyFlags)0x0044000000020001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruMoveComponent, moveChangeAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_moveChangeAction_MetaData), Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_moveChangeAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_runRollAction_MetaData[] = {
		{ "Category", "Yoru|Input" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_runRollAction = { "runRollAction", nullptr, (EPropertyFlags)0x0044000000020001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruMoveComponent, runRollAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_runRollAction_MetaData), Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_runRollAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_crouchAction_MetaData[] = {
		{ "Category", "Yoru|Input" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_crouchAction = { "crouchAction", nullptr, (EPropertyFlags)0x0044000000020001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruMoveComponent, crouchAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_crouchAction_MetaData), Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_crouchAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_changeWeaponAction_MetaData[] = {
		{ "Category", "Yoru|Input" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_changeWeaponAction = { "changeWeaponAction", nullptr, (EPropertyFlags)0x0044000000020001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruMoveComponent, changeWeaponAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_changeWeaponAction_MetaData), Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_changeWeaponAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_useItemAction_MetaData[] = {
		{ "Category", "Yoru|Input" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_useItemAction = { "useItemAction", nullptr, (EPropertyFlags)0x0044000000020001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruMoveComponent, useItemAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_useItemAction_MetaData), Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_useItemAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_interActAction_MetaData[] = {
		{ "Category", "Yoru|Input" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_interActAction = { "interActAction", nullptr, (EPropertyFlags)0x0044000000020001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruMoveComponent, interActAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_interActAction_MetaData), Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_interActAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_rollingMontage_MetaData[] = {
		{ "Category", "Yoru|Montage" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_rollingMontage = { "rollingMontage", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruMoveComponent, rollingMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_rollingMontage_MetaData), Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_rollingMontage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_stepBackMontage_MetaData[] = {
		{ "Category", "Yoru|Montage" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_stepBackMontage = { "stepBackMontage", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruMoveComponent, stepBackMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_stepBackMontage_MetaData), Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_stepBackMontage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_equipMontage_MetaData[] = {
		{ "Category", "Yoru|Montage" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_equipMontage = { "equipMontage", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruMoveComponent, equipMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_equipMontage_MetaData), Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_equipMontage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_unEquipMontage_MetaData[] = {
		{ "Category", "Yoru|Montage" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_unEquipMontage = { "unEquipMontage", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruMoveComponent, unEquipMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_unEquipMontage_MetaData), Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_unEquipMontage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_useItemMontage_MetaData[] = {
		{ "Category", "Yoru|Montage" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_useItemMontage = { "useItemMontage", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruMoveComponent, useItemMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_useItemMontage_MetaData), Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_useItemMontage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_bossEnterMontage_MetaData[] = {
		{ "Category", "Yoru|Montage" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_bossEnterMontage = { "bossEnterMontage", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruMoveComponent, bossEnterMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_bossEnterMontage_MetaData), Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_bossEnterMontage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_bossEnterSound_MetaData[] = {
		{ "Category", "Yoru|Sound" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_bossEnterSound = { "bossEnterSound", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruMoveComponent, bossEnterSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_bossEnterSound_MetaData), Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_bossEnterSound_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_mouseSpeed_MetaData[] = {
		{ "Category", "Yoru|Mouse" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_mouseSpeed = { "mouseSpeed", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruMoveComponent, mouseSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_mouseSpeed_MetaData), Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_mouseSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_canBeHit_MetaData[] = {
		{ "Category", "Yoru|Hit" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	void Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_canBeHit_SetBit(void* Obj)
	{
		((UYoruMoveComponent*)Obj)->canBeHit = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_canBeHit = { "canBeHit", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UYoruMoveComponent), &Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_canBeHit_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_canBeHit_MetaData), Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_canBeHit_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_canBossEnter_MetaData[] = {
		{ "Category", "Yoru|Hit" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	void Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_canBossEnter_SetBit(void* Obj)
	{
		((UYoruMoveComponent*)Obj)->canBossEnter = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_canBossEnter = { "canBossEnter", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UYoruMoveComponent), &Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_canBossEnter_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_canBossEnter_MetaData), Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_canBossEnter_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_portionCount_MetaData[] = {
		{ "Category", "Yoru|Item" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_portionCount = { "portionCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruMoveComponent, portionCount), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_portionCount_MetaData), Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_portionCount_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_rollDistance_MetaData[] = {
		{ "Category", "Yoru" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_rollDistance = { "rollDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruMoveComponent, rollDistance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_rollDistance_MetaData), Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_rollDistance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_rollMoveSpeed_MetaData[] = {
		{ "Category", "Yoru" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_rollMoveSpeed = { "rollMoveSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruMoveComponent, rollMoveSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_rollMoveSpeed_MetaData), Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_rollMoveSpeed_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UYoruMoveComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_moveAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_lookAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_jumpAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_moveChangeAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_runRollAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_crouchAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_changeWeaponAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_useItemAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_interActAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_rollingMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_stepBackMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_equipMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_unEquipMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_useItemMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_bossEnterMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_bossEnterSound,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_mouseSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_canBeHit,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_canBossEnter,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_portionCount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_rollDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_rollMoveSpeed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UYoruMoveComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UYoruMoveComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UYoruMoveComponent_Statics::ClassParams = {
		&UYoruMoveComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UYoruMoveComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UYoruMoveComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UYoruMoveComponent()
	{
		if (!Z_Registration_Info_UClass_UYoruMoveComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UYoruMoveComponent.OuterSingleton, Z_Construct_UClass_UYoruMoveComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UYoruMoveComponent.OuterSingleton;
	}
	template<> LIESOFM_API UClass* StaticClass<UYoruMoveComponent>()
	{
		return UYoruMoveComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UYoruMoveComponent);
	UYoruMoveComponent::~UYoruMoveComponent() {}
	struct Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UYoruMoveComponent, UYoruMoveComponent::StaticClass, TEXT("UYoruMoveComponent"), &Z_Registration_Info_UClass_UYoruMoveComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UYoruMoveComponent), 1812244269U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_1042761105(TEXT("/Script/LiesOfM"),
		Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
