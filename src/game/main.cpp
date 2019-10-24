#include <MMG.h>
#include <iostream>

class TestComponent : public Component
{
private:
	std::weak_ptr<Core> core;

	void onStart()
	{
		printf("yo mama\n");
	}

	void onUpdate()
	{
		printf("ok dying now\n");
		
	}

public:

};

int main()
{
	std::shared_ptr<Core> core = Core::init();
	// Why not just "Core core;" with a constructor?

	// Entity testEntity;
	// testEntity.addComponent<testComponent>();

	std::shared_ptr<Entity> testEntity = std::make_shared<Entity>();
	testEntity->addComponent<TestComponent>();

	std::cout << "START" << std::endl;
	core->run();
	std::cout << "END" << std::endl;

	// Cleanup
	return 0;
}
