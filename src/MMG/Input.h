#include <list>

#include <SDL2/SDL.h>

/** \brief Handles keyboard and mouse input.
*/
class Input
{
public:
	// Keyboard

	/** \brief Checks whether a specific key is being held.
		\param _key The key being checked
		\return True if the key is held, false otherwise
	*/
	bool isKeyHeld(const SDL_Keycode& _key);

	/** \brief Checks whether a specific key has been pressed this frame.
		\param _key The key being checked
		\return True if the key was pressed, false otherwise
	*/
	bool isKeyPressed(const SDL_Keycode& _key);

	/** \brief Checks whether a specific key has been released this frame.
		\param _key The key being checked
		\return True if the key was released, false otherwise
	*/
	bool isKeyReleased(const SDL_Keycode& _key);

	// Mouse

	/** \brief Checks whether a specific mouse button is being held.
		\param _button The mouse button being checked
		\return True if the mouse button is held, false otherwise
	*/
	bool isMouseHeld(const int& _button);

	/** \brief Checks whether a specific mouse button has been pressed this frame.
		\param _key The mouse button being checked
		\return True if the mouse button was pressed, false otherwise
	*/
	bool isMousePressed(const int& _button);

	/** \brief Checks whether a specific mouse button has been released this frame.
		\param _key The mouse button being checked
		\return True if the mouse button was released, false otherwise
	*/
	bool isMouseReleased(const int& _button);

	/** \brief Gets the mouse's current x position in the game window.
		\return The mouse's current x position
	*/
	int getMouseX();

	/** \brief Gets the mouse's current y position in the game window.
		\return The mouse's current y position
	*/
	int getMouseY();

	/** \brief Polls an SDL_Event to determine the user's input this frame.
		\param _event A pointer to the SDL_Event being polled
		\return False if the user has requested to close the game window, true otherwise
	*/
	bool processInput(SDL_Event* _event);

private:
	// Keyboard
	std::list<SDL_Keycode> keysHeld;
	std::list<SDL_Keycode> keysPressed;
	std::list<SDL_Keycode> keysReleased;

	// Mouse
	std::list<int> mouseHeld;
	std::list<int> mousePressed;
	std::list<int> mouseReleased;
	int mouseX;
	int mouseY;

	void processKeyDown(const SDL_Keycode& _key);
	void processKeyUp(const SDL_Keycode& _key);
	void processMouseDown(const int& _button);
	void processMouseUp(const int& _button);
};
