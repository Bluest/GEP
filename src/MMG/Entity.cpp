#include "Entity.h"
#include "Component.h"

std::shared_ptr<Core> Entity::getCore()
{
	return core.lock();
}

void Entity::start()
{
	for (auto it = components.begin(); it != components.end(); it++)
	{
		(*it)->onStart();
	}
}

void Entity::update()
{
	for (auto it = components.begin(); it != components.end(); it++)
	{
		(*it)->onUpdate();
	}
}

void Entity::draw()
{
	for (auto it = components.begin(); it != components.end(); it++)
	{
		(*it)->onDraw();
	}
}
