#include <iostream>
#include <cstdio>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include "sprite.h"


Sprite::Sprite(std::string image_path)
{
	this->filePath = image_path;
}

Sprite::~Sprite()
{

}
