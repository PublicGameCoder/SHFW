#ifndef TIMER_H_
#define TIMER_H_

// Include GLFW
#include <glfw3.h>

class Timer
{
public:
	Timer();
	virtual ~Timer();

	void start();
	void stop();
	void pause();
	void unpause();
	void paused(bool b);

	bool paused() { return _paused; };

	double seconds();

private:
	double _startTicks;
	double _pausedTicks;
	bool _started;
	bool _paused;
	double _tsec();
};

#endif /* TIMER_H_ */
