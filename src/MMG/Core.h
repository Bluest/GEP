#ifndef _CORE_H_
#define _CORE_H_

// rend's <sr1/memory> must be included before <memory>
#include <rend.h>

#include <list>
#include <memory>

#include <SDL2/SDL.h>

class Time;
class Input;
class Entity;

class Core
{
public:
	static std::shared_ptr<Core> init(const char* _title, const int& _winW, const int& _winH);
	void run();

	std::shared_ptr<Entity> addEntity();
	std::sr1::shared_ptr<rend::Context> getRendContext();
	float getDeltaTime();
	std::shared_ptr<Input> getInput();

private:
	SDL_Window* window = nullptr;
	SDL_GLContext glContext = NULL;
	std::sr1::shared_ptr<rend::Context> rendContext;
	// std::weak_ptr<Camera> currentCamera

	std::weak_ptr<Core> self;
	std::unique_ptr<Time> time;
	std::shared_ptr<Input> input;
	std::list<std::shared_ptr<Entity>> entities;
	bool running = false;

	void quit();
};

#endif // _CORE_H_
