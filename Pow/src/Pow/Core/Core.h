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

//
#define BIT(x) (1 << x)