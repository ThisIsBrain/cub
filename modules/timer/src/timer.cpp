#include "timer.h"



cub::Timer::Timer()
{
	isStarted_	= false;
	isPaused_	= false;
	
	startTime_	= 0;
	pausedTime_	= 0;
}



void cub::Timer::start()
{	
	//unpause
	if(isPaused_){
		isPaused_	= false;
		startTime_	= SDL_GetTicks() - pausedTime_;
		pausedTime_	= 0;
	}
	

	if(isStarted_)
		return;

	isStarted_	= true;
	isPaused_	= false;
	startTime_	= SDL_GetTicks();
}



void cub::Timer::stop()
{
	isStarted_	= false;
	isPaused_	= false;
}



void cub::Timer::pause()
{
	if(isPaused_ && (!isStarted_))
		return;
	
	isPaused_ = true;
	
	pausedTime_	= startTime_ - SDL_GetTicks();
}



bool cub::Timer::isStarted()
{
	return isStarted_;
}



bool cub::Timer::isPaused()
{
	return isPaused_;
}



unsigned int cub::Timer::getTime()
{
	if(isStarted_){
		if(isPaused_){
			return pausedTime_;
		}else{
			return SDL_GetTicks() - startTime_;
		}
	}

	return 0;
}



/*End of file*/
