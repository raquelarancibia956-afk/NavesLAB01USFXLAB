// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NavesLAB01USFX/NavesLAB01USFXGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNavesLAB01USFXGameMode() {}
// Cross Module References
	NAVESLAB01USFX_API UEnum* Z_Construct_UEnum_NavesLAB01USFX_ECuadrilla();
	UPackage* Z_Construct_UPackage__Script_NavesLAB01USFX();
	NAVESLAB01USFX_API UClass* Z_Construct_UClass_ANavesLAB01USFXGameMode_NoRegister();
	NAVESLAB01USFX_API UClass* Z_Construct_UClass_ANavesLAB01USFXGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	NAVESLAB01USFX_API UClass* Z_Construct_UClass_AEnemigo_NoRegister();
	NAVESLAB01USFX_API UClass* Z_Construct_UClass_AMuro_NoRegister();
// End Cross Module References
	static UEnum* ECuadrilla_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_NavesLAB01USFX_ECuadrilla, Z_Construct_UPackage__Script_NavesLAB01USFX(), TEXT("ECuadrilla"));
		}
		return Singleton;
	}
	template<> NAVESLAB01USFX_API UEnum* StaticEnum<ECuadrilla>()
	{
		return ECuadrilla_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ECuadrilla(ECuadrilla_StaticEnum, TEXT("/Script/NavesLAB01USFX"), TEXT("ECuadrilla"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_NavesLAB01USFX_ECuadrilla_Hash() { return 153625439U; }
	UEnum* Z_Construct_UEnum_NavesLAB01USFX_ECuadrilla()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_NavesLAB01USFX();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ECuadrilla"), 0, Get_Z_Construct_UEnum_NavesLAB01USFX_ECuadrilla_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ECuadrilla::Primera", (int64)ECuadrilla::Primera },
				{ "ECuadrilla::Segunda", (int64)ECuadrilla::Segunda },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "NavesLAB01USFXGameMode.h" },
				{ "Primera.Name", "ECuadrilla::Primera" },
				{ "Segunda.Name", "ECuadrilla::Segunda" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_NavesLAB01USFX,
				nullptr,
				"ECuadrilla",
				"ECuadrilla",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	void ANavesLAB01USFXGameMode::StaticRegisterNativesANavesLAB01USFXGameMode()
	{
	}
	UClass* Z_Construct_UClass_ANavesLAB01USFXGameMode_NoRegister()
	{
		return ANavesLAB01USFXGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Cuadrilla1_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Cuadrilla1_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Cuadrilla1;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Cuadrilla2_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Cuadrilla2_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Cuadrilla2;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MurosArray_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MurosArray_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_MurosArray;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_CuadrillaActual_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CuadrillaActual_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_CuadrillaActual;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_NavesLAB01USFX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "NavesLAB01USFXGameMode.h" },
		{ "ModuleRelativePath", "NavesLAB01USFXGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_Cuadrilla1_Inner = { "Cuadrilla1", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AEnemigo_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_Cuadrilla1_MetaData[] = {
		{ "Comment", "// ===== CUADRILLAS =====\n" },
		{ "ModuleRelativePath", "NavesLAB01USFXGameMode.h" },
		{ "ToolTip", "===== CUADRILLAS =====" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_Cuadrilla1 = { "Cuadrilla1", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ANavesLAB01USFXGameMode, Cuadrilla1), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_Cuadrilla1_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_Cuadrilla1_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_Cuadrilla2_Inner = { "Cuadrilla2", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AEnemigo_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_Cuadrilla2_MetaData[] = {
		{ "ModuleRelativePath", "NavesLAB01USFXGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_Cuadrilla2 = { "Cuadrilla2", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ANavesLAB01USFXGameMode, Cuadrilla2), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_Cuadrilla2_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_Cuadrilla2_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_MurosArray_Inner = { "MurosArray", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AMuro_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_MurosArray_MetaData[] = {
		{ "ModuleRelativePath", "NavesLAB01USFXGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_MurosArray = { "MurosArray", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ANavesLAB01USFXGameMode, MurosArray), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_MurosArray_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_MurosArray_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_CuadrillaActual_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_CuadrillaActual_MetaData[] = {
		{ "ModuleRelativePath", "NavesLAB01USFXGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_CuadrillaActual = { "CuadrillaActual", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ANavesLAB01USFXGameMode, CuadrillaActual), Z_Construct_UEnum_NavesLAB01USFX_ECuadrilla, METADATA_PARAMS(Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_CuadrillaActual_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_CuadrillaActual_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_Cuadrilla1_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_Cuadrilla1,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_Cuadrilla2_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_Cuadrilla2,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_MurosArray_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_MurosArray,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_CuadrillaActual_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::NewProp_CuadrillaActual,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANavesLAB01USFXGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::ClassParams = {
		&ANavesLAB01USFXGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::PropPointers),
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ANavesLAB01USFXGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ANavesLAB01USFXGameMode, 1795084352);
	template<> NAVESLAB01USFX_API UClass* StaticClass<ANavesLAB01USFXGameMode>()
	{
		return ANavesLAB01USFXGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANavesLAB01USFXGameMode(Z_Construct_UClass_ANavesLAB01USFXGameMode, &ANavesLAB01USFXGameMode::StaticClass, TEXT("/Script/NavesLAB01USFX"), TEXT("ANavesLAB01USFXGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANavesLAB01USFXGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
