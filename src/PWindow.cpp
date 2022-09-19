#include <PWindow.h>


PWindow::PWindow(const std::string& title, int width, int height, Uint32 flags) :
PWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags)
{
}

PWindow::PWindow(const std::string& title, int x, int y, int width, int height, Uint32 flags)
{
	m_window = SDL_CreateWindow(title.c_str(), x, y, width, height, flags);
}

PWindow::PWindow(PWindow&& window) noexcept
{
	m_window = window.m_window;
	window.m_window = nullptr;
}

PWindow::~PWindow()
{
	if (m_window)
		SDL_DestroyWindow(m_window);
}

PWindow& PWindow::operator=(PWindow&& window) noexcept
{
	std::swap(m_window, window.m_window);
	return *this;
}

SDL_Window* PWindow::GetHandle() const
{
	return m_window;
}
