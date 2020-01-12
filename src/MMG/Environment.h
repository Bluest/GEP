#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_

#include <SDL2/SDL.h>

class Time
{
public:
	void start(float _fpsCap);
	void tick();
	float getDelta();

private:
	float prev;
	float curr;
	float delta;
	float target;
};

#endif // _ENVIRONMENT_H_
