// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef DUNGEONCRAWLER_BaseCharacter_generated_h
#error "BaseCharacter.generated.h already included, missing '#pragma once' in BaseCharacter.h"
#endif
#define DUNGEONCRAWLER_BaseCharacter_generated_h

#define DungeonCrawler_Source_DungeonCrawler_BaseCharacter_h_11_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCheckHealth) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_f); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CheckHealth(Z_Param_f); \
		P_NATIVE_END; \
	}


#define DungeonCrawler_Source_DungeonCrawler_BaseCharacter_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCheckHealth) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_f); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CheckHealth(Z_Param_f); \
		P_NATIVE_END; \
	}


#define DungeonCrawler_Source_DungeonCrawler_BaseCharacter_h_11_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesABaseCharacter(); \
	friend DUNGEONCRAWLER_API class UClass* Z_Construct_UClass_ABaseCharacter(); \
	public: \
	DECLARE_CLASS(ABaseCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/DungeonCrawler"), NO_API) \
	DECLARE_SERIALIZER(ABaseCharacter) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define DungeonCrawler_Source_DungeonCrawler_BaseCharacter_h_11_INCLASS \
	private: \
	static void StaticRegisterNativesABaseCharacter(); \
	friend DUNGEONCRAWLER_API class UClass* Z_Construct_UClass_ABaseCharacter(); \
	public: \
	DECLARE_CLASS(ABaseCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/DungeonCrawler"), NO_API) \
	DECLARE_SERIALIZER(ABaseCharacter) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define DungeonCrawler_Source_DungeonCrawler_BaseCharacter_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABaseCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABaseCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABaseCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABaseCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABaseCharacter(ABaseCharacter&&); \
	NO_API ABaseCharacter(const ABaseCharacter&); \
public:


#define DungeonCrawler_Source_DungeonCrawler_BaseCharacter_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABaseCharacter(ABaseCharacter&&); \
	NO_API ABaseCharacter(const ABaseCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABaseCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABaseCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABaseCharacter)


#define DungeonCrawler_Source_DungeonCrawler_BaseCharacter_h_11_PRIVATE_PROPERTY_OFFSET
#define DungeonCrawler_Source_DungeonCrawler_BaseCharacter_h_8_PROLOG
#define DungeonCrawler_Source_DungeonCrawler_BaseCharacter_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	DungeonCrawler_Source_DungeonCrawler_BaseCharacter_h_11_PRIVATE_PROPERTY_OFFSET \
	DungeonCrawler_Source_DungeonCrawler_BaseCharacter_h_11_RPC_WRAPPERS \
	DungeonCrawler_Source_DungeonCrawler_BaseCharacter_h_11_INCLASS \
	DungeonCrawler_Source_DungeonCrawler_BaseCharacter_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define DungeonCrawler_Source_DungeonCrawler_BaseCharacter_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	DungeonCrawler_Source_DungeonCrawler_BaseCharacter_h_11_PRIVATE_PROPERTY_OFFSET \
	DungeonCrawler_Source_DungeonCrawler_BaseCharacter_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DungeonCrawler_Source_DungeonCrawler_BaseCharacter_h_11_INCLASS_NO_PURE_DECLS \
	DungeonCrawler_Source_DungeonCrawler_BaseCharacter_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID DungeonCrawler_Source_DungeonCrawler_BaseCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
