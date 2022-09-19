#pragma once
#include <SDL.h>
#include <string>

class PRenderer;
class PSurface;

class PTexture
{
public:
	PTexture(const PTexture&) = delete;
	PTexture(PTexture&& texture) noexcept;
	~PTexture();

	PTexture& operator=(const PTexture&) = delete;
	PTexture& operator=(PTexture&& texture) noexcept;

	SDL_Texture* GetHandle() const;
	static PTexture LoadFromFile(PRenderer& renderer, const std::string& path);
	static PTexture LoadFromSurface(PRenderer& renderer,const PSurface& surface);

private:
	PTexture(SDL_Texture* texturex);

	SDL_Texture* m_texture;
};