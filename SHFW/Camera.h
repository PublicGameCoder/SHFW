#ifndef CAMERA_H
#define CAMERA_H

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "VectorT.h"

class Camera
{
public:
	Camera();
	virtual ~Camera();

	Point3 position;
	Point3 rotation;

	void tilt(float amount) { rotation.x += amount; };

	void pan(float amount)	{ rotation.y += amount; };

	void roll(float amount)	{ rotation.z += amount; };

	void dolly(float amount) { position += (Point3(_direction.x, _direction.y, _direction.z) * amount); };

	void track(float amount) { position += (Point3(_right.x, _right.y, _right.z) * amount); };

	void boom(float amount)	{ position += (Point3(_up.x, _up.y, _up.z) * amount); };

	virtual void updateCamera();

	glm::mat4 viewMatrix() { return _viewMatrix; };

	glm::mat4 projectionMatrix() { return _projectionMatrix; };

	void perspective();

	void orthogonal();

private:
	glm::mat4 _viewMatrix;
	glm::mat4 _projectionMatrix;

	Point3 _offset;

	glm::vec3 _up;
	glm::vec3 _right;
	glm::vec3 _direction;
};

#endif
