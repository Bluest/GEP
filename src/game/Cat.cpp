#include "Cat.h"

void Player::init()
{
	// Set the player's start position
	getEntity()->transform.position = glm::vec3(0.0f, -1.0f, -5.0f);
}

void Player::onUpdate()
{
	// Rotate
	getEntity()->transform.rotation.y += 90 * getCore()->getDeltaTime();

	// Test controls:

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

	if (getCore()->getInput()->isMousePressed(SDL_BUTTON_LEFT))
	{
		std::cout << "LMB pressed at " <<
			getCore()->getInput()->getMouseX() << ", " <<
			getCore()->getInput()->getMouseX() << "!\n";

		getEntity()->getComponent<SoundSource>()->play("Tune");
	}
}
