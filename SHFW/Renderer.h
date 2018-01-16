#ifndef RENDERER_H
#define RENDERER_H

#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "ResourceManager.h"
#include "Entity.h"
#include "Scene.h"
#include "Shader.h"
#include "SHFWConfig.h"

class Renderer
{
public:
	Renderer();
	virtual ~Renderer();

	int init();

	void renderScene(Scene* scene);

	GLFWwindow* window() { return _window; };

	void cleanup();

private:
	ResourceManager _resman;

	GLFWwindow* _window;

	void _renderEntity(glm::mat4 modelMatrix, Entity* entity, Camera* camera);

	void _renderSprite(const glm::mat4 modelMatrix, Sprite* sprite, bool dynamic);

	void _renderLine(const glm::mat4 modelMatrix, Line* line);

	void _renderSpriteBatch(glm::mat4 modelMatrix, std::vector<Sprite*>& sprites, Camera* camera);

	inline void _renderMesh(const glm::mat4 modelMatrix, Shader* shader,
		Mesh* mesh, int numverts, GLuint mode, RGBAColor blendcolor);

	glm::mat4 _projectionMatrix;
	glm::mat4 _viewMatrix;

	Shader* _defaultShader;
};

#endif /* RENDERER_H */
