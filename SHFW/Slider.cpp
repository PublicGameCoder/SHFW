#include "Slider.h"

Slider::Slider() {
	point = new EmptyObject();
	point->addSprite("assets/dot.tga");
	this->addChild(point);
}

Slider::~Slider() {
	delete point;
}