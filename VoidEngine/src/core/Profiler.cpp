#include "Profiler.h"

Profiler::Profiler(Clock* clock)
{
	this->clock = clock;
}

Timer* Profiler::getTimer(const std::string& name)
{
	for (auto &timer : this->timers)
		if (timer.first == name)
			return timer.second;

	return nullptr;
}

void Profiler::addTimer(const std::string& name)
{
	this->timers[name] = new Timer(this->clock);
}

void Profiler::startTimer(const std::string& name)
{
	this->timers[name]->start();
}

void Profiler::stopTimer(const std::string& name)
{
	this->timers[name]->stop();
}

double Profiler::getReport(const std::string& name)
{
	return this->timers[name]->report(0);
}

Profiler::~Profiler()
{
	for (const auto &timer : this->timers)
		delete timer.second;
}