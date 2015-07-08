#include "graphics_item.h"



cub::GraphicsItem::GraphicsItem()
{
	isVisible_	= false;
	isOk_		= false;
	texture_	=	NULL;
}



cub::GraphicsItem::GraphicsItem(	cub::Texture*	texture,
									cub::Geometry*	geometry)
{
	isVisible_	= false;

	texture_	= texture;

	geometry_.center	= geometry->center;
	geometry_.position	= geometry->position;
	geometry_.angle		= geometry->angle;
	geometry_.scale		= geometry->scale;
	geometry_.flip		= geometry->flip;

	fillingWidth_	= 1;
	fillingHeight_	= 1;

}	



cub::GraphicsItem::~GraphicsItem()
{
}



void cub::GraphicsItem::setGeometry(cub::Geometry* geometry)
{
	geometry_.center	= geometry->center;
	geometry_.position	= geometry->position;
	geometry_.angle		= geometry->angle;
	geometry_.scale		= geometry->scale;
	geometry_.flip		= geometry->flip;
}



void cub::GraphicsItem::setFilling(int w, int h)
{
	fillingWidth_	= w;
	fillingHeight_	= h;
}



void cub::GraphicsItem::setFillingWidth(int w)
{
	fillingWidth_	= w;
}



void cub::GraphicsItem::setFillingHeight(int h)
{
	fillingHeight_	= h;
}



void cub::GraphicsItem::setSprite(std::string name)
{
	currentRectOfTexture_	= name;
}



int cub::GraphicsItem::run(cub::Rect* windowOfFocus)
{
	int ok = 0;

	if(!isOk_){
		return -1;
	}

	if(!isVisible_){
		return 0;
	}

	windowOfFocus_ = windowOfFocus;

	ok = draw_();

	return ok;
}



//TODO
int cub::GraphicsItem::draw_()
{
	textureRendering_(currentRectOfTexture_, fillingWidth_, fillingHeight_);
	return 0;
}



int cub::GraphicsItem::textureRendering_(std::string nameRect)
{
	int ok=0;

	SDL_Rect*			srcRect = NULL;
	SDL_Rect			dstRect;
	double				angle	= 0.0f;
	
	//rect
	srcRect = texture_->getRect(nameRect);
	dstRect.x	= geometry_.position.x - windowOfFocus_->x;	//положение в окне
	dstRect.y	= geometry_.position.y - windowOfFocus_->y; //
	dstRect.w	= srcRect->w * geometry_.scale;
	dstRect.h	= srcRect->h * geometry_.scale;
	
	//angle
	angle = geometry_.angle * 180 / M_PI;

	ok = SDL_RenderCopyEx(	texture_->getSdlRenderer(),
							texture_->getSdlTexture(),
							srcRect,
							&dstRect,
							angle,
							&geometry_.center,
							geometry_.flip);
	if(ok<0){
		std::cout << SDL_GetError() << std::endl;
		isOk_	= false;
		return -1;
	}

	return 0;
}




int cub::GraphicsItem::textureRendering_(	std::string nameRect,
											int countOnWidth,
											int countOnHeight)
{
	int	ok = 0;

	SDL_Rect*			srcRect = NULL;
	SDL_Rect			dstRect;
	
	int 				deltaX = 0;	//шаг заполнения
	int					deltaY= 0;	//

	double				angle	= 0.0f;
	
	//angle
	angle = geometry_.angle * 180 / M_PI;
	
	//исходный фрагмент текстуры
	srcRect = texture_->getRect(nameRect);

	//размеры полученого фрагмента
	dstRect.w	= srcRect->w * geometry_.scale;
	dstRect.h	= srcRect->h * geometry_.scale;

	//шаг заполнения	
	deltaX	= srcRect->w * geometry_.scale;
	deltaY	= srcRect->h * geometry_.scale;
	
	//geometry_.flip = SDL_FLIP_NONE;

	dstRect.x	= geometry_.position.x - windowOfFocus_->x;	
	for(int x=0; x<countOnWidth; x++)
	{
		dstRect.y	= geometry_.position.y - windowOfFocus_->y; 
		for(int y=0; y<countOnHeight; y++)
		{
			ok = SDL_RenderCopyEx(	texture_->getSdlRenderer(),
									texture_->getSdlTexture(),
									srcRect,
									&dstRect,
									angle,
									&geometry_.center,
									geometry_.flip);
			if(ok<0){
				std::cout << SDL_GetError() << std::endl;
				isOk_	= false;
				return -1;
			}
			dstRect.y += deltaY;	
		}
		dstRect.x	+= deltaX;
	}

	return 0;
}



cub::Geometry* cub::GraphicsItem::getGeometry()
{
	return &geometry_;
}



int cub::GraphicsItem::getFillingWidth()
{
	return fillingWidth_;
}



int cub::GraphicsItem::getFillingHeight()
{
	return fillingHeight_;
}



bool cub::GraphicsItem::isOk()
{
	return isOk_;
}



void cub::GraphicsItem::show()
{
	isVisible_	= true;
}



void cub::GraphicsItem::hide()
{
	isVisible_	 = false;
}



bool cub::GraphicsItem::isVisible()
{
	return isVisible_;
}



/*End of file*/
