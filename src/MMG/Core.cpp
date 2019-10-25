#include "Core.h"
#include "Entity.h"

std::shared_ptr<Core> Core::init()
{
	return std::make_shared<Core>();
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

	quit();
}

void Core::quit()
{
	running = false;
}

std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr<Entity> entity = std::make_shared<Entity>();
	entities.push_back(entity);
	// init new entity's fields

	return entity;
}
