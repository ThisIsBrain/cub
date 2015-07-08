#include <iostream>
#include <SDL2/SDL.h>

#include "timer.h"
#include "graphics_scene.h"
#include "graphics_item_animation.h"

cub::Rect rect(int x, int y, int w, int h);

int main(int argc, char* argv[])
{
	SDL_Init(0);
	
	cub::Timer timer;
	timer.start();

	//scene
	cub::Rect window;
	window.x = 0;
	window.y = 0;
	window.w = 286;
	window.h = 511;

	cub::GraphicsScene	scene(&window, "hello world");
	
	//textures
	cub::Texture* texture = scene.loadTexture(argv[1]);
	texture->addRect("background", rect(0, 0, 286, 511));
	texture->addRect("bird1", rect(228, 761, 37, 25));
	texture->addRect("bird2", rect(228, 812, 37, 25));
	texture->addRect("bird3", rect(228, 865, 37, 25));
	
	//items
	cub::Geometry geometry;
	geometry.center.x = 0;
	geometry.center.y = 0;
	geometry.position.x=0;
	geometry.position.y=0;
	geometry.angle = 0.0f;
	geometry.scale = 1;
	geometry.flip = SDL_FLIP_NONE;

	//background
	cub::GraphicsItem background(texture, &geometry);
	background.show();
	background.setSprite("background");
	scene.addItem(&background);

	//bird
	std::vector<std::string> names;
	names.push_back("bird1");
	names.push_back("bird2");
	names.push_back("bird3");
	names.push_back("bird2");

	cub::GraphicsItemAnimation bird(texture, &geometry, &timer, 6);
	bird.show();
	scene.addItem(&bird);
	bird.setAnimation(&names);
	
	while(1){
	scene.drawing();
	}


	return 0;
}


cub::Rect rect(int x, int y, int w, int h)
{
	cub::Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	return rect;
}

