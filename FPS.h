#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class FPS
{
	public:
		FPS();														// Constructor of FPS object

		void Tick();												// Tick

		double getFrameTime();										// Get the time it took for the frame
		double getFPS();											// Get the frames per second with current frametime
	private:
		double previousTime;
		double currentTime;

		double frameTime;
};