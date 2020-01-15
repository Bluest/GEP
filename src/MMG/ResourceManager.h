#ifndef _RESOURCE_MANAGER_H_
#define _RESOURCE_MANAGER_H_

#include <list>
#include <memory>
#include <string>

class Core;
class Resource;

class ResourceManager
{
public:
	ResourceManager(std::shared_ptr<Core> _core);

	template <typename T>
	void load(const std::string& _name, const std::string& _path)
	{
		std::shared_ptr<T> resource = std::make_shared<T>(core, _name);
		resource->onLoad(_path);
		resources.push_back(resource);
	}

	template <typename T>
	std::shared_ptr<T> use(const std::string& _name)
	{
		for (auto it = resources.begin(); it != resources.end(); it++)
		{
			if ((*it)->getName() == _name)
			{
				return std::dynamic_pointer_cast<T>(*it);
			}
		}

		// Resource not found
		return nullptr;
	}

private:
	std::shared_ptr<Core> core;
	std::list<std::shared_ptr<Resource>> resources;
};

#endif // _RESOURCE_MANAGER_H_
