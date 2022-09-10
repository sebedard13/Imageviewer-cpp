#include "Slide.h"

Slide::Slide(SDL_adaptater::Texture vtexture, const int& width, const int& vheight)
{
	texture = vtexture;

	int height = round(width * texture.getHWRatio());
	//Set rendering space and render to screen
	bounds = new SDL_Rect{ 0, (vheight - height) / 2, width,  height };
}

SDL_adaptater::Texture Slide::getTexture() const
{
	return texture;
}

SDL_Rect* Slide::getBounds()
{
	return bounds;
}

Slide::~Slide()
{
	delete bounds;
}
