#pragma once

#ifdef CF_PLATFORM_WINDOWS
	#ifdef CF_BUILD_DLL
		#define CF_API __declspec(dllexport)
	#else
		#define CF_API __declspec(dllimport)
	#endif
#else 
	#error Crossfire only supports Windows!
#endif

