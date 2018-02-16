#ifndef SLIDER_H
#define SLIDER_H

#include "Entity.h"
#include "EmptyObject.h"

class Slider : public Entity
{
public:
	Slider();
	~Slider();

private:
	EmptyObject* point;
};
#endif // !SLIDER_H
