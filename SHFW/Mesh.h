#ifndef MESH_H
#define MESH_H

#include "Line.h"
#include "VectorT.h"
#include "SHFWConfig.h"

// Include GLAD
#include <glad\glad.h>

class Mesh
{
public:
	Mesh();
	virtual ~Mesh();

	GLuint vertexbuffer() { return _vertexbuffer; };

	GLuint uvbuffer() { return _uvbuffer; };

	void generateSpriteMesh(int width, int height,
		float pivotx, float pivoty,
		float uvwidth, float uvheight
	);

	void generateLineMesh(Line* line);

	void generateCircleMesh(int radius, int segments, float uvwidth, float uvheight);

	void generateSegmentMesh(int radius, int segments, int which);

	void generateCubeMesh(
		int width, int height, int depth,
		float pivotx, float pivoty, float pivotz,
		float uvwidth, float uvheight
	);

	unsigned int numverts() { return _numverts; };

private:
	GLuint _vertexbuffer;
	GLuint _normalbuffer;
	GLuint _uvbuffer;

	unsigned int _numverts;

	void generateBuffers(std::vector<glm::vec3>& vertex, std::vector<glm::vec2>& uv);
};

#endif /* MESH_H */
