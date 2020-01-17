#include "Core.h"
#include "Camera.h"
#include "Environment.h"
#include "Input.h"
#include "Entity.h"

std::shared_ptr<Core> Core::init(const char* _title, const int& _winW, const int& _winH)
{
	try
	{
		std::shared_ptr<Core> core = std::make_shared<Core>();
		core->self = core;
		core->time = std::make_unique<Time>();
		core->input = std::make_shared<Input>();
		core->camera = std::make_shared<Camera>(_winW, _winH);

		// Initialise SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw rend::Exception("Failed to initialise SDL");
		}

		// Create SDL window
		core->window = SDL_CreateWindow(_title,
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			_winW, _winH, SDL_WINDOW_OPENGL);

		if (!core->window)
		{
			throw rend::Exception("Failed to create window");
		}

		// OpenGL context
		core->glContext = SDL_GL_CreateContext(core->window);

		if (!core->glContext)
		{
			throw rend::Exception("Failed to create OpenGL context");
		}

		// rend context
		core->rendContext = rend::Context::initialize();

		// OpenAL
		core->alcDevice = alcOpenDevice(nullptr);

		if (!core->alcDevice)
		{
			throw rend::Exception("Failed to create OpenAL device");
		}

		core->alcContext = alcCreateContext(core->alcDevice, nullptr);

		if (!core->alcContext)
		{
			alcCloseDevice(core->alcDevice);
			throw rend::Exception("Failed to create OpenAL context");
		}

		if (!alcMakeContextCurrent(core->alcContext))
		{
			alcDestroyContext(core->alcContext);
			alcCloseDevice(core->alcDevice);
			throw rend::Exception("Failed to set the OpenAL context");
		}

		return core;
	}
	catch (rend::Exception & e)
	{
		std::cout << e.what() << std::endl;
		return nullptr;
	}
}

void Core::run()
{
	// 60 fps cap
	time->start(60.0f);

	// Call all entities' onStart()
	for (auto it = entities.begin(); it != entities.end(); it++)
		(*it)->start();

	SDL_Event event = { 0 };

	running = true;
	while (running)
	{
		if (!input->processInput(&event))
		{
			// Quit if processInput returned false
			running = false;
		}

		// Update entities
		for (auto it = entities.begin(); it != entities.end(); it++)
			(*it)->update();

		// Clear screen
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Draw entities
		for (auto it = entities.begin(); it != entities.end(); it++)
			(*it)->draw();

		// Present screen to window, step time for the next frame
		SDL_GL_SwapWindow(window);
		time->tick();
	}

	quit();
}

std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr<Entity> entity = std::make_shared<Entity>();
	entity->self = entity;
	entity->core = self;
	entities.push_back(entity);

	return entity;
}

std::sr1::shared_ptr<rend::Context> Core::getRendContext()
{
	return rendContext;
}

std::shared_ptr<Camera> Core::getCamera()
{
	return camera;
}

float Core::getDeltaTime()
{
	return time->getDelta();
}

std::shared_ptr<Input> Core::getInput()
{
	return input;
}

void Core::quit()
{
	// Clean up OpenAL
	alcMakeContextCurrent(nullptr);
	alcDestroyContext(alcContext);
	alcCloseDevice(alcDevice);

	// Clean up SDL
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
