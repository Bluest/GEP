#include <SDL2/SDL.h>

/** \brief Calculates delta time every frame and caps framerate.
*/
class Time
{
public:
	/** \brief Initialises Time.
		\param _fpsCap Framerate cap
	*/
	void start(const float& _fpsCap);

	/** \brief Called every frame by Core.
	*/
	void tick();

	/** \brief Gets this frame's delta time.
		\return Time::delta
	*/
	float getDelta();

private:
	float prev;
	float curr;
	float delta;
	float target;
};
