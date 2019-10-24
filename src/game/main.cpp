#include <MMG.h>
#include <iostream>

class TestComponent : public Component
{
private:
	int countdown;

	void onStart()
	{
		printf("TestComponent started\n");
	}

	void onUpdate()
	{
		if (--countdown > 0) printf("%i", countdown);
		else
		{
			printf("ok dying now\n");
			getCore()->quit();
		}
	}

public:
	TestComponent(int _countdown)
	{
		countdown = _countdown;
	}
};

int main()
{
	std::shared_ptr<Core> core = Core::init();
	// Why not just "Core core;" with a constructor?

	std::shared_ptr<Entity> testEntity = std::make_shared<Entity>();
	testEntity->addComponent<TestComponent>();

	std::cout << "START" << std::endl;
	core->run();
	std::cout << "END" << std::endl;

	// Cleanup
	return 0;
}
