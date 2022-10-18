#include <InputManager.h>
#include <iostream>

InputManager& InputManager::Instance() 
{
	static InputManager m_instance;
	return m_instance;
}

void InputManager::BindKeyPressed(SDL_KeyCode key, std::string action)
{
	keyBinds.insert({ key, action });
}

void InputManager::OnAction(std::string action, std::function<void()> func)
{
	actionBinds.insert({ action, func });
}

void InputManager::CheckInput(SDL_KeyCode key)
{
	auto bindsIt = keyBinds.find(key);
	if (bindsIt != keyBinds.end())
	{
		auto actionIt = actionBinds.find(keyBinds[key]);
		if (actionIt != actionBinds.end())
			actionBinds[keyBinds[key]]();
		else
			std::cout << "Action : " << keyBinds[key] << " ; not bind !" << std::endl;
	}
}

InputManager::InputManager() :
	keyBinds(),
	actionBinds()
{

}