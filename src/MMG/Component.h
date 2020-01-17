#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <memory>

class Entity;
class Core;

/** \brief Base component class. Virtual methods' behaviours will be overridden by derived components.
*/
class Component
{
	friend class Entity;

protected:
	/** \brief Gets the Entity that this component belongs to.
		\return Pointer to this component's Entity
	*/
	std::shared_ptr<Entity> getEntity();

	/** Gets the game engine's Core.
		\return Pointer to the Core
	*/
	std::shared_ptr<Core> getCore();

private:
	std::weak_ptr<Entity> entity;

	virtual void onStart() {}
	virtual void onUpdate() {}
	virtual void onDraw() {}
};

#endif _COMPONENT_H_
