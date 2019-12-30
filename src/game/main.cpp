#include <MMG.h>
#include <iostream>

int main()
{
	std::shared_ptr<Core> core = Core::init(500, 500);

	std::shared_ptr<Entity> testEntity = core->addEntity();
	std::shared_ptr<MeshRenderer> meshRenderer = testEntity->addComponent<MeshRenderer>(
		"../assets/curuthers/curuthers.obj",
		"../assets/curuthers/Whiskers_diffuse.png");

	std::cout << "START" << std::endl;
	core->run();
	std::cout << "END" << std::endl;
	
	return 0;
}
