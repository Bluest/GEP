// rend's <sr1/memory> must be included before <memory>
#include <rend.h>

#include <list>
#include <memory>

#include <SDL2/SDL.h>
#include <AL/alc.h>

class Time;
class Input;
class Entity;
class Camera;

/** \brief Contains the entity component system, as well as other engine features.
	*/
class Core
{
public:
	/** \brief Initialises most engine systems.
		\param _title Title of the game window
		\param _winW Window width
		\param _winH Window height
		\return A pointer to the initialised Core, or nullptr if there was an error
	*/
	static std::shared_ptr<Core> init(const char* _title, const int& _winW, const int& _winH);
	void run();

	/** \brief Adds a new entity to the game.
		\return A pointer to the new entity
	*/
	std::shared_ptr<Entity> addEntity();

	/** \brief Getter for the rend context.
		\return A pointer to the rend context
	*/
	std::sr1::shared_ptr<rend::Context> getRendContext();

	/** \brief Getter for delta time, accessible for other classes.
		\return The amount of time since the previous frame, in seconds
	*/
	float getDeltaTime();

	/** \brief Getter for the input class.
		\return A pointer to Core::input
	*/
	std::shared_ptr<Input> getInput();

	/** \brief Getter for the game's camera.
		\return A pointer to Core::camera
	*/
	std::shared_ptr<Camera> getCamera();

private:
	SDL_Window* window = nullptr;
	SDL_GLContext glContext = NULL;
	std::sr1::shared_ptr<rend::Context> rendContext;
	ALCdevice* alcDevice;
	ALCcontext* alcContext;

	std::weak_ptr<Core> self;
	std::unique_ptr<Time> time;
	std::shared_ptr<Input> input;
	std::shared_ptr<Camera> camera;
	std::list<std::shared_ptr<Entity>> entities;
	bool running = false;

	void quit();
};
