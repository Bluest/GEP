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
}
