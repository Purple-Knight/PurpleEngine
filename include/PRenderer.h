#pragma once
#include <SDL.h>

class PWindow;

class PRenderer
{
private:
	SDL_Renderer* m_renderer;

public:
	PRenderer(PWindow& window, int index = 0, Uint32 flags = 0);
	PRenderer(const PRenderer&) = delete;
	~PRenderer();

	PRenderer& operator=(const PRenderer&) = delete;

	SDL_Renderer* GetHandle();
	void Clear();
	void Present();
	void SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
};
