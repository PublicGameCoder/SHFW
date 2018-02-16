#include "TargetTexture.h"

TargetTexture::TargetTexture()
{
	//this->registerEvents((void(*)())TargetTexture::resizeTest, EventType::EnumWindowResizeEvent);
	//this->registerEvents((void(*)())TargetTexture::scrollTest, EventType::EnumScrollEvent);
}

TargetTexture::~TargetTexture()
{
}

void TargetTexture::resizeTest(WindowResizeEvent e) {
	Point2i size = e.getSize();
	std::cout << "windowSize: " << size.x << ":" << size.y << std::endl;
}

void TargetTexture::scrollTest(ScrollEvent e) {
	double horizontalValue = e.getHorizontalOffset();
	double verticalValue = e.getVerticalOffset();
	std::cout << "horizontal: " << float(horizontalValue) <<  "| vertical: " << float(verticalValue) << std::endl;
}