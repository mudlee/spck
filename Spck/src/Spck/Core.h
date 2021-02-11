#pragma once

#ifdef SPCK_PLATFORM_WINDOWS
	#ifdef SPCK_BUILD_DLL
		#define SPCK_API __declspec(dllexport)
	#else
		#define SPCK_API __declspec(dllimport)
	#endif
#else
	#error Currently only Windows is supported.
#endif
