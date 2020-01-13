#include "Player.h"

void Player::init()
{
	// Set the player's start position
	getEntity()->transform.position = glm::vec3(0, -0.5f, -3);
}

void Player::onUpdate()
{
	getEntity()->transform.rotation.y += 90 * getCore()->getDeltaTime();
}
