#include <list>

#include <SDL2/SDL.h>

class Input
{
public:
	bool isKeyHeld(const SDL_Keycode& _key);
	bool isKeyPressed(const SDL_Keycode& _key);
	bool isKeyReleased(const SDL_Keycode& _key);

	bool processInput(SDL_Event* _event);

private:
	std::list<SDL_Keycode> keysHeld;
	std::list<SDL_Keycode> keysPressed;
	std::list<SDL_Keycode> keysReleased;

	void processKeyDown(const SDL_Keycode& _key);
	void processKeyUp(const SDL_Keycode& _key);
};
