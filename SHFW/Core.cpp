#include "Core.h"

Core::Core() {

}

Core::~Core() {

}

void Core::run(Scene* scene) {
	//Calculate deltaTime variable
	Time::calcDeltaTime();
	//Update InputManager
	InputManager::getManager()->update(renderManager.getCurrentWindow());

	scene->update();

	renderManager.render(scene);

	if (glfwWindowShouldClose(renderManager.getCurrentWindow())) {
		scene->setRunning(false);
	}
}