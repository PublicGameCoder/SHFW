#include "ShaderManager.h"

ShaderManager::ShaderManager() {
	// link shaders
	shaderProgram = glCreateProgram();
	int loadCount = 0;
	int loadTotal = 0;
	//Load vertex shaders
	std::vector<const char*> shaders = ResourceManager::getManager()->loadAllShaders("./shaders/vertex");
	for each (const char* shader in shaders) {//Attach all loaded shaders
		if (!registerShader(shader, ShaderOption::VERTEX)) {
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << std::endl;
		}
		else {
			loadCount++;
		}
		loadTotal++;
	}
	shaders.clear();
	//Load fragment shaders
	shaders = ResourceManager::getManager()->loadAllShaders("./shaders/fragment");
	for each (const char* shader in shaders) {//Attach all loaded shaders
		if (!registerShader(shader, ShaderOption::FRAGMENT)) {
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << std::endl;
		}
		else {
			loadCount++;
		}
		loadTotal++;
	}
	shaders.clear();
	std::cout << "Shaders loaded: " << loadCount << " out of " << loadTotal << std::endl;

	glLinkProgram(shaderProgram);
	// check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
}

ShaderManager::~ShaderManager() {
	for each (int shader in shaders) {
		glDeleteShader(shader);
	}
}

bool ShaderManager::registerShader(const char* shader, ShaderOption shaderOption) {
	int shade = glCreateShader(shaderOption);
	glShaderSource(shade, 1, &shader, NULL);
	glCompileShader(shade);
	// check for shader compile errors
	glGetShaderiv(shade, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shade, 512, NULL, infoLog);
		switch (shaderOption)
		{
		VERTEX:
			std::cout << "ERROR::SHADER::VERTEXTYPE::COMPILATION_FAILED\n" << infoLog << std::endl;
			break;
		FRAGMENT:
			std::cout << "ERROR::SHADER::FRAGMENTTYPE::COMPILATION_FAILED\n" << infoLog << std::endl;
		default:
			std::cout << "ERROR::SHADER::UNKNOWNTYPE::COMPILATION_FAILED\n" << infoLog << std::endl;
			break;
		}
		return false;
	}
	glAttachShader(shaderProgram, shade);
	return true;
}
