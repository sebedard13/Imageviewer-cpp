//Using SDL and standard IO
#include <SDL2\SDL.h>

#undef main
#include <stdio.h>
#include <math.h>
#include <SDL2/SDL_image.h>


#include "Texture.h"
#include "SDL.h"
#include "Window.h"
#include "Renderer.h"
#include <vector>
#include <iostream>
#include <filesystem>
#include "Slide.h"
namespace fs = std::filesystem;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{


	namespace sdlA = SDL_adaptater;
	sdlA::SDL sdl{};

	sdlA::Window window{ "Titre", SCREEN_WIDTH, SCREEN_HEIGHT };

	sdlA::Renderer renderer{ window };


	

	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	std::vector<Slide> slides{};
	
	for (const auto& entry : fs::recursive_directory_iterator("data")) {
		sdlA::Texture texture{};
		texture.loadFromFile(renderer, entry.path().generic_string());
		slides.push_back({ std::move(texture) , SCREEN_WIDTH, SCREEN_HEIGHT });
	}



	int slideIndex {0};
	//While application is running
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_k:
					break;
				case SDLK_j:

					break;

				}
			}
		}


		//Clear screen
		SDL_SetRenderDrawColor(renderer.ptr, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer.ptr);

		
		Slide& slide = slides.front();
		SDL_RenderCopy(renderer.ptr, 
			slide.getTexture().ptr, NULL, 
			slide.getBounds());
		//Update screen
		SDL_RenderPresent(renderer.ptr);
	}
	return 0;
}

