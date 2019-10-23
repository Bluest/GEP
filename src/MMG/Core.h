#ifndef _CORE_H_
#define _CORE_H_

#include <list>
#include <memory>

class Entity;

class Core
{
private:
	bool running;
	std::list<std::shared_ptr<Entity>> entities;

public:
	static std::shared_ptr<Core> init();
	std::shared_ptr<Entity> addEntity();
	void run();
	void quit();
};

#endif