#include <iostream>

#include "Resource.h"

Resource::Resource(const std::string& _path)
{
	std::cout << "Loading " << _path << std::endl;
	name = _path;
}

std::string Resource::getName()
{
	return name;
}
