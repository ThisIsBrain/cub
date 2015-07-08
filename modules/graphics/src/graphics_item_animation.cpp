#include "graphics_item_animation.h"



cub::GraphicsItemAnimation::GraphicsItemAnimation(
							Texture*		texture,
							cub::Geometry*	geometry,
							cub::Timer*		timer,
							unsigned int	fps) : 
GraphicsItem(	texture,
				geometry)
{
	 timer_	= timer;
	 
	 timeFrame_	= 1000 / fps;
	 theLastTimeFrame_	= 0;

	 namesRectsOfTexture_	= NULL;

}



int cub::GraphicsItemAnimation::run(cub::Rect* windowOfFocus)
{

	if(!isOk_){
		return -1;
	}

	if(!isVisible_){
		return 0;
	}

	windowOfFocus_ = windowOfFocus;

	if(draw_()<0)
		return -1;

	if(animation_()<0)
		return -1;

	if((timer_->getTime() - theLastTimeFrame_) >= timeFrame_){
		//next frame	
		if((currentRectOfTexture_+1) == namesRectsOfTexture_->end()){
			currentRectOfTexture_ = namesRectsOfTexture_->begin();
		}else{
			++currentRectOfTexture_;
		}

		theLastTimeFrame_	= timer_->getTime();
	}

		return 0;
}



int cub::GraphicsItemAnimation::setAnimation(std::vector<std::string>* names)
{
	namesRectsOfTexture_	= names;
	currentRectOfTexture_	= names->begin();
	
	theLastTimeFrame_	= 0;

	return 0;
}



int cub::GraphicsItemAnimation::animation_()
{
	if(namesRectsOfTexture_->empty())
		return -1;

	textureRendering_(	*currentRectOfTexture_,
						fillingWidth_,
						fillingHeight_);
	return 0;
}



int cub::GraphicsItemAnimation::draw_()
{
	return 0;
}



cub::GraphicsItemAnimation::~GraphicsItemAnimation()
{
}



/*End of file*/
