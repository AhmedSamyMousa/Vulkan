#include <stdio.h>
#include <stdlib.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 720

GLFWwindow* window = NULL;

void GLFW_KeyCallback(GLFWwindow* winodw, int key, int scancode, int action, int mods)
{
	if ((key == GLFW_KEY_ESCAPE) && (action == GLFW_PRESS))
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

int main(int argc, char* argv[])
{
	if (!glfwInit()) {return 1;}
	if (!glfwVulkanSupported()) { return 1; }

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Vulkan", NULL, NULL);
	if (!window) { glfwTerminate(); exit(EXIT_FAILURE); }
	glfwSetKeyCallback(window, GLFW_KeyCallback);


	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
