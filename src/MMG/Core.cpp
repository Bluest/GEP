#include "Core.h"
#include "Entity.h"

std::shared_ptr<Core> Core::init(const int _winW, const int _winH)
{
	std::shared_ptr<Core> core = std::make_shared<Core>();
	core->self = core;

	// SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		throw rend::Exception("Failed to initialise SDL");

	// Window
	core->window = SDL_CreateWindow("MMG",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		_winW, _winH, SDL_WINDOW_OPENGL);

	if (!core->window)
		throw rend::Exception("Failed to create window");

	// OpenGL context
	core->glContext = SDL_GL_CreateContext(core->window);

	if (!core->glContext)
		throw rend::Exception("Failed to create OpenGL context");

	// GlEW
	if (glewInit() != GLEW_OK)
		throw rend::Exception("Failed to initialise GLEW");

	return core;
}

void Core::run()
{
	// v Make this definable in game instead
	time.start(60.0f);

	for (auto it = entities.begin(); it != entities.end(); it++)
		(*it)->start();

	SDL_Event event = { 0 };
	running = true;
	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				printf("Quitting...\n");
				running = false;
			}
		}

		for (auto it = entities.begin(); it != entities.end(); it++)
			(*it)->update();

		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (auto it = entities.begin(); it != entities.end(); it++)
			(*it)->draw();

		SDL_GL_SwapWindow(window);
		time.tick();
	}

	quit();
}

void Core::quit()
{
	// rend::Context.reset() here to fix the abort() message

	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr<Entity> entity = std::make_shared<Entity>();
	entity->self = entity;
	entity->core = self;
	entities.push_back(entity);

	return entity;
}
