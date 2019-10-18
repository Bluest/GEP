#include <memory>

class Entity;

class Component
{
private:
	std::weak_ptr<Entity> entity;

public:
	std::shared_ptr<Entity> getEntity();
};