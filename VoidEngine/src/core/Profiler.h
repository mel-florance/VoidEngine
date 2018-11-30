#pragma once

#include <map>
#include <string>

#include "Timer.h"

class Profiler
{
public:
	Profiler(Clock* clock);
	~Profiler();

	Timer* getTimer(const std::string& name);
	void addTimer(const std::string& name);
	void stopTimer(const std::string& name);
	void startTimer(const std::string& name);
	double getReport(const std::string& name);

private:
	Clock* clock;
	std::map<std::string, Timer*> timers;
};
