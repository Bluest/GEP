#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <list>
#include <memory>

class Component;
class Application;

class Entity
{
private:
	std::list<std::shared_ptr<Component>> components;
	std::weak_ptr<Application> application;

public:
	std::shared_ptr<Application> getApplication();

	template <class T>
	std::shared_ptr<T> addComponent(T _component);
};

#endif