#include "Renderer.h"


#include<iostream>
SDL_adaptater::Renderer::Renderer(const Window& window)
{
	ptr = SDL_CreateRenderer(window.ptr, -1, SDL_RENDERER_ACCELERATED);
	if (!ptr) {
		std::cout << "Error: Unable to create renderer instance : " << SDL_GetError() << std::endl;
		throw Renderer_Exception();
	}
}

SDL_adaptater::Renderer::~Renderer()
{
}
