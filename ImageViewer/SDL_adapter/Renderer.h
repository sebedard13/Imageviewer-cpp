#pragma once
#include <SDL2/SDL_render.h>
#include "Window.h"

namespace SDL_adapter {
	class Renderer
	{
	public:
		explicit Renderer(const Window&);
		Renderer(const Renderer& other) = delete;
		Renderer(Renderer&& other) noexcept = delete;
		Renderer& operator=(const Renderer& other) = delete;
		Renderer& operator=(Renderer&& other) noexcept = delete;
		~Renderer();

		void setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
		void clear();
		void render();

		SDL_Renderer* ptr;
	};

}

