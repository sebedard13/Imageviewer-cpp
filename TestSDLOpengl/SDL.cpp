#include "SDL.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

SDL_adapter::SDL::SDL()
{
	
	if (SDL_Init(SDL_INIT::INIT_VIDEO)< 0) {
		std::cout << "Error: unable to init SDL : " << SDL_GetError() << std::endl;
		throw SDL_Exception{};
	};


	if (IMG_Init(IMG_INIT::IMG_INIT_PNG) == 0) {
		std::cout << "Error: unable to init SDL_IMG : " << IMG_GetError() << std::endl;
		throw SDL_Exception{};
	};

	//Set texture filtering to linear
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
	{
		std::cout << "Warning iLinear texture filtering not enabled!" << std::endl;
	}

	
}

SDL_adapter::SDL::~SDL()
{

	IMG_Quit();
	SDL_Quit();
}
