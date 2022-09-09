#pragma once
#include <string>
#include <SDL2/SDL_video.h>

namespace SDL_adaptater {
	struct Window_Exception {

	};
	
	class Window
	{
	public:
		Window(const std::string& title, const int& width, const int& height);

		~Window();
		SDL_Window* ptr;
	};
}


