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
}