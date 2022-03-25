#pragma once

#include <GLFW/glfw3.h>

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
};
