// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NavesLAB01USFX/FacadeJuego.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFacadeJuego() {}
// Cross Module References
	NAVESLAB01USFX_API UClass* Z_Construct_UClass_AFacadeJuego_NoRegister();
	NAVESLAB01USFX_API UClass* Z_Construct_UClass_AFacadeJuego();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_NavesLAB01USFX();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	NAVESLAB01USFX_API UClass* Z_Construct_UClass_AEnemigo_NoRegister();
// End Cross Module References
	void AFacadeJuego::StaticRegisterNativesAFacadeJuego()
	{
	}
	UClass* Z_Construct_UClass_AFacadeJuego_NoRegister()
	{
		return AFacadeJuego::StaticClass();
	}
	struct Z_Construct_UClass_AFacadeJuego_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ClasesEnemigos_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ClasesEnemigos_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ClasesEnemigos;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFacadeJuego_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_NavesLAB01USFX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFacadeJuego_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "FacadeJuego.h" },
		{ "ModuleRelativePath", "FacadeJuego.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AFacadeJuego_Statics::NewProp_ClasesEnemigos_Inner = { "ClasesEnemigos", nullptr, (EPropertyFlags)0x0004000000000000, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AEnemigo_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFacadeJuego_Statics::NewProp_ClasesEnemigos_MetaData[] = {
		{ "ModuleRelativePath", "FacadeJuego.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AFacadeJuego_Statics::NewProp_ClasesEnemigos = { "ClasesEnemigos", nullptr, (EPropertyFlags)0x0014000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFacadeJuego, ClasesEnemigos), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AFacadeJuego_Statics::NewProp_ClasesEnemigos_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFacadeJuego_Statics::NewProp_ClasesEnemigos_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFacadeJuego_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFacadeJuego_Statics::NewProp_ClasesEnemigos_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFacadeJuego_Statics::NewProp_ClasesEnemigos,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFacadeJuego_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFacadeJuego>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFacadeJuego_Statics::ClassParams = {
		&AFacadeJuego::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AFacadeJuego_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AFacadeJuego_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AFacadeJuego_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFacadeJuego_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFacadeJuego()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFacadeJuego_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFacadeJuego, 800451661);
	template<> NAVESLAB01USFX_API UClass* StaticClass<AFacadeJuego>()
	{
		return AFacadeJuego::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFacadeJuego(Z_Construct_UClass_AFacadeJuego, &AFacadeJuego::StaticClass, TEXT("/Script/NavesLAB01USFX"), TEXT("AFacadeJuego"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFacadeJuego);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
