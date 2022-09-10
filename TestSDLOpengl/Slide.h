#pragma once
#include "Texture.h"
class Slide
{

public:
	Slide(SDL_adaptater::Texture texture, const int& width, const int& height);

	SDL_adaptater::Texture getTexture() const;

	SDL_Rect* getBounds();

	~Slide();

private:
	SDL_adaptater::Texture texture;
	SDL_Rect* bounds;
};

