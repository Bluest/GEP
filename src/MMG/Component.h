#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <memory>
#include "Entity.h"

class Core;

class Component
{
private:
	std::weak_ptr<Entity> entity;

	virtual void onStart() = 0;
	virtual void onUpdate() = 0;

public:
	std::shared_ptr<Entity> getEntity();
	std::shared_ptr<Core> getCore();
};

#endif
