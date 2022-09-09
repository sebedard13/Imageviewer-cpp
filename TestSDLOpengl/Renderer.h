#pragma once
#include <SDL2/SDL_render.h>
#include "Window.h"

namespace SDL_adaptater {
	struct Renderer_Exception {

	};

	class Renderer
	{
	public:
		Renderer(const Window&);

		~Renderer();

		SDL_Renderer* ptr;
	};

}

