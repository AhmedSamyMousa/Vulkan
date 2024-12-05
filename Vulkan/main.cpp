#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;


class HelloWorldTriangle
{
public:
	void run()
	{
		initWindow();
		initVulkan();
		mainLoop();
		cleanup();
	}

public:
	GLFWwindow* window;

private:
	void initWindow() {
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(WIDTH, HEIGHT, "HelloWorld", nullptr, nullptr);

	}
	void initVulkan() {

	}

	void mainLoop() {
		while (!glfwWindowShouldClose(window))
		{
			glfwPollEvents();
		}
	}

	void cleanup() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}
};

int main()
{
	HelloWorldTriangle app;
	try
	{
		app.run();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl; return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}