#include "InputManager.h"

InputManager* InputManager::instance = NULL;

InputManager::InputManager() {

}

InputManager::~InputManager() {

}

InputManager* InputManager::getManager(void) {
	if (!InputManager::instance) {
		InputManager::instance = new InputManager();
	}
	return InputManager::instance;
}


void InputManager::update(GLFWwindow* w) {
	currentWindow = w;

	glfwPollEvents();

	glfwGetWindowSize(this->currentWindow, &windowWidth, &windowHeight);

	glfwGetCursorPos(this->currentWindow, &mouseX, &mouseY);

	mouseX = ((float)1280 / windowWidth) * mouseX;
	mouseY = ((float)720 / windowHeight) * mouseY;

	for (unsigned int i = 32; i<97; i++) {
		processKey(i);
	}
	for (unsigned int i = 255; i<GLFW_KEY_LAST; i++) {
		processKey(i);
	}

	for (unsigned int i = 0; i<GLFW_MOUSE_BUTTON_LAST; i++) {
		processButton(i);
	}
}

void InputManager::processKey(unsigned int key) {
	if (glfwGetKey(this->currentWindow, key) == GLFW_PRESS) {
		if (!PressedKeys[key]) {
			PressedKeys[key] = true;
			KeysDown[key] = true;
			KeysUp[key] = false;
		}
		else {
			KeysDown[key] = false;
		}
	}
	if (glfwGetKey(this->currentWindow, key) == GLFW_RELEASE) {
		if (PressedKeys[key]) {
			PressedKeys[key] = false;
			KeysUp[key] = true;
			KeysDown[key] = false;
		}
		else {
			KeysUp[key] = false;
		}
	}
}

void InputManager::processButton(unsigned int button) {
	if (glfwGetMouseButton(this->currentWindow, button) == GLFW_PRESS) {
		if (mouse[button] == false) {
			mouse[button] = true;
			mouseDown[button] = true;
			mouseUp[button] = false;
		}
		else {
			mouseDown[button] = false;
		}
	}
	if (glfwGetMouseButton(this->currentWindow, button) == GLFW_RELEASE) {
		if (mouse[button] == true) {
			mouse[button] = false;
			mouseUp[button] = true;
			mouseDown[button] = false;
		}
		else {
			mouseUp[button] = false;
		}
	}
}