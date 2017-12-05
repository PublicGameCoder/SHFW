#include <iostream>

#include <SHFW/Core.h>

int main() {
	std::cout << "Starting up" << std::endl;

	Core core;

	Scene* scene = new Scene();
	while (scene->isRunning()) {
		core.run(scene);
	}
	delete scene;

	return 0;
}