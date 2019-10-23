#include "Core.h"

std::shared_ptr<Core> Core::init()
{
	std::shared_ptr<Core> core = std::make_shared<Core>();

	return core;
}

void Core::run()
{
	running = true;
}

void Core::quit()
{
	running = false;
}

std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr<Entity> entity;

	return entity;
}