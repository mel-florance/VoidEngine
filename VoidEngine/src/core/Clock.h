#pragma once

#include <chrono>

class Clock
{
public:
	Clock();
	~Clock();

	double getTime();

private:
	std::chrono::steady_clock::time_point epoch;
};

