#include "graphics_scene.h"



cub::GraphicsScene::GraphicsScene()
{
	SDL_InitSubSystem(SDL_INIT_VIDEO);

	window_		=	NULL;
	renderer_	=	NULL;
	isOk_		=	false;

	windowOfFocus_.x	= 0;
	windowOfFocus_.y	= 0;
	windowOfFocus_.w	= 640;
	windowOfFocus_.h	= 480;
}



cub::GraphicsScene::GraphicsScene(	SDL_Rect*	windowRect,
									std::string	title)
{
	isOk_	=	true;
	int ok	= 	0;	
	
	//init
	if(SDL_InitSubSystem(SDL_INIT_VIDEO)<0){
		std::cout << SDL_GetError() << std::endl;
		isOk_ = false;
		return;
	}

	
	
	//create window
	window_ = NULL;

	if(windowRect != NULL){
		window_	= SDL_CreateWindow(	title.c_str(),
									windowRect->x,
									windowRect->y,
									windowRect->w,
									windowRect->h,
									0);
		//write size windowOfFocus
		windowOfFocus_.x = 0;
		windowOfFocus_.y = 0;
		windowOfFocus_.w = windowRect->w;
		windowOfFocus_.h = windowRect->h;

	}else{
		//get video info
		int display_index		= 0;
		int mode_index			= 0;
		SDL_DisplayMode	 displayMode;
		ok = SDL_GetDisplayMode(display_index, mode_index, &displayMode);
		if(ok<0){
			std::cout << SDL_GetError() << std::endl;
			return;
		}
		
		window_	= SDL_CreateWindow(	title.c_str(),
									SDL_WINDOWPOS_UNDEFINED,
									SDL_WINDOWPOS_UNDEFINED,
									displayMode.w,
									displayMode.h,
									SDL_WINDOW_FULLSCREEN);

		//write size windowOfFocus
		windowOfFocus_.x = 0;
		windowOfFocus_.y = 0;
		windowOfFocus_.w = displayMode.w;
		windowOfFocus_.h = displayMode.h;

	}
									
	if(window_ == NULL){
		std::cout << SDL_GetError() << std::endl;
		isOk_	=	false;
		return;
	}


	//create renderer
	renderer_ = SDL_CreateRenderer(	window_,
									-1,
									SDL_RENDERER_ACCELERATED);
	if(renderer_ == NULL){
		std::cout << SDL_GetError() << std::endl;
		isOk_	=	false;
		return;
	}

	//std::cout << "init ok\n";
}



cub::GraphicsScene::~GraphicsScene()
{
//	std::cout << "exit graphics scene\n";

	//destroy renderer
	SDL_DestroyRenderer(renderer_);
	renderer_	=	NULL;


	//destroy window
	SDL_DestroyWindow(window_);
	window_	=	NULL;

	
	//destroy all textures
	while(!textures_.empty()){
		delete *textures_.begin();
		textures_.erase(textures_.begin());
	}
	
	//destroy all item
	items_.clear();

	SDL_QuitSubSystem(SDL_INIT_VIDEO);
}



bool cub::GraphicsScene::isOk()
{
	return isOk_;
}



void cub::GraphicsScene::setPosFocus(cub::Point point)
{
	windowOfFocus_.x = point.x;
	windowOfFocus_.y = point.y;
}



SDL_Rect* cub::GraphicsScene::getPosFocus()
{
	return &windowOfFocus_;
}



cub::Texture* cub::GraphicsScene::loadTexture(	std::string		pathToBitmap,
												cub::Scalar*	colorKey)
{
	cub::Texture* tmpPtr = new cub::Texture(renderer_,
											pathToBitmap,
											colorKey);

	textures_.push_back(tmpPtr);
	
	return tmpPtr;
}



cub::Texture* cub::GraphicsScene::loadTexture(std::string	pathToImage)
{
	cub::Texture* tmpPtr = new cub::Texture(renderer_,
											pathToImage);

	textures_.push_back(tmpPtr);
	
	return tmpPtr;
}



int cub::GraphicsScene::drawing()
{
	int ok = 0;

	if(!isOk_){
		return -1;
	}
	
	ok = SDL_RenderClear(renderer_);
	if(ok<0){
		std::cout << SDL_GetError() << std::endl;
		return -1;
	}

	//отрисовка объектов
	for(unsigned int i=0; i<items_.size(); i++){
		ok = items_.at(i)->run(&windowOfFocus_);
		if(ok<0){
			return -1;
		}
	}

	//обновление экрана
	SDL_RenderPresent(renderer_);

	return 0;
}



void cub::GraphicsScene::addItem(cub::GraphicsItem* item)
{
	items_.push_back(item);
}



/*End of file*/
