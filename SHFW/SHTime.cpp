#include "SHTime.h"

double Time::deltaTime = 0;

void Time::calcDelta() {
	static double lastTime = glfwGetTime();
	double startTime = glfwGetTime();
	deltaTime = float(startTime - lastTime);
	lastTime = startTime;
}