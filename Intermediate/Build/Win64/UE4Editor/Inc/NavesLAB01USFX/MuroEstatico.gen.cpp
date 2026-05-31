// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NavesLAB01USFX/MuroEstatico.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMuroEstatico() {}
// Cross Module References
	NAVESLAB01USFX_API UClass* Z_Construct_UClass_AMuroEstatico_NoRegister();
	NAVESLAB01USFX_API UClass* Z_Construct_UClass_AMuroEstatico();
	NAVESLAB01USFX_API UClass* Z_Construct_UClass_AMuro();
	UPackage* Z_Construct_UPackage__Script_NavesLAB01USFX();
// End Cross Module References
	void AMuroEstatico::StaticRegisterNativesAMuroEstatico()
	{
	}
	UClass* Z_Construct_UClass_AMuroEstatico_NoRegister()
	{
		return AMuroEstatico::StaticClass();
	}
	struct Z_Construct_UClass_AMuroEstatico_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMuroEstatico_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AMuro,
		(UObject* (*)())Z_Construct_UPackage__Script_NavesLAB01USFX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMuroEstatico_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MuroEstatico.h" },
		{ "ModuleRelativePath", "MuroEstatico.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMuroEstatico_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMuroEstatico>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMuroEstatico_Statics::ClassParams = {
		&AMuroEstatico::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AMuroEstatico_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMuroEstatico_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMuroEstatico()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMuroEstatico_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMuroEstatico, 3093615170);
	template<> NAVESLAB01USFX_API UClass* StaticClass<AMuroEstatico>()
	{
		return AMuroEstatico::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMuroEstatico(Z_Construct_UClass_AMuroEstatico, &AMuroEstatico::StaticClass, TEXT("/Script/NavesLAB01USFX"), TEXT("AMuroEstatico"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMuroEstatico);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
