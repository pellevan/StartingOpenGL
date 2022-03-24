#include "FPS.h"

FPS::FPS()
{
	currentTime = glfwGetTime();
	previousTime = 0.0;

	frameTime = 0.0;
}

void FPS::Tick()
{
	double currentTime = glfwGetTime();
	frameTime = currentTime - previousTime;
	previousTime = currentTime;
}

double FPS::getFrameTime()
{
	return frameTime;
}

double FPS::getFPS()
{
	return 1.0 / frameTime;
}
