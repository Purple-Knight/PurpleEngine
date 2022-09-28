#pragma once
#include <PurpleEngine.h>
#include <SDL.h>

class PURPLE_ENGINE_API PSDL
{
public:
	PSDL();
	PSDL(const PSDL&) = delete;
	PSDL(PSDL&&) = delete;
	~PSDL();

	PSDL& operator=(const PSDL&) = delete;
	PSDL& operator=(PSDL&&) = delete;

	static bool PollEvent(SDL_Event* event);
};