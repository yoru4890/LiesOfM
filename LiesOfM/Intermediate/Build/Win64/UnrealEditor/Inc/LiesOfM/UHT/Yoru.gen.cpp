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
	DEFINE_FUNCTION(AYoru::execSetisPressedMovementInput)
	{
		P_GET_UBOOL(Z_Param_isPressed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetisPressedMovementInput(Z_Param_isPressed);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AYoru::execGetisPressedMovementInput)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetisPressedMovementInput();
		P_NATIVE_END;
	}
	void AYoru::StaticRegisterNativesAYoru()
	{
		UClass* Class = AYoru::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetisPressedMovementInput", &AYoru::execGetisPressedMovementInput },
			{ "SetisPressedMovementInput", &AYoru::execSetisPressedMovementInput },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics
	{
		struct Yoru_eventGetisPressedMovementInput_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Yoru_eventGetisPressedMovementInput_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Yoru_eventGetisPressedMovementInput_Parms), &Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AYoru, nullptr, "GetisPressedMovementInput", nullptr, nullptr, Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::PropPointers), sizeof(Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::Yoru_eventGetisPressedMovementInput_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::Function_MetaDataParams), Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::Yoru_eventGetisPressedMovementInput_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AYoru_GetisPressedMovementInput()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AYoru_GetisPressedMovementInput_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics
	{
		struct Yoru_eventSetisPressedMovementInput_Parms
		{
			bool isPressed;
		};
		static void NewProp_isPressed_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isPressed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::NewProp_isPressed_SetBit(void* Obj)
	{
		((Yoru_eventSetisPressedMovementInput_Parms*)Obj)->isPressed = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::NewProp_isPressed = { "isPressed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Yoru_eventSetisPressedMovementInput_Parms), &Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::NewProp_isPressed_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::NewProp_isPressed,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AYoru, nullptr, "SetisPressedMovementInput", nullptr, nullptr, Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::PropPointers), sizeof(Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::Yoru_eventSetisPressedMovementInput_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::Function_MetaDataParams), Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::Yoru_eventSetisPressedMovementInput_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AYoru_SetisPressedMovementInput()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AYoru_SetisPressedMovementInput_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AYoru);
	UClass* Z_Construct_UClass_AYoru_NoRegister()
	{
		return AYoru::StaticClass();
	}
	struct Z_Construct_UClass_AYoru_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
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
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_isPressedMovementInput_MetaData[];
#endif
		static void NewProp_isPressedMovementInput_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isPressedMovementInput;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AYoru_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_LiesOfM,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AYoru_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AYoru_GetisPressedMovementInput, "GetisPressedMovementInput" }, // 3997279820
		{ &Z_Construct_UFunction_AYoru_SetisPressedMovementInput, "SetisPressedMovementInput" }, // 2097408035
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::FuncInfo) < 2048);
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
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYoru_Statics::NewProp_isPressedMovementInput_MetaData[] = {
		{ "Category", "Yoru|Input" },
		{ "ModuleRelativePath", "Public/YoruPlayer/Yoru.h" },
	};
#endif
	void Z_Construct_UClass_AYoru_Statics::NewProp_isPressedMovementInput_SetBit(void* Obj)
	{
		((AYoru*)Obj)->isPressedMovementInput = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AYoru_Statics::NewProp_isPressedMovementInput = { "isPressedMovementInput", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AYoru), &Z_Construct_UClass_AYoru_Statics::NewProp_isPressedMovementInput_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYoru_Statics::NewProp_isPressedMovementInput_MetaData), Z_Construct_UClass_AYoru_Statics::NewProp_isPressedMovementInput_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AYoru_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_mainSpringArmComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_mainCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_moveComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_statComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYoru_Statics::NewProp_isPressedMovementInput,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AYoru_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AYoru>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AYoru_Statics::ClassParams = {
		&AYoru::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AYoru_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
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
		{ Z_Construct_UClass_AYoru, AYoru::StaticClass, TEXT("AYoru"), &Z_Registration_Info_UClass_AYoru, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AYoru), 2969594916U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_1429644036(TEXT("/Script/LiesOfM"),
		Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiesOfM_Source_LiesOfM_Public_YoruPlayer_Yoru_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
