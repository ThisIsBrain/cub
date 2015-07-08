#ifndef GRAPHICS_ITEM_H
#define GRAPHICS_ITEM_H

#include <iostream>
#include <string>
#include <math.h>

#include <SDL2/SDL.h>

#include "texture.h"
#include "types.h"

namespace cub
{
	class GraphicsItem
	{
	public:
		GraphicsItem();
		GraphicsItem(	cub::Texture*	texture,
						cub::Geometry*	geometry);
		~GraphicsItem();
		
		void setGeometry(cub::Geometry* geometry);
		//void setCenter(SDL_Point point);
		//void setPos(SDL_Point point);
		//void setAngle(double angle);
		//void setFlip(int h, int w);
		//void setScale(double scale);
	
		void setFilling(int w, int h);
		void setFillingWidth(int w);
		void setFillingHeight(int h);

		void setSprite(std::string name);
		
		void show();
		void hide();
		
		cub::Geometry* getGeometry();
		//SDL_Point	getCenter();
		//SDL_Point	getPos();
		//double		getAngle();
		//double		getScale();

		int getFillingWidth();
		int getFillingHeight();
		
		bool isVisible();
		bool isOk();
		
		virtual int run(cub::Rect* windowOfFocus);

	protected:
		bool 	isOk_;
		bool 	isVisible_;

		int fillingWidth_;
		int fillingHeight_;

		cub::Texture*	texture_;
		cub::Geometry	geometry_;
		cub::Rect*		windowOfFocus_;

		std::string currentRectOfTexture_;
		
		virtual int draw_();

		int textureRendering_(std::string nameRect);
		int textureRendering_(	std::string namerect,
								int countOnWidth,
								int countOnHeight);
		
	};
}

#endif
