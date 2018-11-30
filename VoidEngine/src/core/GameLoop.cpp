#include "GameLoop.h"
#include <QDebug>
#include <QThread>

GameLoop::GameLoop()
{
	this->clock = new Clock();
	this->profiler = new Profiler(this->clock);

	this->profiler->addTimer("frame");
	this->profiler->addTimer("update");
	this->profiler->addTimer("render");
	this->profiler->addTimer("sleep");

	this->running = false;
	this->render = false;
	this->sleepTime = 1;
	this->fps = 0.0f;
	this->lastTime = 0.0;
	this->startTime = 0.0;
	this->frameTime = 1.0 / 60.0f;
	this->frameCounter = 0.0;
	this->unprocessedTime = 0;
	this->frames = 0;
	this->passedTime = 1.0f;
	this->fpsIndex = 0;
	this->fpsSum = 0.0f;
}

void GameLoop::start()
{
	emit updated(this->passedTime, this->fps);
	QThread::msleep(1);

	if (this->running)
		return;

	this->running = true;
	this->lastTime = this->clock->getTime();
	this->frameCounter = 0;
	this->unprocessedTime = 0;
	this->frames = 0;

	while (this->running) 
	{
		this->render = false;
		this->startTime = this->clock->getTime();

		this->passedTime = this->startTime - this->lastTime;
		this->lastTime = this->startTime;

		this->unprocessedTime += this->passedTime;
		this->frameCounter += this->passedTime;

		this->profiler->startTimer("frame");

		if (this->frameCounter >= 0.1f)
		{
			this->fps = this->computeAverageFps(1000.0f / (float)this->passedTime) / 1000000.0f;
			this->frames = 0;
			this->frameCounter = 0;
		}

		if(this->unprocessedTime > this->frameTime)
		{
			this->profiler->startTimer("update");
			emit updated(this->passedTime, this->fps);
			this->profiler->stopTimer("update");
			//QThread::msleep(1);

			this->render = true;
			this->unprocessedTime -= this->frameTime;
		}

		if (this->render)
		{
			this->profiler->startTimer("render");
			emit rendered();
			this->profiler->stopTimer("render");

			this->frames++;
		}
		else
		{
			this->profiler->startTimer("sleep");
	/*		emit updated(this->passedTime); */
			QThread::msleep(1);
			this->profiler->stopTimer("sleep");
		}

		this->profiler->stopTimer("frame");
	}
}

float GameLoop::computeAverageFps(float d)
{
	this->fpsSum -= this->fpsList[this->fpsIndex];
	this->fpsSum += d;
	this->fpsList[this->fpsIndex] = d;

	if (++this->fpsIndex == MAX_SAMPLES)
		this->fpsIndex = 0;

	return this->fpsSum / MAX_SAMPLES;
}

void GameLoop::stop()
{
	this->running = false;
}

GameLoop::~GameLoop()
{
	delete this->profiler;
	delete this->clock;
}
