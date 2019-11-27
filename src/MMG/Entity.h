#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <list>
#include <memory>

class Core;
class Component;

class Entity
{
	friend class Core;

private:
	std::weak_ptr<Entity> self;
	std::weak_ptr<Core> core;
	std::list<std::shared_ptr<Component>> components;

	void start();
	void update();
	void draw();

public:
	template <class T>
	std::shared_ptr<T> addComponent()
	{
		std::shared_ptr<T> component = std::make_shared<T>();
		component->entity = self;
		components.push_back(component);
		component->init();

		return component;
	}

	template <class T, class A>
	std::shared_ptr<T> addComponent(A _a)
	{
		std::shared_ptr<T> component = std::make_shared<T>();
		component->entity = self;
		components.push_back(component);
		component->init(_a);

		return component;
	}

	template <class T>
	std::shared_ptr<T> getComponent()
	{
		std::shared_ptr<T> component;

		for (auto it = components.begin(); it != components.end(); it++)
		{
			component = std::dynamic_pointer_cast<T>(*it);
			if (component) return component;
		}

		return nullptr;
	}

	std::shared_ptr<Core> getCore();
};

#endif
