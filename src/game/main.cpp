// <MMG.h> should be included first
#include <MMG.h>

#include <iostream>

#include "Player.h"

void load(ResourceManager& _resources)
{
	_resources.load<Model>("IvysaurModel", "../assets/ivysaur.obj");
	_resources.load<Material>("IvysaurMaterial", "../assets/ivysaur_diffuse.jpg");
	_resources.load<Model>("CuruthersObj", "../assets/curuthers/curuthers.obj");
	_resources.load<Material>("CuruthersMat", "../assets/curuthers/Whiskers_diffuse.png");
}

int main()
{
	std::shared_ptr<Core> core = Core::init(500, 500);
	ResourceManager resources(core);

	load(resources);

	std::shared_ptr<Entity> testEntity = core->addEntity();
	std::shared_ptr<Player> testPlayer = testEntity->addComponent<Player>();

	std::shared_ptr<MeshRenderer> meshRenderer = testEntity->addComponent<MeshRenderer>(
		resources.use<Model>("IvysaurModel"),
		resources.use<Material>("IvysaurMaterial"));

	std::shared_ptr<Entity> testEntity2 = core->addEntity();
	std::shared_ptr<Player> testPlayer2 = testEntity->addComponent<Player>();

	std::shared_ptr<MeshRenderer> meshRenderer2 = testEntity->addComponent<MeshRenderer>(
		resources.use<Model>("CuruthersObj"),
		resources.use<Material>("CuruthersMat"));

	core->run();
	
	return 0;
}
