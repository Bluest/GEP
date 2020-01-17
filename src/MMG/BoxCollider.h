#include <list>

#include <glm/glm.hpp>

#include "Component.h"

class BoxCollider : public Component
{
public:
	void init();
	bool isCollidingWith(const std::shared_ptr<BoxCollider>& _other);

	void setSize(const glm::vec3& _size);
	void setOffset(const glm::vec3& _offset);
	glm::vec3 getSize();

private:
	glm::vec3 size;
	glm::vec3 offset;
	bool colliding;
	static std::list<Entity> collidables;

	void onUpdate();
};
