#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <memory>

class Entity;

class Component
{
private:
	std::weak_ptr<Entity> entity;

	virtual void start() = 0;
	virtual void update() = 0;

public:
	std::shared_ptr<Entity> getEntity();
};

#endif