#pragma once
#include <string>
#include <SDL2/SDL_video.h>

namespace SDL_adapter {
	class Window
	{
	public:
		Window(const std::string& title, const int& width, const int& height);

		Window(const Window& other) = delete;
		Window(Window&& other) noexcept = delete;
		Window& operator=(const Window& other) = delete;
		Window& operator=(Window&& other) noexcept = delete;

		~Window();
		SDL_Window* ptr;
	};
}


