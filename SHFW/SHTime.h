#ifndef TIME_H
#define TIME_H

#include <glfw3.h>

class Time
{
public:
	static double deltaTime;
	static void calcDelta();
};

#endif // !TIME_H
