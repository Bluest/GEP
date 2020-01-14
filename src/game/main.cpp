// <MMG.h> should be included first
#include <MMG.h>

#include <iostream>

#include "Player.h"

int main()
{
	std::shared_ptr<Core> core = Core::init(500, 500);
	ResourceManager resources;

	resources.load<Model>("../assets/ivysaur.obj");
	resources.load<Material>("../assets/ivysaur_diffuse.jpg");

	std::shared_ptr<Entity> testEntity = core->addEntity();
	std::shared_ptr<Player> testPlayer = testEntity->addComponent<Player>();

	std::shared_ptr<MeshRenderer> meshRenderer = testEntity->addComponent<MeshRenderer>(
		"../assets/ivysaur.obj",
		"../assets/ivysaur_diffuse.jpg");

	core->run();
	
	return 0;
}
