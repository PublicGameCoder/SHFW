#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include <glad/glad.h>
#include <glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include "SHFWConfig.h"
#include "Scene.h"
#include "Sprite.h"
#include "Camera.h"

class RenderManager
{
public:
	RenderManager();
	virtual ~RenderManager();

	void render(Scene* scene);

	GLFWwindow* getCurrentWindow() { return currentWindow; }

private:
	GLFWwindow* currentWindow;

	glm::mat4 _projectionMatrix;

	int init();
};

#endif // RENDERMANAGER_H
