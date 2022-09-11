#pragma once
#include <SDL2/SDL_render.h>
#include "Window.h"

namespace SDL_adapter {
	struct Renderer_Exception {

	};

	class Renderer
	{
	public:
		Renderer(const Window&);

		Renderer(const Renderer& other) = delete;
		Renderer(Renderer&& other) noexcept = delete;
		Renderer& operator=(const Renderer& other) = delete;
		Renderer& operator=(Renderer&& other) noexcept = delete;

		~Renderer();

		SDL_Renderer* ptr;
	};

}

