#include "Timer.h"

Timer::Timer(Clock* clock)
{
	this->clock = clock;
}

void Timer::start()
{
	this->startTime = this->clock->getTime();
}

void Timer::stop()
{
	this->calls++;
	this->totalTime += (this->clock->getTime() - this->startTime);
	this->startTime = 0;
}

double Timer::report(double divisor)
{
	divisor = (divisor == 0) ? this->calls : divisor;
	double result = (this->totalTime == 0 && divisor == 0.0) ? 0.0 : (1000.0 * this->totalTime) / ((double)divisor);

	this->totalTime = 0.0;
	this->calls = 0;

	return result;
}

Timer::~Timer()
{

}