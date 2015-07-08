#ifndef TIMER_H
#define TIMER_H

#include <iostream>

#include <SDL2/SDL.h>

namespace cub
{
	class Timer
	{
	public:
		Timer();
		
		void start();
		void stop();
		void pause();

		bool isStarted();
		bool isPaused();

		unsigned int getTime();

	private:
		unsigned int startTime_;
		unsigned int pausedTime_;

		bool isStarted_;
		bool isPaused_;
	};
}

#endif
