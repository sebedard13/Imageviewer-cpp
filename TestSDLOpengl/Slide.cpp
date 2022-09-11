#include "Slide.h"

Slide::Slide(SDL_adapter::Texture&& vtexture, const int& width, const int& vheight)
{
	texture = std::move(vtexture);

	int height = round(width * texture.getHWRatio());
	//Set rendering space and render to screen
	bounds = SDL_Rect{ 0, (vheight - height) / 2, width,  height };
}

SDL_adapter::Texture& Slide::getTexture()
{
	return texture;
}

SDL_Rect* Slide::getBounds()
{
	return &bounds;
}

Slide::~Slide()
{

}
