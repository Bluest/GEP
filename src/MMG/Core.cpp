#include "Core.h"
#include "Entity.h"

std::shared_ptr<Core> Core::init()
{
	std::shared_ptr<Core> core = std::make_shared<Core>();
	core->self = core;
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
