#include "InputManager.h"

InputManager::InputManager() {

}

InputManager::~InputManager() {

}

InputManager* InputManager::getManager() {
	if (!InputManager::im) {
		InputManager::im = new InputManager();
	}
	return InputManager::im;
}

void InputManager::update(GLFWwindow* window) {

}