// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NavesLAB01USFX/Enemigo.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemigo() {}
// Cross Module References
	NAVESLAB01USFX_API UClass* Z_Construct_UClass_AEnemigo_NoRegister();
	NAVESLAB01USFX_API UClass* Z_Construct_UClass_AEnemigo();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_NavesLAB01USFX();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	NAVESLAB01USFX_API UClass* Z_Construct_UClass_ANavesLAB01USFXPawn_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AEnemigo::execOnHit)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp);
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse);
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Result);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Result);
		P_NATIVE_END;
	}
	void AEnemigo::StaticRegisterNativesAEnemigo()
	{
		UClass* Class = AEnemigo::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnHit", &AEnemigo::execOnHit },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AEnemigo_OnHit_Statics
	{
		struct Enemigo_eventOnHit_Parms
		{
			UPrimitiveComponent* HitComp;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			FVector NormalImpulse;
			FHitResult Result;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HitComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HitComp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_NormalImpulse;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Result_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Result;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemigo_OnHit_Statics::NewProp_HitComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEnemigo_OnHit_Statics::NewProp_HitComp = { "HitComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Enemigo_eventOnHit_Parms, HitComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AEnemigo_OnHit_Statics::NewProp_HitComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemigo_OnHit_Statics::NewProp_HitComp_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEnemigo_OnHit_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Enemigo_eventOnHit_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemigo_OnHit_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEnemigo_OnHit_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Enemigo_eventOnHit_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AEnemigo_OnHit_Statics::NewProp_OtherComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemigo_OnHit_Statics::NewProp_OtherComp_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEnemigo_OnHit_Statics::NewProp_NormalImpulse = { "NormalImpulse", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Enemigo_eventOnHit_Parms, NormalImpulse), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemigo_OnHit_Statics::NewProp_Result_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEnemigo_OnHit_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010008008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Enemigo_eventOnHit_Parms, Result), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_AEnemigo_OnHit_Statics::NewProp_Result_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemigo_OnHit_Statics::NewProp_Result_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEnemigo_OnHit_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemigo_OnHit_Statics::NewProp_HitComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemigo_OnHit_Statics::NewProp_OtherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemigo_OnHit_Statics::NewProp_OtherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemigo_OnHit_Statics::NewProp_NormalImpulse,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemigo_OnHit_Statics::NewProp_Result,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemigo_OnHit_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Enemigo.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemigo_OnHit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemigo, nullptr, "OnHit", nullptr, nullptr, sizeof(Enemigo_eventOnHit_Parms), Z_Construct_UFunction_AEnemigo_OnHit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemigo_OnHit_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C80400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AEnemigo_OnHit_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemigo_OnHit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AEnemigo_OnHit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AEnemigo_OnHit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AEnemigo_NoRegister()
	{
		return AEnemigo::StaticClass();
	}
	struct Z_Construct_UClass_AEnemigo_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MallaEnemigo_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MallaEnemigo;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VidaMaxima_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_VidaMaxima;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VidaActual_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_VidaActual;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Velocidad_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Velocidad;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Dano_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Dano;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PosicionInicial_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PosicionInicial;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PuntosRuta_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PuntosRuta_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_PuntosRuta;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IndicePuntoRutaActual_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_IndicePuntoRutaActual;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Tolerancia_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Tolerancia;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Jugador_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Jugador;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemigo_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_NavesLAB01USFX,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AEnemigo_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AEnemigo_OnHit, "OnHit" }, // 4127414301
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemigo_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Enemigo.h" },
		{ "ModuleRelativePath", "Enemigo.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemigo_Statics::NewProp_MallaEnemigo_MetaData[] = {
		{ "Category", "Colision" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Enemigo.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemigo_Statics::NewProp_MallaEnemigo = { "MallaEnemigo", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemigo, MallaEnemigo), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemigo_Statics::NewProp_MallaEnemigo_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigo_Statics::NewProp_MallaEnemigo_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemigo_Statics::NewProp_VidaMaxima_MetaData[] = {
		{ "Category", "Vida" },
		{ "ModuleRelativePath", "Enemigo.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEnemigo_Statics::NewProp_VidaMaxima = { "VidaMaxima", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemigo, VidaMaxima), METADATA_PARAMS(Z_Construct_UClass_AEnemigo_Statics::NewProp_VidaMaxima_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigo_Statics::NewProp_VidaMaxima_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemigo_Statics::NewProp_VidaActual_MetaData[] = {
		{ "Category", "Vida" },
		{ "ModuleRelativePath", "Enemigo.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEnemigo_Statics::NewProp_VidaActual = { "VidaActual", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemigo, VidaActual), METADATA_PARAMS(Z_Construct_UClass_AEnemigo_Statics::NewProp_VidaActual_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigo_Statics::NewProp_VidaActual_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemigo_Statics::NewProp_Velocidad_MetaData[] = {
		{ "Category", "Movimiento" },
		{ "ModuleRelativePath", "Enemigo.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEnemigo_Statics::NewProp_Velocidad = { "Velocidad", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemigo, Velocidad), METADATA_PARAMS(Z_Construct_UClass_AEnemigo_Statics::NewProp_Velocidad_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigo_Statics::NewProp_Velocidad_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemigo_Statics::NewProp_Dano_MetaData[] = {
		{ "Category", "Stats" },
		{ "ModuleRelativePath", "Enemigo.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEnemigo_Statics::NewProp_Dano = { "Dano", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemigo, Dano), METADATA_PARAMS(Z_Construct_UClass_AEnemigo_Statics::NewProp_Dano_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigo_Statics::NewProp_Dano_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemigo_Statics::NewProp_PosicionInicial_MetaData[] = {
		{ "ModuleRelativePath", "Enemigo.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEnemigo_Statics::NewProp_PosicionInicial = { "PosicionInicial", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemigo, PosicionInicial), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AEnemigo_Statics::NewProp_PosicionInicial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigo_Statics::NewProp_PosicionInicial_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEnemigo_Statics::NewProp_PuntosRuta_Inner = { "PuntosRuta", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemigo_Statics::NewProp_PuntosRuta_MetaData[] = {
		{ "ModuleRelativePath", "Enemigo.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AEnemigo_Statics::NewProp_PuntosRuta = { "PuntosRuta", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemigo, PuntosRuta), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AEnemigo_Statics::NewProp_PuntosRuta_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigo_Statics::NewProp_PuntosRuta_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemigo_Statics::NewProp_IndicePuntoRutaActual_MetaData[] = {
		{ "ModuleRelativePath", "Enemigo.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AEnemigo_Statics::NewProp_IndicePuntoRutaActual = { "IndicePuntoRutaActual", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemigo, IndicePuntoRutaActual), METADATA_PARAMS(Z_Construct_UClass_AEnemigo_Statics::NewProp_IndicePuntoRutaActual_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigo_Statics::NewProp_IndicePuntoRutaActual_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemigo_Statics::NewProp_Tolerancia_MetaData[] = {
		{ "ModuleRelativePath", "Enemigo.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEnemigo_Statics::NewProp_Tolerancia = { "Tolerancia", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemigo, Tolerancia), METADATA_PARAMS(Z_Construct_UClass_AEnemigo_Statics::NewProp_Tolerancia_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigo_Statics::NewProp_Tolerancia_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemigo_Statics::NewProp_Jugador_MetaData[] = {
		{ "ModuleRelativePath", "Enemigo.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemigo_Statics::NewProp_Jugador = { "Jugador", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemigo, Jugador), Z_Construct_UClass_ANavesLAB01USFXPawn_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemigo_Statics::NewProp_Jugador_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigo_Statics::NewProp_Jugador_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEnemigo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigo_Statics::NewProp_MallaEnemigo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigo_Statics::NewProp_VidaMaxima,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigo_Statics::NewProp_VidaActual,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigo_Statics::NewProp_Velocidad,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigo_Statics::NewProp_Dano,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigo_Statics::NewProp_PosicionInicial,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigo_Statics::NewProp_PuntosRuta_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigo_Statics::NewProp_PuntosRuta,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigo_Statics::NewProp_IndicePuntoRutaActual,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigo_Statics::NewProp_Tolerancia,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigo_Statics::NewProp_Jugador,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemigo_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemigo>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEnemigo_Statics::ClassParams = {
		&AEnemigo::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AEnemigo_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigo_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEnemigo_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigo_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEnemigo()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEnemigo_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEnemigo, 1971791243);
	template<> NAVESLAB01USFX_API UClass* StaticClass<AEnemigo>()
	{
		return AEnemigo::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEnemigo(Z_Construct_UClass_AEnemigo, &AEnemigo::StaticClass, TEXT("/Script/NavesLAB01USFX"), TEXT("AEnemigo"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemigo);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
