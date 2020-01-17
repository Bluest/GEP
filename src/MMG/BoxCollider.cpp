#include "BoxCollider.h"

void BoxCollider::init()
{
	size = glm::vec3(1.0f, 1.0f, 1.0f);
	offset = glm::vec3(0.0f, 0.0f, 0.0f);
	colliding = false;
}

bool BoxCollider::isCollidingWith(const std::shared_ptr<BoxCollider>& _other)
{
	// if colliding.x
		// if colliding.y
			// if colliding.z
				// return true
	// else return false

	return colliding;
}

void BoxCollider::setSize(const glm::vec3& _size)
{
	size = _size;
}

void BoxCollider::setOffset(const glm::vec3& _offset)
{
	offset = _offset;
}

glm::vec3 BoxCollider::getSize()
{
	return size;
}

void BoxCollider::onUpdate()
{

}
