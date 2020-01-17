// <MMG.h> should be included first
#include <MMG.h>

#include <iostream>

#include "Cat.h"

void load(ResourceManager& _resources)
{
	_resources.load<Model>("CuruthersObj", "../assets/curuthers.obj");
	_resources.load<Model>("IvysaurModel", "../assets/ivysaur.obj");
	_resources.load<Material>("CuruthersMat", "../assets/Whiskers_diffuse.png");
	_resources.load<Material>("IvysaurMaterial", "../assets/ivysaur_diffuse.jpg");
	_resources.load<Sound>("TheHorn", "../assets/dixie_horn.ogg");
	_resources.load<Sound>("Tune", "../assets/Tune.ogg");
}

int main(int argc, char* argv[])
{
	std::shared_ptr<Core> core = Core::init("MMG Demo", 640, 480);
	ResourceManager resources(core);

	load(resources);

	std::shared_ptr<Entity> curuthers = core->addEntity();
	curuthers->addComponent<Player>();
	curuthers->addComponent<MeshRenderer>(
		resources.use<Model>("CuruthersObj"),
		resources.use<Material>("CuruthersMat"));

	std::shared_ptr<Entity> testEntity2 = core->addEntity();
	testEntity2->addComponent<MeshRenderer>(
		resources.use<Model>("IvysaurModel"),
		resources.use<Material>("IvysaurMaterial"));

	std::shared_ptr<SoundSource> voice = curuthers->addComponent<SoundSource>();
	voice->addSound(resources.use<Sound>("TheHorn"));

	curuthers->transform.position.y += 1.0f;
	curuthers->transform.position.z -= 15.0f;
	core->run();
	
	return 0;
}
