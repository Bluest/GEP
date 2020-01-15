#include <iostream>

#include "Resource.h"

Resource::Resource(const std::shared_ptr<Core>& _core, const std::string& _name)
{
	core = _core;
	name = _name;
	std::cout << "Loading " << _name;
}

std::string Resource::getName()
{
	return name;
}
