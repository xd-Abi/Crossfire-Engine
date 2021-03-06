#pragma once

#include "Base.h"

#ifdef CF_ENABLE_ASSERTS
	#define CF_ASSERT(x, ...) { if(!(x)) {CF_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define CF_CORE_ASSERT(x, ...) { if(!(x)) {CF_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define CF_ASSERT(x, ...) x
	#define CF_CORE_ASSERT(x, ...) x
#endif