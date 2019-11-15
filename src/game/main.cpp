#include <MMG.h>
#include <iostream>

int main()
{
	std::shared_ptr<Core> core = Core::init();
	// Why not just "Core core;" with a constructor?

	std::shared_ptr<Entity> testEntity = core->addEntity();
	std::shared_ptr<TriangleRenderer> triangleRenderer = testEntity->addComponent<TriangleRenderer>();

	std::cout << "START" << std::endl;
	core->run();
	std::cout << "END" << std::endl;

	// Cleanup? Or is that handled in Core?
	return 0;
}
