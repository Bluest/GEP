#include <Environment.h>

void Time::start(float _fpsCap)
{
	prev = float(SDL_GetTicks());
	target = 1.0f / _fpsCap;
	delta = target;
}

void Time::tick()
{
	curr = float(SDL_GetTicks());
	delta = (curr - prev) / 1000.0f;
	prev = curr;

	// Cap FPS at _fpsCap
	if (delta < target)
	{
		SDL_Delay(Uint32((target - delta) * 1000.0f));
	}
}

float Time::getDelta()
{
	return delta;
}
