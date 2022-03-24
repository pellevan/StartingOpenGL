#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"

#include"FPS.h"
#include "Texture.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

float vertices[] = {
	// positions          // colors           // texture coords
	 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
	 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
};

unsigned int indices[] = {
	0, 1, 2, 
	3, 2, 0
};

float texCoords[] = {
	0.0f, 0.0f,  // lower-left corner  
	1.0f, 0.0f,  // lower-right corner
	0.5f, 1.0f   // top-center corner
};

int main()
{
	// GLFW initialize and configure
	// -----------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);					// Hint version we are using (3.3) 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);					// "
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	// Using core profile

	// GLFW window creation
	// --------------------
	GLFWwindow* window = glfwCreateWindow(800, 600, "PresentWorld Engine Alpha", NULL, NULL);
	if (window == nullptr)
	{
		std::cout << "Unable to create GLFW window" << std::endl;		// Error message on debug console
		glfwTerminate();												// Terminate GLFW
		return -1;														// Return -1 means: program encountered failure
	}
	glfwMakeContextCurrent(window);										// Make created window active (current) context
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);	// When the user resizes the window, call this Callback function



	// GLAD load all OpenGL function pointers
	// --------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	glViewport(0, 0, 800, 600);											// Tell OpenGL the size of the rendering window



	// Build and compile shader program
	// --------------------------------
	Shader shaderProgram("default.vert", "default.frag");

	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));

	VAO1.LinkVBO(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)nullptr);
	VAO1.LinkVBO(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkVBO(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();



	// Texture stuff
	// -------------
	Texture wood("tex_wood.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	wood.tex_unit(shaderProgram, "texture1", 0);
	Texture stone("tex_stone.jpg", GL_TEXTURE_2D, GL_TEXTURE1, GL_RGB, GL_UNSIGNED_BYTE);
	stone.tex_unit(shaderProgram, "texture2", 1);	

	// Initialize FPS object
	// ---------------------
	FPS fpsProgram;

	stone.Bind();

	// Render loop
	// -----------
	while (!glfwWindowShouldClose(window))
	{
		// Input
		// -----
		processInput(window);

		// FPS Tick
		// --------
		fpsProgram.Tick();
		std::cout << fpsProgram.getFrameTime_ms() << std::endl;

		// Rendering
		// ---------
		glClearColor(48.f/255, 48.f/255, 48.f/255, 1.0f);				// Clear screen color buffer
		glClear(GL_COLOR_BUFFER_BIT);									// "

		shaderProgram.Activate();										// Use  shader program we just created

		stone.Bind();
		wood.Bind();

		VAO1.Bind();													// Bind VAO to keep it organized
		glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, nullptr);

		// Swap the buffers and remaining GLFW events
		// ------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// De-allocate all resources once they've outlived their purpose
	// -------------------------------------------------------------
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();

	// Destroy the window and terminate GLFW
	// -------------------------------------
	glfwDestroyWindow(window);
	glfwTerminate();

	// End
	return 0;
}

/// <summary>
/// Callback function for when user resizes the window
/// </summary>
/// <param name="window">Current window</param>
/// <param name="width">New width</param>
/// <param name="height">New height</param>
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

/// <summary>
/// Process general inputs
/// </summary>
/// <param name="window">Current window</param>
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
