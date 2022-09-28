#pragma once
#include <PurpleEngine.h>
#include <SDL.h>
#include <memory>

class PTexture;
class PWindow;

class PURPLE_ENGINE_API PRenderer
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
	void RenderCopy(std::shared_ptr<PTexture> texture);
	void RenderCopy(std::shared_ptr<PTexture> texture, const SDL_Rect& dst);
	void RenderCopy(std::shared_ptr<PTexture> texture, const SDL_Rect& src, const SDL_Rect& dst);

private:
	SDL_Renderer* m_renderer;

};
