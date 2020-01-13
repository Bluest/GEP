#include <rend.h>

#include <iostream>

#include "Material.h"

Material::Material(const std::string& _path) : Resource(_path)
{
	std::cout << "<Material>" << std::endl;
	// Load rend stuff
}
