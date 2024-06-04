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
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
	ENGINE_API UClass* Z_Construct_UClass_UCharacterMovementComponent_NoRegister();
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_charMoveComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_charMoveComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_velocity_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_velocity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_moveSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_moveSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_isFalling_MetaData[];
#endif
		static void NewProp_isFalling_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isFalling;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_isPressedMovementInput_MetaData[];
#endif
		static void NewProp_isPressedMovementInput_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isPressedMovementInput;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_isSkipWalkStart_MetaData[];
#endif
		static void NewProp_isSkipWalkStart_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isSkipWalkStart;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_isFootUp_MetaData[];
#endif
		static void NewProp_isFootUp_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isFootUp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_isWalking_MetaData[];
#endif
		static void NewProp_isWalking_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isWalking;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_isCrouch_MetaData[];
#endif
		static void NewProp_isCrouch_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isCrouch;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_useWeaponState_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_useWeaponState;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_isLockon_MetaData[];
#endif
		static void NewProp_isLockon_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isLockon;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_angle_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_angle;
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_owner = { "owner", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruAnimInstance, owner), Z_Construct_UClass_AYoru_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_owner_MetaData), Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_owner_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_charMoveComp_MetaData[] = {
		{ "Category", "Yoru|Character" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAnimInstance.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_charMoveComp = { "charMoveComp", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruAnimInstance, charMoveComp), Z_Construct_UClass_UCharacterMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_charMoveComp_MetaData), Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_charMoveComp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_velocity_MetaData[] = {
		{ "Category", "Yoru|Character" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAnimInstance.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_velocity = { "velocity", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruAnimInstance, velocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_velocity_MetaData), Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_velocity_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_moveSpeed_MetaData[] = {
		{ "Category", "Yoru|Character" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAnimInstance.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_moveSpeed = { "moveSpeed", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruAnimInstance, moveSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_moveSpeed_MetaData), Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_moveSpeed_MetaData) };
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
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isFalling = { "isFalling", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UYoruAnimInstance), &Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isFalling_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isFalling_MetaData), Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isFalling_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isPressedMovementInput_MetaData[] = {
		{ "Category", "Yoru|Character" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isPressedMovementInput_SetBit(void* Obj)
	{
		((UYoruAnimInstance*)Obj)->isPressedMovementInput = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isPressedMovementInput = { "isPressedMovementInput", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UYoruAnimInstance), &Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isPressedMovementInput_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isPressedMovementInput_MetaData), Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isPressedMovementInput_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isSkipWalkStart_MetaData[] = {
		{ "Category", "Yoru|Character" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isSkipWalkStart_SetBit(void* Obj)
	{
		((UYoruAnimInstance*)Obj)->isSkipWalkStart = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isSkipWalkStart = { "isSkipWalkStart", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UYoruAnimInstance), &Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isSkipWalkStart_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isSkipWalkStart_MetaData), Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isSkipWalkStart_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isFootUp_MetaData[] = {
		{ "Category", "Yoru|Character" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isFootUp_SetBit(void* Obj)
	{
		((UYoruAnimInstance*)Obj)->isFootUp = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isFootUp = { "isFootUp", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UYoruAnimInstance), &Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isFootUp_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isFootUp_MetaData), Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isFootUp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isWalking_MetaData[] = {
		{ "Category", "Yoru|Character" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isWalking_SetBit(void* Obj)
	{
		((UYoruAnimInstance*)Obj)->isWalking = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isWalking = { "isWalking", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UYoruAnimInstance), &Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isWalking_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isWalking_MetaData), Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isWalking_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isCrouch_MetaData[] = {
		{ "Category", "Yoru|Character" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isCrouch_SetBit(void* Obj)
	{
		((UYoruAnimInstance*)Obj)->isCrouch = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isCrouch = { "isCrouch", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UYoruAnimInstance), &Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isCrouch_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isCrouch_MetaData), Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isCrouch_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_useWeaponState_MetaData[] = {
		{ "Category", "Yoru|Character" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAnimInstance.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_useWeaponState = { "useWeaponState", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruAnimInstance, useWeaponState), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_useWeaponState_MetaData), Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_useWeaponState_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isLockon_MetaData[] = {
		{ "Category", "Yoru|Character" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isLockon_SetBit(void* Obj)
	{
		((UYoruAnimInstance*)Obj)->isLockon = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isLockon = { "isLockon", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UYoruAnimInstance), &Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isLockon_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isLockon_MetaData), Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isLockon_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_angle_MetaData[] = {
		{ "Category", "Yoru|Character" },
		{ "ModuleRelativePath", "Public/YoruPlayer/YoruAnimInstance.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_angle = { "angle", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UYoruAnimInstance, angle), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_angle_MetaData), Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_angle_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UYoruAnimInstance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_owner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_charMoveComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_velocity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_moveSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isFalling,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isPressedMovementInput,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isSkipWalkStart,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isFootUp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isWalking,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isCrouch,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_useWeaponState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_isLockon,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UYoruAnimInstance_Statics::NewProp_angle,
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
		{ Z_Construct_UClass_UYoruAnimInstance, UYoruAnimInstance::StaticClass, TEXT("UYoruAnimInstance"), &Z_Registration_Info_UClass_UYoruAnimInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UYoruAnimInstance), 1331002896U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruAnimInstance_h_1963854326(TEXT("/Script/LiesOfM"),
		Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruAnimInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_YoruAnimInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
