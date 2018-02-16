#include "ScrollEvent.h"

ScrollEvent::ScrollEvent(GLFWwindow* window, double xOffset, double yOffset, double xTotal, double yTotal) : Event() {
	_window = window;
	_xOffset = xOffset;
	_yOffset = yOffset;
	_xTotal = xTotal;
	_yTotal = yTotal;
	_type = EventType::EnumScrollEvent;
}

ScrollEvent::~ScrollEvent() {

}