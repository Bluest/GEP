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
	std::shared_ptr<Core> core = Core::init("MMG Demo", 500, 500);
	ResourceManager resources(core);

	load(resources);

	std::shared_ptr<Entity> testEntity = core->addEntity();
	testEntity->addComponent<Player>();
	testEntity->addComponent<MeshRenderer>(
		resources.use<Model>("IvysaurModel"),
		resources.use<Material>("IvysaurMaterial"));

	std::shared_ptr<Entity> testEntity2 = core->addEntity();
	testEntity2->addComponent<Player>();
	testEntity2->addComponent<MeshRenderer>(
		resources.use<Model>("CuruthersObj"),
		resources.use<Material>("CuruthersMat"));

	testEntity2->transform.position.y += 1.0f;
	testEntity2->transform.position.z -= 15.0f;
	core->run();
	
	return 0;
}
