#include "Camera.h"

Camera::Camera(const int& _winW, const int& _winH)
{
	position = glm::vec3(0.0f, 0.0f, 0.0f);
	rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	projection = glm::perspective(glm::radians(45.0f), float(_winW) / _winH, 0.1f, 100.0f);
	view = glm::mat4(1.0f);
}

void Camera::move(const glm::vec3& _step)
{
	position += _step;
}

void Camera::rotate(const glm::vec3& _step)
{
	rotation += _step;
}

void Camera::setPosition(const glm::vec3& _position)
{
	position = _position;
}

void Camera::setRotation(const glm::vec3& _rotation)
{
	rotation = _rotation;
}

glm::vec3 Camera::getPosition()
{
	return position;
}

glm::vec3 Camera::getRotation()
{
	return rotation;
}

glm::mat4 Camera::getProjection()
{
	return projection;
}

glm::mat4 Camera::getView()
{
	return view;
}
