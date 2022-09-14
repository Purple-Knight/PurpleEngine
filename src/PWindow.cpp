#include <PWindow.h>

PWindow::PWindow(const std::string& title, int x, int y, int width, int height, Uint32 flags)
{
	m_window = SDL_CreateWindow(title.c_str(), x, y, width, height, flags);
}

PWindow::PWindow(const std::string& title, int width, int height, Uint32 flags) :
PWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags)
{
}

PWindow::~PWindow()
{
	SDL_DestroyWindow(m_window);
}

SDL_Window* PWindow::GetHandle()
{
	return m_window;
}
