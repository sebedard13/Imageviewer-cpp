#pragma once
#include "Texture.h"
class Slide
{

public:
	Slide(SDL_adapter::Texture&& texture, const int& width, const int& height);
	Slide(const Slide& other) = delete;
	Slide(Slide&& other) noexcept;
	Slide& operator=(const Slide& other) = delete;
	Slide& operator=(Slide&& other) noexcept;
	~Slide() = default;

	SDL_adapter::Texture& getTexture();
	SDL_Rect* getBounds();
private:
	SDL_adapter::Texture texture;
	SDL_Rect bounds;
};

