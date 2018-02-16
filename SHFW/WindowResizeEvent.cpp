#include "WindowResizeEvent.h"

WindowResizeEvent::WindowResizeEvent(GLFWwindow* window, int newX, int newY) : Event(this) {
	_window = window;
	_size = Point2i(newX, newY);
	_type = EventType::EnumWindowResizeEvent;
}

WindowResizeEvent::~WindowResizeEvent() {

}