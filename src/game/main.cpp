#include <MMG.h>
#include <iostream>

int main()
{
	std::shared_ptr<Core> core = Core::init(500, 500);

	std::shared_ptr<Entity> testEntity = core->addEntity();
	std::shared_ptr<MeshRenderer> meshRenderer = testEntity->addComponent<MeshRenderer>(
		"../assets/ivysaur.obj",
		"../assets/ivysaur_diffuse.jpg");

	// TODO: Move resource code to a ResourceManager class, make template functions

	core->loadResource("A.png");
	core->loadResource("B.obj");
	core->loadResource("../C.jpg");
	core->loadResource("assets/D.ogg");
	std::cout << std::endl;

	std::cout << "START" << std::endl;

	std::cout << core->useResource("A.png")->getName() << "\n";
	std::cout << core->useResource("B.obj")->getName() << "\n";
	std::cout << core->useResource("../C.jpg")->getName() << "\n";
	std::cout << core->useResource("assets/D.ogg")->getName() << "\n";
	std::cout << std::endl;

	core->run();
	std::cout << "END" << std::endl;
	
	return 0;
}
