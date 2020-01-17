#include <rend.h>

#include <iostream>
#include <fstream>

#include "Model.h"
#include "Core.h"

Model::Model(const std::shared_ptr<Core>& _core, const std::string& _name) : Resource(_core, _name)
{
	std::cout << " <Model> from \"";
}

void Model::onLoad(const std::string& _path)
{
	try
	{
		std::cout << _path << "\"" << std::endl;

		mesh = core->getRendContext()->createMesh();

		std::ifstream objFile(_path);

		if (!objFile.is_open())
		{
			throw rend::Exception("Failed to open .obj file");
		}

		std::string obj;
		std::string line;

		while (!objFile.eof())
		{
			std::getline(objFile, line);
			obj += line + "\n";
		}

		mesh->parse(obj);
	}
	catch (rend::Exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::sr1::shared_ptr<rend::Mesh> Model::getMesh()
{
	return mesh;
}
