#include "ResourceManager.h"
#include "Resource.h"

std::shared_ptr<Resource> ResourceManager::use(const std::string& _name)
{
	for (auto it = resources.begin(); it != resources.end(); it++)
	{
		if ((*it)->getName() == _name)
		{
			return (*it);
		}
	}

	// Resource not found
	return nullptr;
}
