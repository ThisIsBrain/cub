#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <map>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "types.h"

namespace cub
{
	class Texture
	{
	public:
		Texture();

		Texture(SDL_Renderer*	renderer,
				std::string		pathToBitmap,
				cub::Scalar*	colorKey);

		Texture(SDL_Renderer*	renderer,
				std::string		pathToImage);

		~Texture();
		
		bool			isOk();
		int				addRect(std::string name, SDL_Rect rect);

		SDL_Rect*		getRect(std::string name);
		SDL_Texture*	getSdlTexture();
		SDL_Renderer*	getSdlRenderer();
	
	private:

		bool 							isOk_;
		SDL_Renderer*					renderer_;
		SDL_Texture*					texture_;
		std::map<std::string, SDL_Rect> rects_;

	};
}

#endif
