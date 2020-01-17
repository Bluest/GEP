#include "BoxCollider.h"

void BoxCollider::init()
{

}

bool BoxCollider::isCollidingWith(const std::shared_ptr<BoxCollider>& _other)
{
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
