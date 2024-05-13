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
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruBaseComponent();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruMoveComponent();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruMoveComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_LiesOfM();
// End Cross Module References
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
			{ "MovementInputHandler", &UYoruMoveComponent::execMovementInputHandler },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_defaultInputMappingContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_defaultInputMappingContext;
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_mouseSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_mouseSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_canBeHit_MetaData[];
#endif
		static void NewProp_canBeHit_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_canBeHit;
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
		{ &Z_Construct_UFunction_UYoruMoveComponent_MovementInputHandler, "MovementInputHandler" }, // 1628321773
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_defaultInputMappingContext_MetaData[] = {
		{ "Category", "Yoru|Input" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruMoveComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_defaultInputMappingContext = { "defaultInputMappingContext", nullptr, (EPropertyFlags)0x0044000000020001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruMoveComponent, defaultInputMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_defaultInputMappingContext_MetaData), Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_defaultInputMappingContext_MetaData) };
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
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UYoruMoveComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_defaultInputMappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_moveAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_lookAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_jumpAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_moveChangeAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_runRollAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_crouchAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_changeWeaponAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_rollingMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_stepBackMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_equipMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_unEquipMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_mouseSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_canBeHit,
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
		{ Z_Construct_UClass_UYoruMoveComponent, UYoruMoveComponent::StaticClass, TEXT("UYoruMoveComponent"), &Z_Registration_Info_UClass_UYoruMoveComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UYoruMoveComponent), 2107636099U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_2554297508(TEXT("/Script/LiesOfM"),
		Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
