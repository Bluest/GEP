#include <rend.h>

#include <iostream>

#include "Model.h"

Model::Model(const std::string& _path) : Resource(_path)
{
	std::cout << "<Model>" << std::endl;
	// Load rend stuff
}
