#include "Core.h"
#include "Entity.h"

std::shared_ptr<Core> Core::init()
{
	std::shared_ptr<Core> core = std::make_shared<Core>();
	core->self = core;
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		throw std::exception();

	SDL_Window *window = SDL_CreateWindow("Lab 4 - Architecture",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		core->winW = 640, core->winH = 480, SDL_WINDOW_OPENGL);

	if (!SDL_GL_CreateContext(window))
		throw std::exception();

	if (glewInit() != GLEW_OK)
		throw std::exception();

	return core;
}

void Core::run()
{
	running = true;

	for (auto it = entities.begin(); it != entities.end(); it++)
		(*it)->start();

	while (running)
	{
		for (auto it = entities.begin(); it != entities.end(); it++)
			(*it)->update();

		for (auto it = entities.begin(); it != entities.end(); it++)
			(*it)->draw();
	}
}

void Core::quit()
{
	running = false;
}

std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr<Entity> entity = std::make_shared<Entity>();
	entity->self = entity;
	entity->core = self;
	entities.push_back(entity);

	return entity;
}
