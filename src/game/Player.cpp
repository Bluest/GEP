#include "Player.h"

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
		getEntity()->transform.position.z += 5.0f * getCore()->getDeltaTime();
	}

	if (getCore()->getInput()->isKeyHeld(SDLK_s))
	{
		getEntity()->transform.position.z -= 5.0f * getCore()->getDeltaTime();
	}

	if (getCore()->getInput()->isMousePressed(SDL_BUTTON_LEFT))
	{
		std::cout << "LMB pressed at " <<
			getCore()->getInput()->getMouseX() << ", " <<
			getCore()->getInput()->getMouseX() << "!\n";
	}
}
