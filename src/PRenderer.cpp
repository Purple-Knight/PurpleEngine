#include <PRenderer.h>
#include <PWindow.h>
#include <PTexture.h>

PRenderer::PRenderer(PWindow& window, int index, Uint32 flags)
{
	m_renderer = SDL_CreateRenderer(window.GetHandle(), index, flags);
}

PRenderer::PRenderer(PRenderer&& renderer) noexcept
{
	m_renderer = renderer.m_renderer;
	renderer.m_renderer = nullptr;
}

PRenderer::~PRenderer()
{
	SDL_DestroyRenderer(m_renderer);
}

PRenderer& PRenderer::operator=(PRenderer&& renderer) noexcept
{
	std::swap(m_renderer, renderer.m_renderer);
	return *this;
}

SDL_Renderer* PRenderer::GetHandle() const
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

void PRenderer::RenderCopy(const PTexture& texture)
{
	SDL_RenderCopy(m_renderer, texture.GetHandle(), nullptr, nullptr);
}

void PRenderer::RenderCopy(const PTexture& texture, const SDL_Rect& dst)
{
	SDL_RenderCopy(m_renderer, texture.GetHandle(), nullptr, &dst);
}

void PRenderer::RenderCopy(const PTexture& texture, const SDL_Rect& src, const SDL_Rect& dst)
{
	SDL_RenderCopy(m_renderer, texture.GetHandle(), &src, &dst);
}
