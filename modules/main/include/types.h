#ifndef TYPES_H
#define TYPES_H

#include <SDL2/SDL.h>

namespace cub
{
	typedef SDL_Point	Point;
	typedef SDL_Rect	Rect;
	
	typedef struct Scalar
	{
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char a;
	}
	Scalar;

	typedef struct Geometry
	{
		cub::Point			center;
		cub::Point			position;
		double				angle;
		double				scale;
		SDL_RendererFlip	flip;
	}
	Geometry;
}

#endif
