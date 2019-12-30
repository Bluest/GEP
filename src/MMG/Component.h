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

	virtual void onStart() = 0;
	virtual void onUpdate() = 0;
	virtual void onDraw() = 0;
};

#endif
