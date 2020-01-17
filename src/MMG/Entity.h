#include <list>
#include <memory>

#include <glm/glm.hpp>

class Core;
class Component;

/** \brief Transform is a part of Entity, instead of a separate component
*/
struct Transform
{
	// Initialise with default values
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f); ///< The Entity's position.
	glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f); ///< The Entity's rotation.
	glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f); ///< The Entity's scale.
};

/** \brief All objects in the game are Entities. Components define behaviour
*/
class Entity
{
	friend class Core;

public:
	Transform transform; ///< Defines the Entity's position, rotation and scale.

	/** \brief Adds the specified Component type to this Entity. Added component takes no parameters.
		\return A pointer to the newly-created Component
	*/
	template <typename T>
	std::shared_ptr<T> addComponent()
	{
		std::shared_ptr<T> component = std::make_shared<T>();
		component->entity = self;
		components.push_back(component);
		component->init();

		return component;
	}

	/** \brief Adds the specified Component type to this Entity. Added component takes one parameter.
		\return A pointer to the newly-created Component
	*/
	template <typename T, typename A>
	std::shared_ptr<T> addComponent(A _a)
	{
		std::shared_ptr<T> component = std::make_shared<T>();
		component->entity = self;
		components.push_back(component);
		component->init(_a);

		return component;
	}

	/** \brief Adds the specified Component type to this Entity. Added component takes two parameters.
		\return A pointer to the newly-created Component
	*/
	template <typename T, typename A, typename B>
	std::shared_ptr<T> addComponent(A _a, B _b)
	{
		std::shared_ptr<T> component = std::make_shared<T>();
		component->entity = self;
		components.push_back(component);
		component->init(_a, _b);

		return component;
	}

	/** \brief Gets the specified Component from the Entity.
		\return A pointer to the requested Component, or nullptr if the component is not found
	*/
	template <class T>
	std::shared_ptr<T> getComponent()
	{
		try
		{
			std::shared_ptr<T> component;

			for (auto it = components.begin(); it != components.end(); it++)
			{
				component = std::dynamic_pointer_cast<T>(*it);
				if (component) return component;
			}

			throw rend::Exception("Entity does not have the requested component.");
		}
		catch (rend::Exception & e)
		{
			std::cout << e.what() << std::endl;

			return nullptr;
		}
	}

	/** \brief Gets the Core that this entity belongs to.
		\return Pointer to the Core
	*/
	std::shared_ptr<Core> getCore();

private:
	std::weak_ptr<Entity> self;
	std::weak_ptr<Core> core;
	std::list<std::shared_ptr<Component>> components;

	void start();
	void update();
	void draw();
};
