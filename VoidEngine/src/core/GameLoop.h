#pragma once

#include <QObject>
#include <QTimer>
#include <QElapsedTimer>

#include "Clock.h"
#include "Profiler.h"

#define MAX_SAMPLES 120

class GameLoop : public QObject
{
	Q_OBJECT

public:
	GameLoop();

	void stop();

	inline bool isRunning() { return this->running; }
	inline Profiler* getProfiler() { return this->profiler; }
	inline Clock* getClock() { return this->clock; }

	inline double getFrameTime() { return this->frameTime; }
	inline double getPassedTime() { return this->passedTime; }
	inline float getFps() { return this->fps; }

	float computeAverageFps(float fps);

	~GameLoop();

signals:
	void updated(float delta, float fps);
	void rendered();
	void fpsTick(float fps);

public slots:
	void start();

private:
	bool running;
	bool render;
	int sleepTime;
	float fps;
	double lastTime;
	double startTime;
	double frameTime;
	double frameCounter;
	double unprocessedTime = 0;
	int frames = 0;
	double passedTime;

	int fpsIndex;
	float fpsSum;
	float fpsList[MAX_SAMPLES];

	Clock* clock;
	Profiler* profiler;
};
