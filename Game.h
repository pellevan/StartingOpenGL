#pragma once

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

class Game
{
public:
	void SetTarget(GLFWwindow* window)
	{
		this->window = window;
	}
	void Start();				// Start is called before the first frame update
	void OnApplicationQuit();	// This function is called after all frame updates as the last frame of the objects existence
	void Update( float deltaTime );				// Called once per frame
	void LateUpdate( float deltaTime );			// Called once per frame, after Update() has finished

	void KeyUp();
	void KeyDown();

	GLFWwindow* getWindow() const;

private:
	GLFWwindow* window = nullptr;
	Shader* shaderProgram = nullptr;

	VAO* VAO1;
	VBO* VBO1;

	Texture* stone;
	Texture* wood;

	GLuint model_location;
	GLuint view_location;
	GLuint projection_location;
};
