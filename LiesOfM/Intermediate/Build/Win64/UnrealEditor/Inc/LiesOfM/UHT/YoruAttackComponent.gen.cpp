// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LiesOfM/Public/YoruPlayer/YoruAttackComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYoruAttackComponent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	LIESOFM_API UClass* Z_Construct_UClass_AEnemyBase_NoRegister();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruAttackComponent();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruAttackComponent_NoRegister();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruBaseComponent();
	UPackage* Z_Construct_UPackage__Script_LiesOfM();
// End Cross Module References
	DEFINE_FUNCTION(UYoruAttackComponent::execStopLineTrace)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopLineTrace();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UYoruAttackComponent::execApplyLineTrace)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ApplyLineTrace();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UYoruAttackComponent::execTriggerLineTrace)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TriggerLineTrace();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UYoruAttackComponent::execRotateAttackDirection)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RotateAttackDirection();
		P_NATIVE_END;
	}
	void UYoruAttackComponent::StaticRegisterNativesUYoruAttackComponent()
	{
		UClass* Class = UYoruAttackComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ApplyLineTrace", &UYoruAttackComponent::execApplyLineTrace },
			{ "RotateAttackDirection", &UYoruAttackComponent::execRotateAttackDirection },
			{ "StopLineTrace", &UYoruAttackComponent::execStopLineTrace },
			{ "TriggerLineTrace", &UYoruAttackComponent::execTriggerLineTrace },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UYoruAttackComponent_ApplyLineTrace_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UYoruAttackComponent_ApplyLineTrace_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAttackComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UYoruAttackComponent_ApplyLineTrace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UYoruAttackComponent, nullptr, "ApplyLineTrace", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UYoruAttackComponent_ApplyLineTrace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UYoruAttackComponent_ApplyLineTrace_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UYoruAttackComponent_ApplyLineTrace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UYoruAttackComponent_ApplyLineTrace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UYoruAttackComponent_RotateAttackDirection_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UYoruAttackComponent_RotateAttackDirection_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAttackComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UYoruAttackComponent_RotateAttackDirection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UYoruAttackComponent, nullptr, "RotateAttackDirection", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UYoruAttackComponent_RotateAttackDirection_Statics::Function_MetaDataParams), Z_Construct_UFunction_UYoruAttackComponent_RotateAttackDirection_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UYoruAttackComponent_RotateAttackDirection()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UYoruAttackComponent_RotateAttackDirection_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UYoruAttackComponent_StopLineTrace_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UYoruAttackComponent_StopLineTrace_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAttackComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UYoruAttackComponent_StopLineTrace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UYoruAttackComponent, nullptr, "StopLineTrace", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UYoruAttackComponent_StopLineTrace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UYoruAttackComponent_StopLineTrace_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UYoruAttackComponent_StopLineTrace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UYoruAttackComponent_StopLineTrace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UYoruAttackComponent_TriggerLineTrace_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UYoruAttackComponent_TriggerLineTrace_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAttackComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UYoruAttackComponent_TriggerLineTrace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UYoruAttackComponent, nullptr, "TriggerLineTrace", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UYoruAttackComponent_TriggerLineTrace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UYoruAttackComponent_TriggerLineTrace_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UYoruAttackComponent_TriggerLineTrace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UYoruAttackComponent_TriggerLineTrace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UYoruAttackComponent);
	UClass* Z_Construct_UClass_UYoruAttackComponent_NoRegister()
	{
		return UYoruAttackComponent::StaticClass();
	}
	struct Z_Construct_UClass_UYoruAttackComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_curve_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_curve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_lightAttackAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_lightAttackAction;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_hitActors_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_hitActors_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_hitActors;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_grabActor_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_grabActor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_wallHitMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_wallHitMontage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_grabAttackMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_grabAttackMontage;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UYoruAttackComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UYoruBaseComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_LiesOfM,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAttackComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UYoruAttackComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UYoruAttackComponent_ApplyLineTrace, "ApplyLineTrace" }, // 1889392145
		{ &Z_Construct_UFunction_UYoruAttackComponent_RotateAttackDirection, "RotateAttackDirection" }, // 3505555053
		{ &Z_Construct_UFunction_UYoruAttackComponent_StopLineTrace, "StopLineTrace" }, // 1336293546
		{ &Z_Construct_UFunction_UYoruAttackComponent_TriggerLineTrace, "TriggerLineTrace" }, // 4046885866
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAttackComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruAttackComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "YoruPlayer/YoruAttackComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAttackComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_curve_MetaData[] = {
		{ "Category", "Yoru|Timeline" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAttackComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_curve = { "curve", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruAttackComponent, curve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_curve_MetaData), Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_curve_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_lightAttackAction_MetaData[] = {
		{ "Category", "Yoru|Input" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAttackComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_lightAttackAction = { "lightAttackAction", nullptr, (EPropertyFlags)0x0044000000020001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruAttackComponent, lightAttackAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_lightAttackAction_MetaData), Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_lightAttackAction_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_hitActors_Inner = { "hitActors", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_hitActors_MetaData[] = {
		{ "Category", "Yoru|Actor" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAttackComponent.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_hitActors = { "hitActors", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruAttackComponent, hitActors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_hitActors_MetaData), Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_hitActors_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_grabActor_MetaData[] = {
		{ "Category", "Yoru|Actor" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAttackComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_grabActor = { "grabActor", nullptr, (EPropertyFlags)0x0044000000020001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruAttackComponent, grabActor), Z_Construct_UClass_AEnemyBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_grabActor_MetaData), Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_grabActor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_wallHitMontage_MetaData[] = {
		{ "Category", "Yoru|Montage" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAttackComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_wallHitMontage = { "wallHitMontage", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruAttackComponent, wallHitMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_wallHitMontage_MetaData), Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_wallHitMontage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_grabAttackMontage_MetaData[] = {
		{ "Category", "Yoru|Montage" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAttackComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_grabAttackMontage = { "grabAttackMontage", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruAttackComponent, grabAttackMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_grabAttackMontage_MetaData), Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_grabAttackMontage_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UYoruAttackComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_curve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_lightAttackAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_hitActors_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_hitActors,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_grabActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_wallHitMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruAttackComponent_Statics::NewProp_grabAttackMontage,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UYoruAttackComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UYoruAttackComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UYoruAttackComponent_Statics::ClassParams = {
		&UYoruAttackComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UYoruAttackComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAttackComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAttackComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UYoruAttackComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAttackComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UYoruAttackComponent()
	{
		if (!Z_Registration_Info_UClass_UYoruAttackComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UYoruAttackComponent.OuterSingleton, Z_Construct_UClass_UYoruAttackComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UYoruAttackComponent.OuterSingleton;
	}
	template<> LIESOFM_API UClass* StaticClass<UYoruAttackComponent>()
	{
		return UYoruAttackComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UYoruAttackComponent);
	UYoruAttackComponent::~UYoruAttackComponent() {}
	struct Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruAttackComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruAttackComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UYoruAttackComponent, UYoruAttackComponent::StaticClass, TEXT("UYoruAttackComponent"), &Z_Registration_Info_UClass_UYoruAttackComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UYoruAttackComponent), 334814641U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruAttackComponent_h_4140129252(TEXT("/Script/LiesOfM"),
		Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruAttackComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruAttackComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
