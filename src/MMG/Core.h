#ifndef _CORE_H_
#define _CORE_H_

#include <rend.h>
#include <SDL2/SDL.h>
#include <list>
#include <memory>

class Entity;

class Time
{
private:
	float prev;
	float curr;
	float target;

public:
	float delta;

	void start(float _fpsCap)
	{
		prev = SDL_GetTicks();
		target = 1.0f / _fpsCap;
		delta = target;
	}

	void tick()
	{
		curr = SDL_GetTicks();
		delta = (curr - prev) / 1000.0f;
		prev = curr;
		
		// Cap FPS at _fpsCap
		if (delta < target)
		{
			SDL_Delay((target - delta) * 1000.0f);
		}
	}
};

class Core
{

public:
	static std::shared_ptr<Core> init(const int _winW, const int _winH);
	void run();
	void quit();
	std::shared_ptr<Entity> addEntity();

private:
	SDL_Window* window = nullptr;
	SDL_GLContext glContext = NULL;
	// rend::Context rendContext
	// std::weak_ptr<Camera> currentCamera
	// std::shared_ptr< (list?) Resource> resources

	Time time;

	std::weak_ptr<Core> self;
	std::list<std::shared_ptr<Entity>> entities;
	bool running = false;

	void quit();
};

#endif
