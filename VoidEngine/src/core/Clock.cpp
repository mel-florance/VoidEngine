#include "Clock.h"

Clock::Clock() : epoch(std::chrono::high_resolution_clock::now())
{

}

double Clock::getTime()
{
	return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - this->epoch).count() / 1000000000.0;
}

Clock::~Clock()
{

}
