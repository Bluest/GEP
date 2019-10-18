#include <memory>
#include <list>

class Entity;

class Application
{
private:
	std::list<std::shared_ptr<Entity>> entities;

public:
	std::shared_ptr<Application> init();
	std::shared_ptr<Entity> addEntity();
};