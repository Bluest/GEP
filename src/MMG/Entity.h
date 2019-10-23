#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <list>
#include <memory>

class Component;
class Core;

class Entity
{
private:
	std::list<std::shared_ptr<Component>> components;
	std::weak_ptr<Core> core;

public:
	std::shared_ptr<Core> getCore();

	template <class T>
	std::shared_ptr<T> addComponent(T _component);
};

#endif