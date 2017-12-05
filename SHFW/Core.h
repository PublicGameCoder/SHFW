#ifndef CORE_H
#define CORE_H

#include <glfw3.h>
#include "Scene.h"
#include "Time.h"
#include "RenderManager.h"
#include "InputManager.h"

class Core {
public:
	Core();
	virtual ~Core();
	
	void run(Scene* scene);

private:
	RenderManager renderManager;
	void calcDeltaTime();
};

#endif // !CORE_H
