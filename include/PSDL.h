#pragma once
#include <SDL.h>

class PSDL
{
public:
	PSDL();
	PSDL(const PSDL&) = delete;
	~PSDL();

	PSDL& operator=(const PSDL&) = delete;

	static bool PollEvent(SDL_Event* event);
};