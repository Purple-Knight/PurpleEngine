#pragma once
#include <PurpleEngine.h>
#include <SDL.h>
#include <memory>

class PRenderer;
class PTexture;

class PURPLE_ENGINE_API Sprite
{
public:
	Sprite(std::shared_ptr<PTexture> texture);
	Sprite(std::shared_ptr<PTexture>, const SDL_Rect& rect);
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
	std::shared_ptr<PTexture> m_texture;
	SDL_Rect m_rect;
	int m_width;
	int m_height;
};