#ifndef SCROLLEVENT_H
#define SCROLLEVENT_H

#include "glfw3.h"
#include "PointT.h"
#include "SHEvent.h"

class ScrollEvent : public Event
{
public:
	ScrollEvent(GLFWwindow* window, double xOffset, double yOffset, double xTotal, double yTotal);
	virtual ~ScrollEvent();

	GLFWwindow* getWindow() {
		return _window;
	}

	double getHorizontalOffset() { return _xOffset; }
	double getVerticalOffset() { return _xOffset; }
	double getHorizontalTotal() { return _xOffset; }
	double getVerticalTotal() { return _xOffset; }

private:
	GLFWwindow* _window;
	double _xOffset;
	double _yOffset;
	double _xTotal;
	double _yTotal;
};

#endif // !WINDOWRESIZEEVENT_H
