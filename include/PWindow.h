#pragma once
#include <SDL.h>
#include <String>

class PWindow
{
private:
	SDL_Window* m_window;

public:
	PWindow(const std::string& title, int x, int y, int width, int height, Uint32 flags = 0);
	PWindow(const std::string& title, int width, int height, Uint32 flags = 0);
	PWindow(const PWindow&) = delete;
	~PWindow();

	PWindow& operator=(const PWindow&) = delete;

	SDL_Window* GetHandle();
};