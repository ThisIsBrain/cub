#ifndef GRAPHICS_SCENE_H
#define GRAPHICS_SCENE_H

#include <iostream>
#include <vector>
#include <map>

#include <SDL2/SDL.h>

#include "graphics_item.h"
#include "texture.h"
#include "types.h"

namespace cub
{
	class GraphicsScene
	{
	public:
		GraphicsScene();
		GraphicsScene(	SDL_Rect*	windowRect,
						std::string	title);

		~GraphicsScene();

		cub::Texture*	loadTexture(std::string		pathToBitmap,
									cub::Scalar*	colorKey);

		cub::Texture*	loadTexture(std::string		pathToImage);

		void	addItem(cub::GraphicsItem* item);
		void	setPosFocus(cub::Point point);
		//void	swapItem();

		SDL_Rect* getPosFocus();

		int		drawing();

		bool	isOk();
	
	private:
		bool isOk_;

		SDL_Window*		window_;
		SDL_Renderer*	renderer_;

		cub::Rect		windowOfFocus_;
		
		std::vector<cub::Texture*>		textures_;
		std::vector<cub::GraphicsItem*>	items_;	

	};

}

#endif
