#ifndef WINDOWRESIZEEVENT_H
#define WINDOWRESIZEEVENT_H

#include "glfw3.h"
#include "PointT.h"
#include "SHEvent.h"

class WindowResizeEvent : public Event
{
public:
	WindowResizeEvent(GLFWwindow* window ,int newX, int newY);
	virtual ~WindowResizeEvent();

	Point2i getSize() {
		return _size;
	}

	GLFWwindow* getWindow() {
		return _window;
	}
private:
	GLFWwindow* _window;
	Point2i _size;
};

#endif // !WINDOWRESIZEEVENT_H
