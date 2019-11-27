#include <MMG.h>
#include <iostream>

int main()
{
	std::shared_ptr<Core> core = Core::init();

	std::shared_ptr<Entity> testEntity = core->addEntity();
	std::shared_ptr<MeshRenderer> meshRenderer = testEntity->addComponent<MeshRenderer>("source.obj");

	std::cout << "START" << std::endl;
	core->run();
	std::cout << "END" << std::endl;

	return 0;
}
