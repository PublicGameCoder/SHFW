#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <glfw3.h>
#include "InputKeycodes.h"

class InputManager {
public:
	static InputManager* getManager();
	void update(GLFWwindow* window);

private:
	static InputManager* im;

	InputManager();
	virtual ~InputManager();
};

#endif // !INPUTMANAGER_H
