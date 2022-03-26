#pragma once

#include <iostream>
#include <chrono>
#include <atomic>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Timer
{
	public:
		Timer(); // Constructor of FPS object

		void Reset();			// Start the timer
		float getElapsedMS();	// Get time elapsed from last .Reset()
		float getElapsedSec();
	private:
		std::chrono::time_point<std::chrono::steady_clock> m_StartTime;
};