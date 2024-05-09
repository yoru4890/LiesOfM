// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LiesOfM/Public/YoruPlayer/YoruAnimInstance.h"
#include "../../Source/Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYoruAnimInstance() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
	LIESOFM_API UClass* Z_Construct_UClass_AYoru_NoRegister();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruAnimInstance();
	LIESOFM_API UClass* Z_Construct_UClass_UYoruAnimInstance_NoRegister();
	UPackage* Z_Construct_UPackage__Script_LiesOfM();
// End Cross Module References
	void UYoruAnimInstance::StaticRegisterNativesUYoruAnimInstance()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UYoruAnimInstance);
	UClass* Z_Construct_UClass_UYoruAnimInstance_NoRegister()
	{
		return UYoruAnimInstance::StaticClass();
	}
	struct Z_Construct_UClass_UYoruAnimInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_owner_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_owner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_moveSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_moveSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_isFalling_MetaData[];
#endif
		static void NewProp_isFalling_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isFalling;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UYoruAnimInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_LiesOfM,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAnimInstance_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruAnimInstance_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "YoruPlayer/YoruAnimInstance.h" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAnimInstance.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_owner_MetaData[] = {
		{ "Category", "Yoru|Character" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAnimInstance.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_owner = { "owner", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruAnimInstance, owner), Z_Construct_UClass_AYoru_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_owner_MetaData), Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_owner_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_moveSpeed_MetaData[] = {
		{ "Category", "Yoru|Character" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAnimInstance.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_moveSpeed = { "moveSpeed", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruAnimInstance, moveSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_moveSpeed_MetaData), Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_moveSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isFalling_MetaData[] = {
		{ "Category", "Yoru|Character" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isFalling_SetBit(void* Obj)
	{
		((UYoruAnimInstance*)Obj)->isFalling = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isFalling = { "isFalling", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UYoruAnimInstance), &Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isFalling_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isFalling_MetaData), Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isFalling_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UYoruAnimInstance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_owner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_moveSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isFalling,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UYoruAnimInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UYoruAnimInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UYoruAnimInstance_Statics::ClassParams = {
		&UYoruAnimInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UYoruAnimInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAnimInstance_Statics::PropPointers),
		0,
		0x009000A8u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAnimInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UYoruAnimInstance_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAnimInstance_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UYoruAnimInstance()
	{
		if (!Z_Registration_Info_UClass_UYoruAnimInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UYoruAnimInstance.OuterSingleton, Z_Construct_UClass_UYoruAnimInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UYoruAnimInstance.OuterSingleton;
	}
	template<> LIESOFM_API UClass* StaticClass<UYoruAnimInstance>()
	{
		return UYoruAnimInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UYoruAnimInstance);
	UYoruAnimInstance::~UYoruAnimInstance() {}
	struct Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruAnimInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruAnimInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UYoruAnimInstance, UYoruAnimInstance::StaticClass, TEXT("UYoruAnimInstance"), &Z_Registration_Info_UClass_UYoruAnimInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UYoruAnimInstance), 1766642751U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruAnimInstance_h_4238959997(TEXT("/Script/LiesOfM"),
		Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruAnimInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruAnimInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
