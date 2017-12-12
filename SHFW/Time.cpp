#include "Time.h"

double Time::_deltaTime = 0;

void Time::calcDeltaTime() {
	static double lastTime = glfwGetTime();
	double startTime = glfwGetTime();
	_deltaTime = startTime - lastTime;
	lastTime = startTime;
}