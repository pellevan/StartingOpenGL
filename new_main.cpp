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

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Game.h"

#ifdef _WIN32
extern "C"
{
	__declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
	__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
}
#endif

// Implement deltaTime calculation here
// ------------------------------------
float deltaTime = 0.f;

// Initialize values
// -----------------
static bool firstframe = true;
Game* game = nullptr;
FPS* fpsMath = nullptr;

int main()
{
	// GLFW initialize and configure
	// -----------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// GLFW window creation + error handling
	// -------------------------------------
	GLFWwindow* window = glfwCreateWindow(800, 600, "PresentWorld Engine Alpha", NULL, NULL);
	if (window == nullptr)
	{
		
	}
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

	return 0;
}