#ifndef _CORE_H_
#define _CORE_H_

#include <SDL.h>
#include <glew.h>
#include <list>
#include <memory>

class Entity;

class Core
{
private:
	SDL_Window* window = nullptr;
	const int winW = 640;
	const int winH = 480;
	SDL_GLContext glContext = NULL;

	std::weak_ptr<Core> self;
	std::list<std::shared_ptr<Entity>> entities;
	bool running = false;

public:
	static std::shared_ptr<Core> init();
	std::shared_ptr<Entity> addEntity();
	void run();
	void quit();
};

#endif
