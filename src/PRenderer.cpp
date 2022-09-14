#include <PRenderer.h>
#include <PWindow.h>

PRenderer::PRenderer(PWindow& window, int index, Uint32 flags)
{
	m_renderer = SDL_CreateRenderer(window.GetHandle(), index, flags);
}

PRenderer::~PRenderer()
{
	SDL_DestroyRenderer(m_renderer);
}

SDL_Renderer* PRenderer::GetHandle()
{
	return m_renderer;
}

void PRenderer::Clear()
{
	SDL_RenderClear(m_renderer);
}

void PRenderer::Present()
{
	SDL_RenderPresent(m_renderer);
}

void PRenderer::SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
}
