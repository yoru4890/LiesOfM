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
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruBaseComponent();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruMoveComponent();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruMoveComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_LiesOfM();
// End Cross Module References
	void UYoruMoveComponent::StaticRegisterNativesUYoruMoveComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UYoruMoveComponent);
	UClass* Z_Construct_UClass_UYoruMoveComponent_NoRegister()
	{
		return UYoruMoveComponent::StaticClass();
	}
	struct Z_Construct_UClass_UYoruMoveComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
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
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UYoruMoveComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UYoruBaseComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_LiesOfM,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruMoveComponent_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruMoveComponent_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "YoruPlayer/YoruMoveComponent.h" },
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
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UYoruMoveComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_defaultInputMappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruMoveComponent_Statics::NewProp_moveAction,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UYoruMoveComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UYoruMoveComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UYoruMoveComponent_Statics::ClassParams = {
		&UYoruMoveComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UYoruMoveComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
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
		{ Z_Construct_UClass_UYoruMoveComponent, UYoruMoveComponent::StaticClass, TEXT("UYoruMoveComponent"), &Z_Registration_Info_UClass_UYoruMoveComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UYoruMoveComponent), 602281307U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_424235257(TEXT("/Script/LiesOfM"),
		Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruMoveComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
