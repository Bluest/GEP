#ifndef _CORE_H_
#define _CORE_H_

#include <rend.h>
#include <SDL2/SDL.h>
#include <list>
#include <memory>

class Entity;

class Core
{
private:
	SDL_Window* window = nullptr;
	SDL_GLContext glContext = NULL;

	// Allow these to be defined in the game project:
	const int winW = 640;
	const int winH = 480;

	std::weak_ptr<Core> self;
	std::list<std::shared_ptr<Entity>> entities;
	bool running = false;

public:
	static std::shared_ptr<Core> init();
	void run();
	void quit();
	std::shared_ptr<Entity> addEntity();
};

#endif
