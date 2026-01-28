#pragma once

#ifdef _WIN32
#ifdef LUMINA_BUILD_DLL
#define LUMINA_API __declspec(dllexport)
#else
#define LUMINA_API __declspec(dllimport)
#endif
#else
#define LUMINA_API
#endif
