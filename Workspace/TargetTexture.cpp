#include "TargetTexture.h"

TargetTexture::TargetTexture()
{
	//this->registerEvents(std::bind(TargetTexture::resizeTest, this, std::placeholders::_1), EventType::EnumWindowResizeEvent);
}

TargetTexture::~TargetTexture()
{
}

void TargetTexture::resizeTest(WindowResizeEvent e) {
	Point2i size = e.getSize();
	std::cout << "windowSize: " << size.x << ":" << size.y << std::endl;
}