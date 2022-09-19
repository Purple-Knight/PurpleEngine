#pragma once
#include <SDL.h>

class PTexture;
class PWindow;

class PRenderer
{
public:
	PRenderer(PWindow& window, int index = 0, Uint32 flags = 0);
	PRenderer(const PRenderer&) = delete;
	PRenderer(PRenderer&&) noexcept;
	~PRenderer();

	PRenderer& operator=(const PRenderer&) = delete;
	PRenderer& operator=(PRenderer&&) noexcept;

	SDL_Renderer* GetHandle() const;
	void Clear();
	void Present();
	void SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void RenderCopy(const PTexture& texture);
	void RenderCopy(const PTexture& texture, const SDL_Rect& dst);
	void RenderCopy(const PTexture& texture, const SDL_Rect& src, const SDL_Rect& dst);

private:
	SDL_Renderer* m_renderer;

};
