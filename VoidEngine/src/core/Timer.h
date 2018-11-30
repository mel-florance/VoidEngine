#pragma once

#include "Clock.h"

class Timer
{
public:
	Timer(Clock* clock);
	~Timer();

	void start();
	void stop();
	double report(double divisor);

private:
	int calls;
	Clock* clock;
	double startTime;
	double totalTime;
};