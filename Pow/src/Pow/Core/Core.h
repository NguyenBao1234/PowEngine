//Copyright POW Game std

#pragma once
//
#ifdef POW_PLATFORM_WINDOWS
	#ifdef POW_BUILD_DLL
		#define POW_API __declspec(dllexport)
	#else
		#define POW_API __declspec(dllimport)
	#endif 
#else
	#error POW just supprt Window for now
#endif

#ifdef POW_ENABLE_ASSERT
	#define POW_ASSERT(x,...) {if(!(x)) {PE_ERROR("Assertion failed: {v}",__VA_ARGS__); __debugbreak(); }}
	#define POW_CORE_ASSERT(x,...) {if(!(x)) {PE_CORE_ERROR("Assertion failed: {v}",__VA_ARGS__); __debugbreak(); }}
#else
	#define POW_ASSERT(x,...)
	#define POW_CORE_ASSERT(x,...)
#endif // POW_ENABLE_ASSERT

//
#define BIT(x) (1 << x)