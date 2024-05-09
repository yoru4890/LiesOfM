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
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "YoruPlayer/YoruDefenceComponent.h" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruDefenceComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UYoruDefenceComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UYoruDefenceComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UYoruDefenceComponent_Statics::ClassParams = {
		&UYoruDefenceComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruDefenceComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UYoruDefenceComponent_Statics::Class_MetaDataParams)
	};
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
	UYoruDefenceComponent::UYoruDefenceComponent() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UYoruDefenceComponent);
	UYoruDefenceComponent::~UYoruDefenceComponent() {}
	struct Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruDefenceComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruDefenceComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UYoruDefenceComponent, UYoruDefenceComponent::StaticClass, TEXT("UYoruDefenceComponent"), &Z_Registration_Info_UClass_UYoruDefenceComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UYoruDefenceComponent), 3613512112U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruDefenceComponent_h_3484159683(TEXT("/Script/LiesOfM"),
		Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruDefenceComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruDefenceComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
