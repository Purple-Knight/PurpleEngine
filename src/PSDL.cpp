#include <PSDL.h>

PSDL::PSDL()
{
	SDL_Init(0);
}

PSDL::~PSDL()
{
	SDL_Quit();
}

bool PSDL::PollEvent(SDL_Event* event)
{
	return SDL_PollEvent(event);
}
