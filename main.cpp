//#include <iostream>
//#include <Windows.h>
//
//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <stb/stb_image.h>
//
//#include"shaderClass.h"
//#include"VAO.h"
//#include"VBO.h"
//#include"EBO.h"
//
//#include"FPS.h"
//#include "Texture.h"
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//#ifdef _WIN32
//extern "C"
//{
//	__declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
//	__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
//}
//
//#endif
//
//void framebuffer_size_callback(GLFWwindow* window, const int width, const int height);
//void process_input(GLFWwindow* window);
//
//float vertices[] = {
//	// POSITION			// TEX COORDS // 
//	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//};
//
//unsigned int indices[] = {
//	0, 1, 2, 
//	3, 2, 0
//};
//
//float texCoords[] = {
//	0.0f, 0.0f,  // lower-left corner  
//	1.0f, 0.0f,  // lower-right corner
//	0.5f, 1.0f   // top-center corner
//};
//
//glm::vec3 cubePositions[] = {
//	glm::vec3(0.0f,  0.0f,  0.0f),
//	glm::vec3(2.0f,  5.0f, -15.0f),
//	glm::vec3(-1.5f, -2.2f, -2.5f),
//	glm::vec3(-3.8f, -2.0f, -12.3f),
//	glm::vec3(2.4f, -0.4f, -3.5f),
//	glm::vec3(-1.7f,  3.0f, -7.5f),
//	glm::vec3(1.3f, -2.0f, -2.5f),
//	glm::vec3(1.5f,  2.0f, -2.5f),
//	glm::vec3(1.5f,  0.2f, -1.5f),
//	glm::vec3(-1.3f,  1.0f, -1.5f)
//};
//
//int main()
//{
//	// GLFW initialize and configure
//	// -----------------------------
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);					// Hint version we are using (3.3) 
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);					// "
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	// Using core profile
//
//	// GLFW window creation
//	// --------------------
//	GLFWwindow* window = glfwCreateWindow(800, 600, "PresentWorld Engine Alpha", NULL, NULL);
//	if (window == nullptr)
//	{
//		std::cout << "Unable to create GLFW window" << std::endl;		// Error message on debug console
//		glfwTerminate();												// Terminate GLFW
//		return -1;														// Return -1 means: program encountered failure
//	}
//	glfwMakeContextCurrent(window);										// Make created window active (current) context
//	glfwSwapInterval(0);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);	// When the user resizes the window, call this Callback function
//
//
//
//	// GLAD load all OpenGL function pointers
//	// --------------------------------------
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//	glViewport(0, 0, 800, 600);											// Tell OpenGL the size of the rendering window
//	glEnable(GL_DEPTH_TEST);
//
//
//
//	// Build and compile shader program
//	// --------------------------------
//	Shader shaderProgram("default.vert", "default.frag");
//
//	VAO VAO1;
//	VAO1.Bind();
//
//	VBO VBO1(vertices, sizeof(vertices));
//	EBO EBO1(indices, sizeof(indices));
//
//	VAO1.LinkVBO(VBO1, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)nullptr);					// POS
//	VAO1.LinkVBO(VBO1, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));		// TEX COORDS
//	//VAO1.LinkVBO(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//	VAO1.Unbind();
//	VBO1.Unbind();
//	EBO1.Unbind();
//
//	Texture stone("tex_stone.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
//	stone.tex_unit(shaderProgram, "texture1", 0);
//	Texture wood("tex_wood.jpg", GL_TEXTURE_2D, GL_TEXTURE1, GL_RGB, GL_UNSIGNED_BYTE);
//	wood.tex_unit(shaderProgram, "texture2", 1);
//
//	// retrieve the matrix uniform locations
//	GLuint modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
//	GLuint viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
//	GLuint projectionLoc = glGetUniformLocation(shaderProgram.ID, "projection");
//
//	// Initialize FPS object
//	// ---------------------
//	FPS fpsProgram;
//
//	// Render loop
//	// -----------
//	while (!glfwWindowShouldClose(window))
//	{
//		int current_width, current_height;
//		glfwGetWindowSize(window, &current_width, &current_height);
//
//		float FOV = 45.f;
//		// Input
//		// -----
//		process_input(window);
//
//		// FPS Tick
//		// --------
//		fpsProgram.Tick();
//
//		// Rendering
//		// ---------
//		glClearColor(48.f/255, 48.f/255, 48.f/255, 1.0f);				// Clear screen color buffer
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				// "
//
//		shaderProgram.Activate();										// Use  shader program we just created
//
//		// Texture stuff
//		// -------------
//		glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
//		glm::mat4 view = glm::mat4(1.0f);
//		glm::mat4 projection = glm::mat4(1.0f);
//		model = glm::rotate(model, static_cast<float>(glfwGetTime()) * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
//		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
//		projection = glm::perspective(glm::radians(FOV), static_cast<float>(current_width) / static_cast<float>(current_height), 0.1f, 100.0f);
//
//		// Pass them to the shader
//		// -----------------------
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
//
//		stone.Bind();
//		wood.Bind();
//
//		VAO1.Bind();													// Bind VAO to keep it organized
//		for(GLuint i = 0; i < 10; i++)
//		{
//			glm::mat4 model = glm::mat4(1.0f);
//			model = glm::translate(model, cubePositions[i]);
//			model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
//			float angle = 20.0f * i;
//			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
//
//		// Swap the buffers and remaining GLFW events
//		// ------------------------------------------
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	// De-allocate all resources once they've outlived their purpose
//	// -------------------------------------------------------------
//	VAO1.Delete();
//	VBO1.Delete();
//	EBO1.Delete();
//	shaderProgram.Delete();
//
//	// Destroy the window and terminate GLFW
//	// -------------------------------------
//	glfwDestroyWindow(window);
//	glfwTerminate();
//
//	// End
//	return 0;
//}
//
///// <summary>
///// Callback function for when user resizes the window
///// </summary>
///// <param name="window">Current window</param>
///// <param name="width">New width</param>
///// <param name="height">New height</param>
//void framebuffer_size_callback(GLFWwindow* window, const int width, const int height)
//{
//	glViewport(0, 0, width, height);
//}
//
///// <summary>
///// Process general inputs
///// </summary>
///// <param name="window">Current window</param>
//void process_input(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//}
