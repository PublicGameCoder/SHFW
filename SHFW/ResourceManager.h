#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <iostream>
#include <string>
#include <map>

// Include GLAD
#include <glad\glad.h>

// Include GLFW
#include <glfw3.h>

#include "SHFWConfig.h"
#include "Shader.h"
#include "Texture.h"
#include "Mesh.h"

class ResourceManager
{
public:
	ResourceManager();
	virtual ~ResourceManager();

	Texture* getTexture(const std::string& filename, int filter, int wrap);

	Mesh* getSpriteMesh(int width, int height, float pivotx, float pivoty, float uvwidth, float uvheight, int circle, int which);
	Mesh* getCubeMesh(int width, int height, int depth, float pivotx, float pivoty, float pivotz, float uvwidth, float uvheight, int circle, int which);

	Mesh* getLineMesh(Line* line);

	Shader* getShader(const std::string& vs, const std::string& fs);

	void cleanup();

private:

	void deleteTexture(const std::string& filename);

	void deleteMesh(const std::string& meshname);

	void deleteShader(const std::string& shadername);

	std::map<std::string, Texture*> _textures;
	std::map<std::string, Mesh*> _meshes;
	std::map<std::string, Shader*> _shaders;
};

#endif /* RESOURCEMANAGER_H */
