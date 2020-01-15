#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <list>
#include <memory>

#include <glm/glm.hpp>

class Core;
class Component;

// Transform is a part of entity, instead of a separate component
struct Transform
{
	// Initialise with default values
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);
};

class Entity
{
	friend class Core;

public:
	Transform transform;

	template <typename T>
	void addComponent()
	{
		std::shared_ptr<T> component = std::make_shared<T>();
		component->entity = self;
		components.push_back(component);
		component->init();
	}

	template <typename T, typename A>
	void addComponent(A _a)
	{
		std::shared_ptr<T> component = std::make_shared<T>();
		component->entity = self;
		components.push_back(component);
		component->init(_a);
	}

	template <typename T, typename A, typename B>
	void addComponent(A _a, B _b)
	{
		std::shared_ptr<T> component = std::make_shared<T>();
		component->entity = self;
		components.push_back(component);
		component->init(_a, _b);
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

private:
	std::weak_ptr<Entity> self;
	std::weak_ptr<Core> core;
	std::list<std::shared_ptr<Component>> components;

	void start();
	void update();
	void draw();
};

#endif // _ENTITY_H_
