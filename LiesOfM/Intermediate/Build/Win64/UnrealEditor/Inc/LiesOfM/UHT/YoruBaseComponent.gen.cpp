// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LiesOfM/Public/YoruPlayer/YoruBaseComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYoruBaseComponent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	LIESOFM_API UClass* Z_Construct_UClass_AYoru_NoRegister();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruBaseComponent();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruBaseComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_LiesOfM();
// End Cross Module References
	void UYoruBaseComponent::StaticRegisterNativesUYoruBaseComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UYoruBaseComponent);
	UClass* Z_Construct_UClass_UYoruBaseComponent_NoRegister()
	{
		return UYoruBaseComponent::StaticClass();
	}
	struct Z_Construct_UClass_UYoruBaseComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_me_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_me;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UYoruBaseComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_LiesOfM,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruBaseComponent_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruBaseComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "YoruPlayer/YoruBaseComponent.h" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruBaseComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruBaseComponent_Statics::NewProp_me_MetaData[] = {
		{ "Category", "Yoru|Reference" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruBaseComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UYoruBaseComponent_Statics::NewProp_me = { "me", nullptr, (EPropertyFlags)0x0024080000020001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruBaseComponent, me), Z_Construct_UClass_AYoru_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruBaseComponent_Statics::NewProp_me_MetaData), Z_Construct_UClass_UYoruBaseComponent_Statics::NewProp_me_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UYoruBaseComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruBaseComponent_Statics::NewProp_me,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UYoruBaseComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UYoruBaseComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UYoruBaseComponent_Statics::ClassParams = {
		&UYoruBaseComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UYoruBaseComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UYoruBaseComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruBaseComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UYoruBaseComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruBaseComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UYoruBaseComponent()
	{
		if (!Z_Registration_Info_UClass_UYoruBaseComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UYoruBaseComponent.OuterSingleton, Z_Construct_UClass_UYoruBaseComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UYoruBaseComponent.OuterSingleton;
	}
	template<> LIESOFM_API UClass* StaticClass<UYoruBaseComponent>()
	{
		return UYoruBaseComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UYoruBaseComponent);
	UYoruBaseComponent::~UYoruBaseComponent() {}
	struct Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruBaseComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruBaseComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UYoruBaseComponent, UYoruBaseComponent::StaticClass, TEXT("UYoruBaseComponent"), &Z_Registration_Info_UClass_UYoruBaseComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UYoruBaseComponent), 1142545065U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruBaseComponent_h_4241021798(TEXT("/Script/LiesOfM"),
		Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruBaseComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruBaseComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
