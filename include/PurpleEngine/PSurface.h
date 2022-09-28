#pragma once
#include <PurpleEngine.h>
#include <SDL.h>
#include <string>

class PURPLE_ENGINE_API PSurface
{
public:
	PSurface(const PSurface&) = delete;
	PSurface(PSurface&& surface) noexcept;
	~PSurface();

	PSurface& operator=(const PSurface&) = delete;
	PSurface& operator=(PSurface&& surface) noexcept;

	SDL_Surface* GetHandle() const;
	static PSurface LoadFromFile(const std::string& path);

private:
	PSurface(SDL_Surface* texturex);

	SDL_Surface* m_surface;
};