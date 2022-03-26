#include <iostream>
#include <Windows.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"

#include"FPS.h"
#include "Texture.h"
#include "Game.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#define WIDTH 800
#define HEIGHT 600

#ifdef _WIN32
extern "C"
{
	__declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
	__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
}
#endif

void framebuffer_size_callback(GLFWwindow* window, const int width, const int height);



int main()
{
	// Implement deltaTime calculation here
	// ------------------------------------
	float deltaTime = 0.f;

	// Initialize values
	// -----------------
	static bool firstframe = true;
	Game* game = nullptr;
	FPS* fpsMath = nullptr;

	// GLFW initialize and configure
	// -----------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// GLFW window creation + error handling
	// -------------------------------------
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "PresentWorld Engine Alpha", NULL, NULL);
	if (window == nullptr)
	{
		std::cout << "Unable to initialize GLFW window";
		return -1; 
	}

	glfwMakeContextCurrent(window);	// Make created window active (current) context
	glfwSwapInterval(0);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);	// When the user resizes the window, call this Callback function


	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	glViewport(0, 0, WIDTH, HEIGHT); // Tell OpenGL the size of the rendering window
	glEnable(GL_DEPTH_TEST);

	fpsMath = new FPS();
	game = new Game();

	game->SetTarget(window);

	// Event loop
	// ----------
	while (!glfwWindowShouldClose(game->getWindow()))
	{
		if (firstframe)
		{
			game->Start();
			firstframe = false;
		}

		fpsMath->Tick();
		game->Update(static_cast<float>(fpsMath->getFrameTime_sec()));
		game->LateUpdate(static_cast<float>(fpsMath->getFrameTime_sec()));

		glfwSwapBuffers(game->getWindow());
		glfwPollEvents();

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(game->getWindow(), true);
		}
	}
	game->OnApplicationQuit();

	// Cleanup
	// -------
	glfwDestroyWindow(game->getWindow());
	glfwTerminate();

	delete fpsMath;
	delete game;

	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, const int width, const int height)
{
	glViewport(0, 0, width, height);
}