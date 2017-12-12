#include "RenderManager.h"	

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

RenderManager::RenderManager() {
	this->init();
}

int RenderManager::init() {
	if (!glfwInit())
	{
		std::cout << "GLFW Initialization failed" << std::endl;
		std::cout << "Aborting!" << std::endl;
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

	GLFWmonitor* primary = glfwGetPrimaryMonitor();
	if (FULLSCREEN) {
		currentWindow = glfwCreateWindow(640, 480, SHFWTITLE, glfwGetPrimaryMonitor(), NULL);
	}
	else {
		currentWindow = glfwCreateWindow(640, 480, SHFWTITLE, NULL, NULL);
	}

	if (!currentWindow)
	{
		std::cout << "Window creation failed" << std::endl;
		std::cout << "Aborting!" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(currentWindow);
	glfwSetFramebufferSizeCallback(currentWindow, framebuffer_size_callback);

	// Initialize GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	//////////////////////////////////////////////////
	glfwSetWindowSizeLimits(currentWindow, MINWINDOWWIDTH, MINWINDOWHEIGHT, MAXWINDOWWIDTH, MAXWINDOWHEIGHT);

	glfwSwapInterval(VSYNC);

	glfwMakeContextCurrent(currentWindow);
	
	glfwSetInputMode(currentWindow, GLFW_STICKY_KEYS, GL_TRUE);

	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);

}

RenderManager::~RenderManager() {
	glfwTerminate();
}

void RenderManager::render(Scene* scene) {
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glfwSwapBuffers(currentWindow);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
	std::cout << "width: " << width << " | height: " << height << std::endl;
}