#pragma once
#include <PurpleEngine.h>
#include <SDL.h>
#include <map>
#include <string>
#include <functional>

class PURPLE_ENGINE_API InputManager
{
public:
	InputManager(const InputManager&) = delete;
	InputManager(InputManager&&) = delete;
	~InputManager() = default;

	InputManager& operator=(const InputManager&) = delete;
	InputManager& operator=(InputManager&&) = delete;

	static InputManager& Instance();
	void BindKeyPressed(SDL_Keycode key, std::string action);
	void OnAction(std::string action, std::function<void()> func);
	void CheckInput(SDL_Keycode key);

private:
	InputManager();
	std::map<SDL_Keycode, std::string> keyBinds;
	std::map<std::string, std::function<void()>> actionBinds;
};