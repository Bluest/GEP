#include <iostream>

#include "Sound.h"

Sound::Sound(const std::shared_ptr<Core>& _core, const std::string& _name) : Resource(_core, _name)
{
	std::cout << " <Sound> from \"";
}

void Sound::onLoad(const std::string& _path)
{
	std::cout << _path << "\"" << std::endl;
}
