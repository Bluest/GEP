#include <memory>
#include <list>

class Component;
class Application;

class Entity
{
private:
	std::list<std::shared_ptr<Component>> components;
	std::weak_ptr<Application> application;

public:
	std::shared_ptr<Application> getApplication();

	template <class T>
	std::shared_ptr<T> addComponent(T _component);
};