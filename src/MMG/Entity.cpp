#include "Entity.h"

void Entity::start()
{
	for (auto it = components.begin(); it != components.end(); it++)
	{
		// (*it)->start();
	}
}

void Entity::update()
{
	for (auto it = components.begin(); it != components.end(); it++)
	{
		// (*it)->update();
	}
}

void Entity::draw()
{
	
}

std::shared_ptr<Core> Entity::getCore()
{
	return core.lock();
}

template <class T>
std::shared_ptr<T> Entity::addComponent()
{
	std::shared_ptr<T> component = std::make_shared<T>;

	return component;
}
