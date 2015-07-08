#ifndef GRAPHICS_ITEM_ANIMATION_H
#define GRAPHICS_ITEM_ANIMATION_H

#include <iostream>
#include <vector>
#include <string>

#include <SDL2/SDL.h>

#include "graphics_item.h"
#include "timer.h"

namespace cub
{
	class GraphicsItemAnimation: public cub::GraphicsItem
	{
	public:
		GraphicsItemAnimation();
		GraphicsItemAnimation(	cub::Texture*	texture,
								cub::Geometry*	geometry,
								cub::Timer*		timer,
								unsigned int	fps);
		~GraphicsItemAnimation();

		//void setFps(unsigned int fps);
		//void setAnimationType(int type);
		
		int run(cub::Rect* windowOfFocus);
		int setAnimation(std::vector<std::string>* mames);

	protected:
		cub::Timer*		timer_;

		unsigned int	timeFrame_;
		unsigned int	theLastTimeFrame_;
		//int 			animationType_;
		

		std::vector<std::string>* 			namesRectsOfTexture_;
		std::vector<std::string>::iterator 	currentRectOfTexture_;
		
		int animation_();
		int draw_();

	};
}

#endif
