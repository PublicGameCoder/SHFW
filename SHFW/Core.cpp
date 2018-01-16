#include "Core.h"

Core::Core()
{

}

Core::~Core()
{

}

void Core::run(Scene* scene)
{
	// update our Time::deltaTime
	Time::calcDelta();

	// Update Input singleton instance
	InputManager::getManager()->update(_renderer.window());

	// Update camera instance in Scene
	scene->camera()->updateCamera();

	// Update Scene (and recursively all children)
	scene->updateScene();

	// Render Scene
	_renderer.renderScene(scene);

	// user clicked the 'close' button in the window
	if (glfwWindowShouldClose(_renderer.window()) == 1) { scene->isRunning(false); }
}

void Core::showFrameRate(float numsecs)
{
	static int frames = 0;
	static double time = 0;

	frames++;
	time += Time::deltaTime;
	if (time >= numsecs) {
		printf("%f ms/frame (%f FPS)\n", (numsecs*1000)/double(frames), frames/numsecs);
		frames = 0;
		time = 0;
	}
}

void Core::cleanup()
{
	_renderer.cleanup();
}
