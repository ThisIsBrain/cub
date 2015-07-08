#include "texture.h"



cub::Texture::Texture()
{
	texture_	= NULL;
	renderer_	= NULL;
}



cub::Texture::Texture(	SDL_Renderer*		renderer,
						std::string			pathToBitmap,
						cub::Scalar*		colorKey)
{
	isOk_		=	true;
	renderer_	=	renderer;
	unsigned int  colorKeyInt;

	int ok=0;
	
	//load surface
	SDL_Surface* loadSurface = SDL_LoadBMP(pathToBitmap.c_str());
	if(loadSurface == NULL){
		std::cout << SDL_GetError() << std::endl;
		isOk_ = false;
		return;
	}
	
	//set colorKey
	if(colorKey != NULL){
		colorKeyInt = SDL_MapRGB(	loadSurface->format,
									colorKey->r,
									colorKey->g,
									colorKey->b);
		ok = SDL_SetColorKey(loadSurface, SDL_TRUE, colorKeyInt);
		if(ok < 0){
			std::cout << SDL_GetError() << std::endl;
			isOk_ = false;
			return;
		}
	}

	//create texture from surface
	texture_ = SDL_CreateTextureFromSurface(renderer, loadSurface);
	if(texture_ == NULL){
		std::cout << SDL_GetError() << std::endl;
		isOk_ = false;
		return;
	}

	//free surface
	SDL_FreeSurface(loadSurface);
}




cub::Texture::Texture(	SDL_Renderer*		renderer,
						std::string			pathToImage)
{
	isOk_		=	true;
	renderer_	=	renderer;

	int ok=0;
	
	//load surface
	SDL_Surface* loadSurface = IMG_Load(pathToImage.c_str());
	if(loadSurface == NULL){
		std::cout << SDL_GetError() << std::endl;
		isOk_ = false;
		return;
	}
	
	//create texture from surface
	texture_ = SDL_CreateTextureFromSurface(renderer, loadSurface);
	if(texture_ == NULL){
		std::cout << SDL_GetError() << std::endl;
		isOk_ = false;
		return;
	}

	//free surface
	SDL_FreeSurface(loadSurface);
}




cub::Texture::~Texture()
{
	SDL_DestroyTexture(texture_);
	rects_.clear();
	texture_ = NULL;
}



int cub::Texture::addRect(std::string name, SDL_Rect rect)
{
	rects_[name] = rect;
	return 0;
}



SDL_Rect* cub::Texture::getRect(std::string name)
{
	return &rects_[name];
}



bool cub::Texture::isOk()
{
	return isOk_;
}



SDL_Texture* cub::Texture::getSdlTexture()
{
	return texture_;
}



SDL_Renderer* cub::Texture::getSdlRenderer()
{
	return renderer_;
}



/*End of file*/
