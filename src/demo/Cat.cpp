#include "Cat.h"

void Cat::init()
{
	// Set the player's start position
	getEntity()->transform.position = glm::vec3(0.0f, -1.0f, -5.0f);
}

void Cat::onUpdate()
{
	// Rotate
	getEntity()->transform.rotation.y += 90 * getCore()->getDeltaTime();

	// Camera:
	// WASD Controls
	if (getCore()->getInput()->isKeyHeld(SDLK_w))
	{
		getCore()->getCamera()->move({ 0.0f, 0.0f, 5.0f * getCore()->getDeltaTime() });
	}

	if (getCore()->getInput()->isKeyHeld(SDLK_s))
	{
		getCore()->getCamera()->move({ 0.0f, 0.0f, -5.0f * getCore()->getDeltaTime() });
	}

	if (getCore()->getInput()->isKeyHeld(SDLK_a))
	{
		getCore()->getCamera()->move({ 5.0f * getCore()->getDeltaTime(), 0.0f, 0.0f });
	}

	if (getCore()->getInput()->isKeyHeld(SDLK_d))
	{
		getCore()->getCamera()->move({ -5.0f * getCore()->getDeltaTime(), 0.0f, 0.0f });
	}

	// Press E to go up
	if (getCore()->getInput()->isKeyHeld(SDLK_e))
	{
		getCore()->getCamera()->move({ 0.0f, -5.0f * getCore()->getDeltaTime(), 0.0f });
	}

	// Press Q to go down
	if (getCore()->getInput()->isKeyHeld(SDLK_q))
	{
		getCore()->getCamera()->move({ 0.0f, 5.0f * getCore()->getDeltaTime(), 0.0f });
	}

	// Left mouse button
	if (getCore()->getInput()->isMousePressed(SDL_BUTTON_LEFT))
	{
		std::cout << "LMB pressed at " <<
			getCore()->getInput()->getMouseX() << ", " <<
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
		std::cout << "RMB pressed at " <<
			getCore()->getInput()->getMouseX() << ", " <<
			getCore()->getInput()->getMouseX() << std::endl;
	}
}
