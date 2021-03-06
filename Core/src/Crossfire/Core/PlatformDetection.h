#pragma once

#ifdef _WIN32
	/* Windows x64/x86 */
	#ifdef _WIN64
		/* Windows x64 */
		#define CF_PLATFORM_WINDOWS
	#else
		/* Windows x86*/
		#error "x86 Builds are not supported!
	#endif

#else
	#error "Crossfire only supports Windows!"		
#endif 

/* Chosing the best render api for the current platform*/

#ifdef CF_PLATFORM_WINDOWS
	#define CF_API_OPENGL
#endif