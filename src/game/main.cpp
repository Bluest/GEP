#include <MMG.h>
#include <iostream>

int main()
{
	std::shared_ptr<Core> core = Core::init();
	// Why not just "Core core;" with a constructor?
	// Maybe make it a unique_ptr?

	std::shared_ptr<Entity> testEntity = core->addEntity();
	testEntity->addComponent<TriangleRenderer>();
	testEntity->getComponent<TriangleRenderer>();

	std::cout << "START" << std::endl;
	core->run();
	std::cout << "END" << std::endl;

	// Cleanup? Or is that handled in Core?
	return 0;
}
