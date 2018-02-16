#include "WindowResizeEvent.h"

WindowResizeEvent::WindowResizeEvent(GLFWwindow* window, int newX, int newY) : Event() {
	_window = window;
	_size = Point2i(newX, newY);
	_type = EventType::EnumWindowResizeEvent;
}

WindowResizeEvent::~WindowResizeEvent() {

}