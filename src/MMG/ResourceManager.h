#ifndef _RESOURCE_MANAGER_H_
#define _RESOURCE_MANAGER_H_

#include <list>
#include <memory>
#include <string>

class Resource;

class ResourceManager
{
public:
	std::shared_ptr<Resource> use(const std::string& _name);

	template <typename T>
	void load(const std::string& _path)
	{
		resources.emplace_back(std::make_shared<T>(_path));
	}

private:
	std::list<std::shared_ptr<Resource>> resources;
};

#endif // _RESOURCE_MANAGER_H_
