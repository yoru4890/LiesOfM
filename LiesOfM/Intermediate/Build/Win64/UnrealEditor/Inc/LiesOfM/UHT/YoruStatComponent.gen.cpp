// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LiesOfM/Public/YoruPlayer/YoruStatComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYoruStatComponent() {}
// Cross Module References
	LIESOFM_API UClass* Z_Construct_UClass_UYoruBaseComponent();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruStatComponent();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruStatComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_LiesOfM();
// End Cross Module References
	DEFINE_FUNCTION(UYoruStatComponent::execTempTemp)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TempTemp();
		P_NATIVE_END;
	}
	void UYoruStatComponent::StaticRegisterNativesUYoruStatComponent()
	{
		UClass* Class = UYoruStatComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "TempTemp", &UYoruStatComponent::execTempTemp },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UYoruStatComponent_TempTemp_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UYoruStatComponent_TempTemp_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruStatComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UYoruStatComponent_TempTemp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UYoruStatComponent, nullptr, "TempTemp", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UYoruStatComponent_TempTemp_Statics::Function_MetaDataParams), Z_Construct_UFunction_UYoruStatComponent_TempTemp_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UYoruStatComponent_TempTemp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UYoruStatComponent_TempTemp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UYoruStatComponent);
	UClass* Z_Construct_UClass_UYoruStatComponent_NoRegister()
	{
		return UYoruStatComponent::StaticClass();
	}
	struct Z_Construct_UClass_UYoruStatComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_currentStamina_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_currentStamina;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_maxStamina_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_maxStamina;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StaminaRegen_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_StaminaRegen;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_walkSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_walkSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_jogSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_jogSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_runSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_runSpeed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UYoruStatComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UYoruBaseComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_LiesOfM,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruStatComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UYoruStatComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UYoruStatComponent_TempTemp, "TempTemp" }, // 3793009933
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruStatComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruStatComponent_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "YoruPlayer/YoruStatComponent.h" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruStatComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_currentStamina_MetaData[] = {
		{ "Category", "Your|Stamina" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruStatComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_currentStamina = { "currentStamina", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruStatComponent, currentStamina), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_currentStamina_MetaData), Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_currentStamina_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_maxStamina_MetaData[] = {
		{ "Category", "Your|Stamina" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruStatComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_maxStamina = { "maxStamina", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruStatComponent, maxStamina), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_maxStamina_MetaData), Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_maxStamina_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_StaminaRegen_MetaData[] = {
		{ "Category", "Your|Stamina" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruStatComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_StaminaRegen = { "StaminaRegen", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruStatComponent, StaminaRegen), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_StaminaRegen_MetaData), Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_StaminaRegen_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_walkSpeed_MetaData[] = {
		{ "Category", "Yoru|Speed" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruStatComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_walkSpeed = { "walkSpeed", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruStatComponent, walkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_walkSpeed_MetaData), Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_walkSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_jogSpeed_MetaData[] = {
		{ "Category", "Your|Speed" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruStatComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_jogSpeed = { "jogSpeed", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruStatComponent, jogSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_jogSpeed_MetaData), Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_jogSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_runSpeed_MetaData[] = {
		{ "Category", "Yoru|Speed" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruStatComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_runSpeed = { "runSpeed", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruStatComponent, runSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_runSpeed_MetaData), Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_runSpeed_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UYoruStatComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_currentStamina,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_maxStamina,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_StaminaRegen,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_walkSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_jogSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruStatComponent_Statics::NewProp_runSpeed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UYoruStatComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UYoruStatComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UYoruStatComponent_Statics::ClassParams = {
		&UYoruStatComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UYoruStatComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UYoruStatComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruStatComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UYoruStatComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruStatComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UYoruStatComponent()
	{
		if (!Z_Registration_Info_UClass_UYoruStatComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UYoruStatComponent.OuterSingleton, Z_Construct_UClass_UYoruStatComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UYoruStatComponent.OuterSingleton;
	}
	template<> LIESOFM_API UClass* StaticClass<UYoruStatComponent>()
	{
		return UYoruStatComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UYoruStatComponent);
	UYoruStatComponent::~UYoruStatComponent() {}
	struct Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruStatComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruStatComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UYoruStatComponent, UYoruStatComponent::StaticClass, TEXT("UYoruStatComponent"), &Z_Registration_Info_UClass_UYoruStatComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UYoruStatComponent), 699172750U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruStatComponent_h_319919692(TEXT("/Script/LiesOfM"),
		Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruStatComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruStatComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
