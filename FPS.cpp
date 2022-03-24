#include "FPS.h"


FPS::FPS()
{
	previousTime = currentTime = std::chrono::high_resolution_clock::now();
}

void FPS::Tick()
{
	currentTime = std::chrono::high_resolution_clock::now();
	frametime_us = (std::chrono::duration_cast<std::chrono::microseconds>(currentTime - previousTime).count());
	frametime_s = frametime_us / 1e6f;
	previousTime = currentTime;
}

double FPS::getFrameTime_sec() const
{
	return frametime_s;
}

double FPS::getFrameTime_ms() const
{
	return frametime_us / 1000.f;
}


double FPS::getFPS() const
{
	return 1.0f / getFrameTime_sec(); // NOT CORRECT WAY OF RETRIEVING FPS ---> TO IMPROVE
}
