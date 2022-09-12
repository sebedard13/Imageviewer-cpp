#include "Slide.h"

Slide::Slide(SDL_adapter::Texture&& vtexture, const int& width, const int& vheight)
{
	texture = std::move(vtexture);

	int height = round(width * texture.getHWRatio());
	//Set rendering space and render to screen
	bounds = SDL_Rect{ 0, (vheight - height) / 2, width,  height };
}

Slide::Slide(Slide&& other) noexcept
	: texture(std::move(other.texture)),
	bounds(other.bounds)
{

}

Slide& Slide::operator=(Slide&& other) noexcept
{
	if (this == &other)
		return *this;
	texture = std::move(other.texture);

	bounds = other.bounds;
	return *this;
}

SDL_adapter::Texture& Slide::getTexture()
{
	return texture;
}

SDL_Rect* Slide::getBounds()
{
	return &bounds;
}
