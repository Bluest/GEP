#include "Cat.h"

void Cat::init()
{
	// Set the cat's initial position
	getEntity()->transform.position = glm::vec3(0.0f, -1.0f, -20.0f);
}

void Cat::onUpdate()
{
	// Rotate
	getEntity()->transform.rotation.y += 90 * getCore()->getDeltaTime();

	// Left mouse button
	if (getCore()->getInput()->isMousePressed(SDL_BUTTON_LEFT))
	{
		std::cout << "LMB pressed at x: " <<
			getCore()->getInput()->getMouseX() << ", y: " <<
			getCore()->getInput()->getMouseX() << std::endl;

		getEntity()->getComponent<SoundSource>()->play("TheHorn");
	}

	// Middle mouse button
	if (getCore()->getInput()->isMousePressed(SDL_BUTTON_MIDDLE))
	{
		getEntity()->getComponent<SoundSource>()->play("TheHorb");
	}

	// Right mouse button
	if (getCore()->getInput()->isMousePressed(SDL_BUTTON_RIGHT))
	{
		std::cout << "RMB pressed at x: " <<
			getCore()->getInput()->getMouseX() << ", y: " <<
			getCore()->getInput()->getMouseX() << std::endl;
	}
}
