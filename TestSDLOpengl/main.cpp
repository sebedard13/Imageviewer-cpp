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

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main(int argc, char* args[])
{
	namespace sdlA = SDL_adaptater;
	sdlA::SDL sdl{};

	sdlA::Window window{ "Titre", SCREEN_WIDTH, SCREEN_HEIGHT };

	sdlA::Renderer renderer{ window };


	sdlA::Texture g_texture{};

	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

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
					g_texture.loadFromFile(renderer, "data/Image.png");
					break;
				case SDLK_j:
					g_texture.free();

					break;

				}
			}
		}


		//Clear screen
		SDL_SetRenderDrawColor(renderer.ptr, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer.ptr);

		int width = g_texture.getWidth();
		if (width != 0)
		{
			int height = round(SCREEN_WIDTH * g_texture.getHWRatio());
			//Set rendering space and render to screen
			SDL_Rect renderQuad { 0, (SCREEN_HEIGHT-height)/2, SCREEN_WIDTH,  height};
			SDL_RenderCopy(renderer.ptr, g_texture.ptr, NULL, &renderQuad);
		}
		//Update screen
		SDL_RenderPresent(renderer.ptr);
	}
	return 0;
}