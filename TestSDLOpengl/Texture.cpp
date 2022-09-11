#include "Texture.h"
#include <SDL2\SDL_image.h>

SDL_adapter::Texture::Texture()
{
	//Initialize
	ptr = nullptr;
	mWidth = 0;
	mHeight = 0;
}

SDL_adapter::Texture::~Texture()
{
	//Deallocate
	free();
}

bool SDL_adapter::Texture::loadFromFile(Renderer& renderer, std::string path)
{
	//Get rid of preexisting texture
	free();
	//The final texture
	SDL_Texture* newTexture = nullptr;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(renderer.ptr, loadedSurface);
		if (newTexture == nullptr)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	ptr = newTexture;
	return ptr != nullptr;
}

void SDL_adapter::Texture::free()
{
	//Free texture if it exists
	if (ptr != nullptr)
	{
		SDL_DestroyTexture(ptr);
		ptr = nullptr;
		mWidth = 0;
		mHeight = 0;
	}
}

int SDL_adapter::Texture::getWidth()
{
	return mWidth;
}

int SDL_adapter::Texture::getHeight()
{
	return mHeight;
}

double SDL_adapter::Texture::getHWRatio()
{
	if (mWidth != 0) {
		return ((double)mHeight) / ((double)mWidth);
	}
	else
	{
		return 0;
	}
}
