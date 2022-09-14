#include <PRenderer.h>
#include <PWindow.h>

PRenderer::PRenderer(PWindow& window, int index, Uint32 flags)
{
	renderer = SDL_CreateRenderer(window.GetSDLWindow(), index, flags);
}

PRenderer::~PRenderer()
{
	SDL_DestroyRenderer(renderer);
}

void PRenderer::Clear()
{
	SDL_RenderClear(renderer);
}

void PRenderer::Present()
{
	SDL_RenderPresent(renderer);
}

void PRenderer::SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}
