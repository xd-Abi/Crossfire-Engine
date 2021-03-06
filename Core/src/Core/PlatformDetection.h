#pragma once

#ifdef CF_PLATFORM_WINDOWS
	#define CF_API_OPENGL
#else 
	#error Crossfire only supports Windows!
#endif