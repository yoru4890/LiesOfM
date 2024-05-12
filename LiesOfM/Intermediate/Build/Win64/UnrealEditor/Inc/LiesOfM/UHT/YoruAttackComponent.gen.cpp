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
	LIESOFM_API UClass* Z_Construct_UClass_UYoruAttackComponent();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruAttackComponent_NoRegister();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruBaseComponent();
	UPackage* Z_Construct_UPackage__Script_LiesOfM();
// End Cross Module References
	void UYoruAttackComponent::StaticRegisterNativesUYoruAttackComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UYoruAttackComponent);
	UClass* Z_Construct_UClass_UYoruAttackComponent_NoRegister()
	{
		return UYoruAttackComponent::StaticClass();
	}
	struct Z_Construct_UClass_UYoruAttackComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UYoruAttackComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UYoruBaseComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_LiesOfM,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAttackComponent_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruAttackComponent_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "YoruPlayer/YoruAttackComponent.h" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAttackComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UYoruAttackComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UYoruAttackComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UYoruAttackComponent_Statics::ClassParams = {
		&UYoruAttackComponent::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAttackComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UYoruAttackComponent_Statics::Class_MetaDataParams)
	};
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
	UYoruAttackComponent::UYoruAttackComponent() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UYoruAttackComponent);
	UYoruAttackComponent::~UYoruAttackComponent() {}
	struct Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruAttackComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruAttackComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UYoruAttackComponent, UYoruAttackComponent::StaticClass, TEXT("UYoruAttackComponent"), &Z_Registration_Info_UClass_UYoruAttackComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UYoruAttackComponent), 637369708U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruAttackComponent_h_1627415665(TEXT("/Script/LiesOfM"),
		Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruAttackComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruAttackComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
