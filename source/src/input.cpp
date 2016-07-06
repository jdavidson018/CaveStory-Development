#include "input.h"

/* Input class
 * Keep track of keyboard state
 */

//this function gets called at beginning of each frame to reset irrelevant keys
void Input::beginNewFrame()
{
	this->_pressedKeys.clear();
	this->_releasedKeys.clear();
}

//this function is called when key is pressed
void Input::keyDownEvent(const SDL_Event& event)
{
	this->_pressedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = true;
}

//this function is called when key is released
void Input::keyUpEvent(const SDL_Event& event)
{
	this->_releasedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = false;
}

//checks if a certain key was pressed during current frame
bool Input::wasKeyPressed(SDL_Scancode key)
{
	return this->_pressedKeys[key];
}

//checks if a certain key was released during current frame
bool Input::wasKeyReleased(SDL_Scancode key)
{
	return this->_releasedKeys[key];
}

//checks if a certain key is currently being held
bool Input::isKeyHeld(SDL_Scancode key)
{
	return this->_heldKeys[key];
}