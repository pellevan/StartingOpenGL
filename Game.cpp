#include "Game.h"


float vertices[] = {
	// POSITION			// TEX COORDS // 
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};

glm::vec3 cubePositions[] = {
	glm::vec3(0.0f,  0.0f,  0.0f),
	glm::vec3(2.0f,  5.0f, -15.0f),
	glm::vec3(-1.5f, -2.2f, -2.5f),
	glm::vec3(-3.8f, -2.0f, -12.3f),
	glm::vec3(2.4f, -0.4f, -3.5f),
	glm::vec3(-1.7f,  3.0f, -7.5f),
	glm::vec3(1.3f, -2.0f, -2.5f),
	glm::vec3(1.5f,  2.0f, -2.5f),
	glm::vec3(1.5f,  0.2f, -1.5f),
	glm::vec3(-1.3f,  1.0f, -1.5f)
};

void Game::Start()
{
	// Build and compile shader program
	// --------------------------------
	shaderProgram = new Shader("default.vert", "default.frag");

	VAO1 = new VAO();
	VAO1->Bind();

	VBO1 = new VBO(vertices, sizeof(vertices));


	VAO1->LinkVBO(*VBO1, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)nullptr);
	VAO1->LinkVBO(*VBO1, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));

	VAO1->Unbind();
	VBO1->Unbind();

	stone = new Texture("tex_stone.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	stone->tex_unit(*shaderProgram, "texture1", 0);

	wood = new Texture("tex_wood.jpg", GL_TEXTURE_2D, GL_TEXTURE1, GL_RGB, GL_UNSIGNED_BYTE);
	wood->tex_unit(*shaderProgram, "texture2", 1);

	// Retrieve the matrix uniform locations
	model_location = glGetUniformLocation(shaderProgram->ID, "model");
	view_location = glGetUniformLocation(shaderProgram->ID, "view");
	projection_location = glGetUniformLocation(shaderProgram->ID, "projection");
}

void Game::OnApplicationQuit()
{
	delete shaderProgram;
	delete VAO1;
	delete VBO1;
	delete stone;
	delete wood;
}

void Game::Update(float deltaTime)
{
	// Rendering
	// ---------
	glClearColor(48.f / 255, 48.f / 255, 48.f / 255, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shaderProgram->Activate();


	// Texture stuff
	// -------------
	glm::mat4 model = glm::mat4(1.f);
	glm::mat4 view = glm::mat4(1.f);
	glm::mat4 projection = glm::mat4(1.f);

	model = glm::rotate(model, static_cast<float>(glfwGetTime()) * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
	view = glm::translate(view, glm::vec3(0.f, 0.f, -3.f));
	projection = glm::perspective(glm::radians(45.f), static_cast<float>(800) / static_cast<float>(600), 0.1f, 100.f);

	// Pass them to the shader
	// -----------------------
	glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(view_location, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projection_location, 1, GL_FALSE, glm::value_ptr(projection));

	stone->Bind();
	wood->Bind();

	VAO1->Bind();
	for (GLuint i = 0; i < 10; i++)
	{
		glm::mat4 model = glm::mat4(1.f);
		model = glm::translate(model, cubePositions[i]);
		model = glm::rotate(model, static_cast<float>(glfwGetTime()) * glm::radians(50.f), glm::vec3(0.5f, 1.f, 0.f));
		float angle = 20.f * i;
		model = glm::rotate(model, glm::radians(angle), glm::vec3(1.f, 0.3f, 0.5f));
		glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(model));

		glDrawArrays(GL_TRIANGLES, 0, 36);
	}

}

void Game::LateUpdate(float deltaTime)
{
}

GLFWwindow* Game::getWindow() const
{
	return this->window;
}
