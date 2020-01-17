#include "CameraController.h"

void CameraController::onUpdate()
{
	// WASD controls
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

	// Q to go down
	if (getCore()->getInput()->isKeyHeld(SDLK_q))
	{
		getCore()->getCamera()->move({ 0.0f, 5.0f * getCore()->getDeltaTime(), 0.0f });
	}

	// E to go up
	if (getCore()->getInput()->isKeyHeld(SDLK_e))
	{
		getCore()->getCamera()->move({ 0.0f, -5.0f * getCore()->getDeltaTime(), 0.0f });
	}
}
