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
	void UYoruStatComponent::StaticRegisterNativesUYoruStatComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UYoruStatComponent);
	UClass* Z_Construct_UClass_UYoruStatComponent_NoRegister()
	{
		return UYoruStatComponent::StaticClass();
	}
	struct Z_Construct_UClass_UYoruStatComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UYoruStatComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UYoruBaseComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_LiesOfM,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruStatComponent_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruStatComponent_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "YoruPlayer/YoruStatComponent.h" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruStatComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UYoruStatComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UYoruStatComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UYoruStatComponent_Statics::ClassParams = {
		&UYoruStatComponent::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruStatComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UYoruStatComponent_Statics::Class_MetaDataParams)
	};
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
	UYoruStatComponent::UYoruStatComponent() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UYoruStatComponent);
	UYoruStatComponent::~UYoruStatComponent() {}
	struct Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruStatComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruStatComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UYoruStatComponent, UYoruStatComponent::StaticClass, TEXT("UYoruStatComponent"), &Z_Registration_Info_UClass_UYoruStatComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UYoruStatComponent), 2877841489U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruStatComponent_h_1786367004(TEXT("/Script/LiesOfM"),
		Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruStatComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruStatComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
