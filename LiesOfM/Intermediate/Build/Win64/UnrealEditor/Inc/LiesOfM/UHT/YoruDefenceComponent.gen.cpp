// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LiesOfM/Public/YoruPlayer/YoruDefenceComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYoruDefenceComponent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruBaseComponent();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruDefenceComponent();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruDefenceComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_LiesOfM();
// End Cross Module References
	void UYoruDefenceComponent::StaticRegisterNativesUYoruDefenceComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UYoruDefenceComponent);
	UClass* Z_Construct_UClass_UYoruDefenceComponent_NoRegister()
	{
		return UYoruDefenceComponent::StaticClass();
	}
	struct Z_Construct_UClass_UYoruDefenceComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_blockAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_blockAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_blockMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_blockMontage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_isHittable_MetaData[];
#endif
		static void NewProp_isHittable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isHittable;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_isParrying_MetaData[];
#endif
		static void NewProp_isParrying_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isParrying;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UYoruDefenceComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UYoruBaseComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_LiesOfM,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruDefenceComponent_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruDefenceComponent_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "YoruPlayer/YoruDefenceComponent.h" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruDefenceComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruDefenceComponent_Statics::NewProp_blockAction_MetaData[] = {
		{ "Category", "Yoru|Input" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruDefenceComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UYoruDefenceComponent_Statics::NewProp_blockAction = { "blockAction", nullptr, (EPropertyFlags)0x0044000000020001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruDefenceComponent, blockAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruDefenceComponent_Statics::NewProp_blockAction_MetaData), Z_Construct_UClass_UYoruDefenceComponent_Statics::NewProp_blockAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruDefenceComponent_Statics::NewProp_blockMontage_MetaData[] = {
		{ "Category", "Yoru|Montage" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruDefenceComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UYoruDefenceComponent_Statics::NewProp_blockMontage = { "blockMontage", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruDefenceComponent, blockMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruDefenceComponent_Statics::NewProp_blockMontage_MetaData), Z_Construct_UClass_UYoruDefenceComponent_Statics::NewProp_blockMontage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruDefenceComponent_Statics::NewProp_isHittable_MetaData[] = {
		{ "Category", "Yoru | Hit" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruDefenceComponent.h" },
	};
#endif
	void Z_Construct_UClass_UYoruDefenceComponent_Statics::NewProp_isHittable_SetBit(void* Obj)
	{
		((UYoruDefenceComponent*)Obj)->isHittable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UYoruDefenceComponent_Statics::NewProp_isHittable = { "isHittable", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UYoruDefenceComponent), &Z_Construct_UClass_UYoruDefenceComponent_Statics::NewProp_isHittable_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruDefenceComponent_Statics::NewProp_isHittable_MetaData), Z_Construct_UClass_UYoruDefenceComponent_Statics::NewProp_isHittable_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruDefenceComponent_Statics::NewProp_isParrying_MetaData[] = {
		{ "Category", "Yoru | Hit" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruDefenceComponent.h" },
	};
#endif
	void Z_Construct_UClass_UYoruDefenceComponent_Statics::NewProp_isParrying_SetBit(void* Obj)
	{
		((UYoruDefenceComponent*)Obj)->isParrying = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UYoruDefenceComponent_Statics::NewProp_isParrying = { "isParrying", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UYoruDefenceComponent), &Z_Construct_UClass_UYoruDefenceComponent_Statics::NewProp_isParrying_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruDefenceComponent_Statics::NewProp_isParrying_MetaData), Z_Construct_UClass_UYoruDefenceComponent_Statics::NewProp_isParrying_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UYoruDefenceComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruDefenceComponent_Statics::NewProp_blockAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruDefenceComponent_Statics::NewProp_blockMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruDefenceComponent_Statics::NewProp_isHittable,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruDefenceComponent_Statics::NewProp_isParrying,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UYoruDefenceComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UYoruDefenceComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UYoruDefenceComponent_Statics::ClassParams = {
		&UYoruDefenceComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UYoruDefenceComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UYoruDefenceComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruDefenceComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UYoruDefenceComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruDefenceComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UYoruDefenceComponent()
	{
		if (!Z_Registration_Info_UClass_UYoruDefenceComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UYoruDefenceComponent.OuterSingleton, Z_Construct_UClass_UYoruDefenceComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UYoruDefenceComponent.OuterSingleton;
	}
	template<> LIESOFM_API UClass* StaticClass<UYoruDefenceComponent>()
	{
		return UYoruDefenceComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UYoruDefenceComponent);
	UYoruDefenceComponent::~UYoruDefenceComponent() {}
	struct Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruDefenceComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruDefenceComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UYoruDefenceComponent, UYoruDefenceComponent::StaticClass, TEXT("UYoruDefenceComponent"), &Z_Registration_Info_UClass_UYoruDefenceComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UYoruDefenceComponent), 2135766348U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruDefenceComponent_h_3303544142(TEXT("/Script/LiesOfM"),
		Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruDefenceComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruDefenceComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
