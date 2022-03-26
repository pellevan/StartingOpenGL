#include "Timer.h"


Timer::Timer()
{
	m_StartTime = std::chrono::high_resolution_clock::now();
}

void Timer::Reset()
{
	m_StartTime = std::chrono::high_resolution_clock::now();
}

float Timer::getElapsedMS()
{
	auto m_CurrentTime = std::chrono::high_resolution_clock::now();
	auto elapsedMS = std::chrono::duration_cast<std::chrono::microseconds> (m_CurrentTime - m_StartTime);
	return elapsedMS.count() / 1000.f;
}

float Timer::getElapsedSec()
{
	return this->getElapsedMS() / 1000.f;
}