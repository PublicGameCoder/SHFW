#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include <glfw3.h>

class RenderManager
{
public:
	RenderManager();
	virtual ~RenderManager();

	GLFWwindow* getCurrentWindow() { return NULL; }
private:

};

#endif // RENDERMANAGER_H
