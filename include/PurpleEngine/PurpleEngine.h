#pragma once

#ifdef  PURPLE_ENGINE_EXPORT 
#define PURPLE_ENGINE_API __declspec(dllexport)  
#else
#define PURPLE_ENGINE_API __declspec(dllimport)  
#endif