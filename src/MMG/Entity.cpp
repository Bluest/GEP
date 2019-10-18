#include "Entity.h"

std::shared_ptr<Application> Entity::getApplication()
{
	return application.lock();
}

template <class T>
std::shared_ptr<T> Entity::addComponent(T _component)
{
	std::shared_ptr<T> component;

	return component;
}