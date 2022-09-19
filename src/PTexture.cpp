#include <PTexture.h>
#include <PRenderer.h>
#include <PSurface.h>
#include <SDL_image.h>

PTexture::PTexture(PTexture&& texture) noexcept
{
	m_texture = texture.m_texture;
	texture.m_texture = nullptr;
}

PTexture::~PTexture()
{
	if (m_texture)
		SDL_DestroyTexture(m_texture);
}

PTexture& PTexture::operator=(PTexture&& texture) noexcept
{
	std::swap(m_texture, texture.m_texture);
	return *this;
}

SDL_Texture* PTexture::GetHandle() const
{
	return m_texture;
}

PTexture PTexture::LoadFromFile(PRenderer& renderer, const std::string& path)
{
	return LoadFromSurface(renderer, PSurface::LoadFromFile(path));
}

PTexture PTexture::LoadFromSurface(PRenderer& renderer, const PSurface& surface)
{
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer.GetHandle(), surface.GetHandle());
	return PTexture(texture);
}

PTexture::PTexture(SDL_Texture* texture) :
	m_texture(texture)
{
}
