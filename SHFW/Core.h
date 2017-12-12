#ifndef CORE_H
#define CORE_H

#include "RenderManager.h"
#include <glfw3.h>
#include "Scene.h"
#include "Time.h"
#include "InputManager.h"

class Core {
public:
	Core();
	virtual ~Core();
	
	void run(Scene* scene);

private:
	RenderManager renderManager;
};

#endif // !CORE_H
