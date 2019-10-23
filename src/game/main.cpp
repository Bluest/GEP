#include <MMG.h>
#include <iostream>

int main()
{
	std::cout << "START" << std::endl;
	std::shared_ptr<Core> core = Core::init();
	// Why not just "Core core;" with a constructor?

	// Entity testEntity;
	// testEntity.addComponent<testComponent>();

	core->run();

	core->quit();
	std::cout << "END" << std::endl;
	return 0;
}