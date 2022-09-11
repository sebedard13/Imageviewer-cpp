//Using SDL and standard IO
#include <SDL2\SDL.h>

#undef main

#include "Texture.h"
#include "SDL.h"
#include "Window.h"
#include "Renderer.h"
#include <vector>
#include <filesystem>

#include "Index.h"
#include "Slide.h"
namespace fs = std::filesystem;

//Screen dimension constants
constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{


	namespace sdlA = SDL_adapter;
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

		Slide slide{ std::move(texture), SCREEN_WIDTH, SCREEN_HEIGHT };

		slides.emplace_back(std::move(slide));
	}

	Index slideIndex{ 0, (static_cast<int>(slides.size()) - 1) };

	Uint64 nextFrame = SDL_GetPerformanceCounter();

	//While application is running
	bool draw = true;
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
					slideIndex.next();
					draw = true;
					break;
				case SDLK_j:
					slideIndex.previous();
					draw = true;
					break;
				}
			}
		}

		if (draw)
		{
			//Clear screen
			SDL_SetRenderDrawColor(renderer.ptr, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(renderer.ptr);

			Slide& slide = slides.at(slideIndex());
			SDL_RenderCopy(renderer.ptr,
				slide.getTexture().ptr, NULL,
				slide.getBounds());
			//Update screen
			SDL_RenderPresent(renderer.ptr);
			draw = false;
		}
		SDL_Delay(1);
	}
	return 0;
}

