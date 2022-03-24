#pragma once

#include <iostream>
#include <chrono>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class FPS
{
	public:
		FPS();														// Constructor of FPS object

		void Tick();												// Tick

		double getFrameTime_sec() const;								// Get the time it took for the frame
		double getFrameTime_ms() const;
		double getFPS() const;										// Get the frames per second with current frametime
	private:
		std::chrono::high_resolution_clock::time_point previousTime, currentTime;
		float frametime_s;
		long int frametime_us;
};