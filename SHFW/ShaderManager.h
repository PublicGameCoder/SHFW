#ifndef SHADERMANAGER_H
#define SHADERMANAGER_H

#include <glad/glad.h>
#include <glfw3.h>

#include "SHFWConfig.h"
#include "ResourceManager.h"
#include <iostream>
#include <vector>

enum ShaderOption;

class ShaderManager
{
public:
	ShaderManager();
	~ShaderManager();

private:
	int shaderProgram;
	std::vector<int> shaders;
	int success;
	char infoLog[512];
	bool registerShader(const char* shader, ShaderOption shaderOption);
};

enum ShaderOption {
	VERTEX = GL_VERTEX_SHADER,
	FRAGMENT = GL_FRAGMENT_SHADER
};

#endif // !SHADERMANAGER_H
