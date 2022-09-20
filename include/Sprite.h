#pragma once
#include <SDL.h>

class PRenderer;
class PTexture;

class Sprite
{
public:
	Sprite(const PTexture& texture);
	Sprite(const PTexture& texture, const SDL_Rect& rect);
	Sprite(const Sprite&) = default;
	Sprite(Sprite&&) = default;
	~Sprite() = default;

	Sprite& operator=(const Sprite&) = delete;
	Sprite& operator=(Sprite&&) = delete;

	void Draw(PRenderer& renderer, int x, int y);

	int GetHeight() const;
	int GetWidth() const;

	void Resize(int width, int height);

	void SetRect(SDL_Rect rect);

private:
	const PTexture& m_texture;
	SDL_Rect m_rect;
	int m_width;
	int m_height;
};