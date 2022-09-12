#include <SDL2/SDL.h>
//Because SDL2 define a main and cause problem for visual studio
#undef main

#include "SDL_adapter/Texture.h"
#include "SDL_adapter/SDL.h"
#include "SDL_adapter/Window.h"
#include "SDL_adapter/Renderer.h"
#include <vector>
#include <filesystem>

#include "Index.h"
#include "Slide.h"

constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	namespace fs = std::filesystem;
	namespace sdl = SDL_adapter;
	sdl::SDL sdlInit{};

	const sdl::Window window{ "Image Viewer", SCREEN_WIDTH, SCREEN_HEIGHT };

	sdl::Renderer renderer{ window };
	renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);


	//Load slide from folder data
	std::vector<Slide> slides{};
	for (const auto& entry : fs::recursive_directory_iterator("data")) {
		sdl::Texture texture{};
		texture.loadFromFile(renderer, entry.path().generic_string());

		Slide slide{ std::move(texture), SCREEN_WIDTH, SCREEN_HEIGHT };

		slides.emplace_back(std::move(slide));
	}


	Index slideIndex{ 0, (static_cast<int>(slides.size()) - 1) };
	//Event handler
	SDL_Event e;
	//Main loop flag
	bool quit = false;
	//Draw flag or change diapo flag
	bool draw = true;
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_RIGHT:
				case SDLK_d:
					slideIndex.next();
					draw = true;
					break;
				case SDLK_LEFT:
				case SDLK_a:
					slideIndex.previous();
					draw = true;
					break;
				}
			}
		}

		if (draw)
		{
			//Clear screen
			renderer.clear();

			Slide& slide = slides.at(slideIndex());
			SDL_RenderCopy(renderer.ptr,
				slide.getTexture().ptr,
				NULL,
				slide.getBounds());

			renderer.render();
			draw = false;
		}
		//To slow down the loop and give the cpu some compute
		SDL_Delay(1);
	}
	return 0;
}

