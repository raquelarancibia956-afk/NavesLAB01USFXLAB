// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NavesLAB01USFX/BloqueCamino.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBloqueCamino() {}
// Cross Module References
	NAVESLAB01USFX_API UClass* Z_Construct_UClass_ABloqueCamino_NoRegister();
	NAVESLAB01USFX_API UClass* Z_Construct_UClass_ABloqueCamino();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_NavesLAB01USFX();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void ABloqueCamino::StaticRegisterNativesABloqueCamino()
	{
	}
	UClass* Z_Construct_UClass_ABloqueCamino_NoRegister()
	{
		return ABloqueCamino::StaticClass();
	}
	struct Z_Construct_UClass_ABloqueCamino_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Malla_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Malla;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PosicionX_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_PosicionX;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PosicionY_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_PosicionY;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bEsCamino_MetaData[];
#endif
		static void NewProp_bEsCamino_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bEsCamino;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABloqueCamino_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_NavesLAB01USFX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABloqueCamino_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BloqueCamino.h" },
		{ "ModuleRelativePath", "BloqueCamino.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABloqueCamino_Statics::NewProp_Malla_MetaData[] = {
		{ "Category", "BloqueCamino" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "BloqueCamino.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABloqueCamino_Statics::NewProp_Malla = { "Malla", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABloqueCamino, Malla), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABloqueCamino_Statics::NewProp_Malla_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueCamino_Statics::NewProp_Malla_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABloqueCamino_Statics::NewProp_PosicionX_MetaData[] = {
		{ "Category", "BloqueCamino" },
		{ "ModuleRelativePath", "BloqueCamino.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ABloqueCamino_Statics::NewProp_PosicionX = { "PosicionX", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABloqueCamino, PosicionX), METADATA_PARAMS(Z_Construct_UClass_ABloqueCamino_Statics::NewProp_PosicionX_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueCamino_Statics::NewProp_PosicionX_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABloqueCamino_Statics::NewProp_PosicionY_MetaData[] = {
		{ "Category", "BloqueCamino" },
		{ "Comment", "// Posicion en la cuadricula X\n" },
		{ "ModuleRelativePath", "BloqueCamino.h" },
		{ "ToolTip", "Posicion en la cuadricula X" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ABloqueCamino_Statics::NewProp_PosicionY = { "PosicionY", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABloqueCamino, PosicionY), METADATA_PARAMS(Z_Construct_UClass_ABloqueCamino_Statics::NewProp_PosicionY_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueCamino_Statics::NewProp_PosicionY_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABloqueCamino_Statics::NewProp_bEsCamino_MetaData[] = {
		{ "Category", "BloqueCamino" },
		{ "Comment", "// Posicion en la cuadricula Y\n" },
		{ "ModuleRelativePath", "BloqueCamino.h" },
		{ "ToolTip", "Posicion en la cuadricula Y" },
	};
#endif
	void Z_Construct_UClass_ABloqueCamino_Statics::NewProp_bEsCamino_SetBit(void* Obj)
	{
		((ABloqueCamino*)Obj)->bEsCamino = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ABloqueCamino_Statics::NewProp_bEsCamino = { "bEsCamino", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ABloqueCamino), &Z_Construct_UClass_ABloqueCamino_Statics::NewProp_bEsCamino_SetBit, METADATA_PARAMS(Z_Construct_UClass_ABloqueCamino_Statics::NewProp_bEsCamino_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueCamino_Statics::NewProp_bEsCamino_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABloqueCamino_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABloqueCamino_Statics::NewProp_Malla,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABloqueCamino_Statics::NewProp_PosicionX,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABloqueCamino_Statics::NewProp_PosicionY,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABloqueCamino_Statics::NewProp_bEsCamino,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABloqueCamino_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABloqueCamino>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABloqueCamino_Statics::ClassParams = {
		&ABloqueCamino::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ABloqueCamino_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueCamino_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABloqueCamino_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueCamino_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABloqueCamino()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABloqueCamino_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABloqueCamino, 2943834062);
	template<> NAVESLAB01USFX_API UClass* StaticClass<ABloqueCamino>()
	{
		return ABloqueCamino::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABloqueCamino(Z_Construct_UClass_ABloqueCamino, &ABloqueCamino::StaticClass, TEXT("/Script/NavesLAB01USFX"), TEXT("ABloqueCamino"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABloqueCamino);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
