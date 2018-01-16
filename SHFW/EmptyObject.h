#ifndef EMPTYOBJECT_H
#define EMPTYOBJECT_H

#include "Entity.h"
#include "SHMath.h"

class EmptyObject : public Entity {
public:
	EmptyObject();
	virtual ~EmptyObject();
	virtual void update();
};

#endif // !EMPTYOBJECT_H
