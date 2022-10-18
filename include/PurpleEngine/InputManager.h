#pragma once
#include <PurpleEngine.h>
#include <SDL.h>
#include <unordered_map>
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
	void BindKeyPressed(SDL_KeyCode key, std::string action);
	void OnAction(std::string action, std::function<void()> func);
	void CheckInput(SDL_KeyCode key);

private:
	InputManager();
	std::unordered_map<SDL_KeyCode, std::string> keyBinds;
	std::unordered_map<std::string, std::function<void()>> actionBinds;
};