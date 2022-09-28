#include <PSurface.h>
#include <SDL_image.h>
#include <iostream>

PSurface::PSurface(PSurface&& surface) noexcept
{
	m_surface = surface.m_surface;
	surface.m_surface = nullptr;
}

PSurface::~PSurface()
{
	if (m_surface)
		SDL_FreeSurface(m_surface);
}

PSurface& PSurface::operator=(PSurface&& surface) noexcept
{
	std::swap(m_surface, surface.m_surface);
	return *this;
}

SDL_Surface* PSurface::GetHandle() const
{
	return m_surface;
}

PSurface PSurface::LoadFromFile(const std::string& path)
{
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (!surface)
		std::cout << IMG_GetError() << std::endl;
	return PSurface(surface);
}

PSurface::PSurface(SDL_Surface* surface) :
	m_surface(surface)
{
}
