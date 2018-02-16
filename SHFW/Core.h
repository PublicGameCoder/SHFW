#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "SHTime.h"
#include "Renderer.h"
#include "InputManager.h"
#include "Scene.h"

class Core
{
public:
	Core();
	virtual ~Core();

	void run(Scene* scene);

	void cleanup();

	void showFrameRate(float numsecs);

private:
	Renderer _renderer;
};

#endif /* CORE_H */
