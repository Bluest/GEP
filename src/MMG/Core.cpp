#include "Core.h"

std::shared_ptr<Core> Core::init()
{
	std::shared_ptr<Core> core = std::make_shared<Core>();

	return core;
}

void Core::run()
{
	running = true;

	for (auto it = entities.begin(); it != entities.end(); it++)
		// (*it)->start();

	while (running)
	{
		for (auto it = entities.begin(); it != entities.end(); it++)
			// (*it)->update();

		for (auto it = entities.begin(); it != entities.end(); it++)
			// (*it)->draw();

		quit(); // <- put this in testEntity's update()
	}
}

void Core::quit()
{
	running = false;
}

std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr<Entity> entity = std::make_shared<Entity>();
	entities.push_back(entity);
	
	entities.emplace_back(std::make_shared<Entity>());
	// init new entity's fields

	return entity;
}