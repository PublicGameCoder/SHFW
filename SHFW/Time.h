#ifndef TIME_H
#define TIME_H

#include <glfw3.h>

class Time
{
public:
	static float deltaTime() { return (float)_deltaTime; };
	static void calcDeltaTime();
private:
	static double _deltaTime;
};

#endif // !TIME_H
