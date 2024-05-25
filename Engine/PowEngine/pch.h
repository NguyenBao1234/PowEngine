#pragma once

#include<memory>
#include<stdint.h>
#include<set>
#include<random>
#include<limits>
#include<vector>
#include<string>
#include<bitset>
#include<cassert>
#include<assert.h>
#include<sstream>
#include<istream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<functional>
#include<unordered_map>
#include<map>
#include<stack>


template<typename T> using Shared = std::shared_ptr<T>;
template<typename T> using Unique = std::unique_ptr <T>;

#if ON_POW_ENGINE
	#if DYNAMIC_BUILD
		#ifdef _MCS_VER
			#define POW_API __declspec(dllexport)
		#else
			#define POW_API __attribute__((visibility("default")))
		#endif

	#else
		#define POW_API
	#endif
#else
	#if DYNAMIC_IMPORT
		#ifdef _MCS_VER
			#define POW_API __declspec(dllexport)
		#else
			#define POW_API __attribute__((visibility("default")))
		#endif

	#else
		#define POW_API
	#endif

#endif

//Runtime assert
#define POW_ASSERT assert

//Static assert
#if defined(__clang__)|| defined (__gcc__)
	#define POW_STATIC_ASSERT _Static_assert
#else
	#define POW_STATIC_ASSERT static_assert
#endif

#if defined(__clang__)|| defined (__gcc__)
	#define POW_FORCE_INLINE __attribute__((always_inline)) inline
	#define POW_NOINLINE __attribute__((noinline))
#elif defined (__MCS_VER)
	#define POW_FORCE_INLINE __forceinline
	#define POW_NOINLINE __declspec(noinline)
#else
	#define POW_FORCE_INLINE inline
	#define POW_NOINLINE
#endif

//
#define POW_FREE_MEMORY(memory) if (memory!=nullptr){ delete memory; memory = nullptr;}
//
#define BIND_EVENT_FUNCTION(function) [this](auto&... args) -> decltype(auto)\
	{ return this->function(std::forward<decltype(args)>(args)...); }
