#pragma once
#include "Texture.h"
class Slide
{

public:
	Slide(SDL_adapter::Texture&& texture, const int& width, const int& height);

	Slide(const Slide& other) = delete;

	Slide(Slide&& other) noexcept
		: texture(std::move(other.texture)),
		bounds(other.bounds)
	{

	}

	Slide& operator=(const Slide& other) = delete;

	Slide& operator=(Slide&& other) noexcept
	{
		if (this == &other)
			return *this;
		texture = std::move(other.texture);

		bounds = other.bounds;
		return *this;
	}

	SDL_adapter::Texture& getTexture();

	SDL_Rect* getBounds();

	~Slide();

private:
	SDL_adapter::Texture texture;
	SDL_Rect bounds;
};

