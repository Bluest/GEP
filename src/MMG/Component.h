#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <memory>

class Entity;
class Core;

class Component
{
	friend class Entity;

public:
	std::shared_ptr<Entity> getEntity();
	std::shared_ptr<Core> getCore();

private:
	std::weak_ptr<Entity> entity;

	virtual void onStart() {}
	virtual void onUpdate() {}
	virtual void onDraw() {}
};

#endif _COMPONENT_H_
