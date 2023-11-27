#include "timer.h"

#include <math.h>

#include "raylib.h"

namespace LeFlappyBird
{
	namespace Timer
	{
		void startTimer(Timer* timer, double lifetime)
		{
			timer->startTime = GetTime();
			timer->lifeTime = lifetime;
			timer->pauseTime = 0;
			timer->paused = false;
		}

		bool timerDone(Timer timer)
		{
			return !timer.paused && GetTime() - timer.startTime >= timer.lifeTime;
		}

		void pauseTimer(Timer* timer)
		{
			timer->pauseTime = GetTime();
			timer->paused = true;
		}

		void unPauseTimer(Timer* timer)
		{
			timer->startTime += GetTime() - timer->pauseTime;
			timer->paused = false;
		}

		double getTimePassed(Timer timer)
		{
			return GetTime() - timer.startTime;
		}

		double getTimerCountDown(Timer timer)
		{
			return timer.startTime - GetTime() + timer.lifeTime + 1;
		}

		bool isTimeLeftLessThan(Timer timer, double lifetimeLeft)
		{
			return !timer.paused && GetTime() - timer.startTime >= timer.lifeTime - lifetimeLeft;
		}

		bool isMillisecondLessThan(Timer timer, double ms)
		{
			double whole, fractional;

			fractional = modf(GetTime() - timer.startTime, &whole);

			return fractional * 1000.0 < ms;
		}

		bool isPaused(Timer timer)
		{
			return timer.paused;
		}
	}
}
