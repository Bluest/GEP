#include "Input.h"

bool Input::isKeyHeld(const SDL_Keycode& _key)
{
	for (auto it = keysHeld.begin(); it != keysHeld.end(); it++)
	{
		if (*it == _key)
		{
			return true;
		}
	}

	return false;
}

bool Input::isKeyPressed(const SDL_Keycode& _key)
{
	for (auto it = keysPressed.begin(); it != keysPressed.end(); it++)
	{
		if (*it == _key)
		{
			return true;
		}
	}

	return false;
}

bool Input::isKeyReleased(const SDL_Keycode& _key)
{
	for (auto it = keysReleased.begin(); it != keysReleased.end(); it++)
	{
		if (*it == _key)
		{
			return true;
		}
	}

	return false;
}

bool Input::processInput(SDL_Event* _event)
{
	keysPressed.clear();
	keysReleased.clear();

	while (SDL_PollEvent(_event))
	{
		switch (_event->type)
		{
		case SDL_KEYDOWN: { processKeyDown(_event->key.keysym.sym); break; }
		case SDL_KEYUP: { processKeyUp(_event->key.keysym.sym); break; }
		case SDL_QUIT: { return false; }
		}
	}

	return true;
}

void Input::processKeyDown(const SDL_Keycode& _key)
{
	keysPressed.push_back(_key);

	// If the key is not already in the keysHeld list, add it
	if (std::find(keysHeld.begin(), keysHeld.end(), _key) == keysHeld.end())
	{
		keysHeld.push_back(_key);
	}
}

void Input::processKeyUp(const SDL_Keycode& _key)
{
	keysReleased.push_back(_key);
	keysHeld.remove(_key);
}
