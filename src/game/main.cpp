#include <MMG.h>
#include <iostream>

int main()
{
	std::shared_ptr<Core> core = Core::init(500, 500);
	ResourceManager resources;

	std::shared_ptr<Entity> testEntity = core->addEntity();
	std::shared_ptr<MeshRenderer> meshRenderer = testEntity->addComponent<MeshRenderer>(
		"../assets/ivysaur.obj",
		"../assets/ivysaur_diffuse.jpg");

	resources.load<Material>("A.png");
	resources.load<Model>("B.obj");
	resources.load<Model>("C.obj");
	resources.load<Material>("D.jpg");

	std::cout << "START" << std::endl;
	core->run();
	std::cout << "END" << std::endl;
	
	return 0;
}
