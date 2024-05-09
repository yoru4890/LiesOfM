// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LiesOfM/Public/YoruPlayer/Yoru.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYoru() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	LIESOFM_API UClass* Z_Construct_UClass_AYoru();
	LIESOFM_API UClass* Z_Construct_UClass_AYoru_NoRegister();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruMoveComponent_NoRegister();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruStatComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_LiesOfM();
// End Cross Module References
	void AYoru::StaticRegisterNativesAYoru()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AYoru);
	UClass* Z_Construct_UClass_AYoru_NoRegister()
	{
		return AYoru::StaticClass();
	}
	struct Z_Construct_UClass_AYoru_Statics
	{
		static UObject* (*const DependentSingletons[])();
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
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AYoru_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_LiesOfM,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::DependentSingletons) < 16);
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
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_mainSpringArmComp = { "mainSpringArmComp", nullptr, (EPropertyFlags)0x00440000000a0009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYoru, mainSpringArmComp), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::NewProp_mainSpringArmComp_MetaData), Z_Construct_UClass_AYoru_Statics::NewProp_mainSpringArmComp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYoru_Statics::NewProp_mainCamera_MetaData[] = {
		{ "Category", "Yoru|Compoent" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_mainCamera = { "mainCamera", nullptr, (EPropertyFlags)0x00440000000a0009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYoru, mainCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::NewProp_mainCamera_MetaData), Z_Construct_UClass_AYoru_Statics::NewProp_mainCamera_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYoru_Statics::NewProp_moveComp_MetaData[] = {
		{ "Category", "Yoru|Component" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_moveComp = { "moveComp", nullptr, (EPropertyFlags)0x00440000000a0009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYoru, moveComp), Z_Construct_UClass_UYoruMoveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::NewProp_moveComp_MetaData), Z_Construct_UClass_AYoru_Statics::NewProp_moveComp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYoru_Statics::NewProp_statComp_MetaData[] = {
		{ "Category", "Yoru|Component" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_statComp = { "statComp", nullptr, (EPropertyFlags)0x00440000000a0009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AYoru, statComp), Z_Construct_UClass_UYoruStatComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::NewProp_statComp_MetaData), Z_Construct_UClass_AYoru_Statics::NewProp_statComp_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AYoru_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_mainSpringArmComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_mainCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_moveComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_statComp,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AYoru_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AYoru>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AYoru_Statics::ClassParams = {
		&AYoru::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AYoru_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::PropPointers),
		0,
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
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AYoru, AYoru::StaticClass, TEXT("AYoru"), &Z_Registration_Info_UClass_AYoru, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AYoru), 460159922U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_3656984600(TEXT("/Script/LiesOfM"),
		Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
