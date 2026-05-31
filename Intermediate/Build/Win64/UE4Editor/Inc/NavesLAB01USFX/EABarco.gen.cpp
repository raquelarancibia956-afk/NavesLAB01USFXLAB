// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NavesLAB01USFX/EABarco.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEABarco() {}
// Cross Module References
	NAVESLAB01USFX_API UClass* Z_Construct_UClass_AEABarco_NoRegister();
	NAVESLAB01USFX_API UClass* Z_Construct_UClass_AEABarco();
	NAVESLAB01USFX_API UClass* Z_Construct_UClass_AEnemigoAcuatico();
	UPackage* Z_Construct_UPackage__Script_NavesLAB01USFX();
// End Cross Module References
	void AEABarco::StaticRegisterNativesAEABarco()
	{
	}
	UClass* Z_Construct_UClass_AEABarco_NoRegister()
	{
		return AEABarco::StaticClass();
	}
	struct Z_Construct_UClass_AEABarco_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEABarco_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AEnemigoAcuatico,
		(UObject* (*)())Z_Construct_UPackage__Script_NavesLAB01USFX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEABarco_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "EABarco.h" },
		{ "ModuleRelativePath", "EABarco.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEABarco_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEABarco>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEABarco_Statics::ClassParams = {
		&AEABarco::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEABarco_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEABarco_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEABarco()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEABarco_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEABarco, 1692482633);
	template<> NAVESLAB01USFX_API UClass* StaticClass<AEABarco>()
	{
		return AEABarco::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEABarco(Z_Construct_UClass_AEABarco, &AEABarco::StaticClass, TEXT("/Script/NavesLAB01USFX"), TEXT("AEABarco"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEABarco);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
