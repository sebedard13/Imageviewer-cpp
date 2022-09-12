#include "Renderer.h"


#include<iostream>
SDL_adapter::Renderer::Renderer(const Window& window)
{
	ptr = SDL_CreateRenderer(window.ptr, -1, SDL_RENDERER_ACCELERATED);
	if (!ptr) {
		std::cout << "Error: Unable to create renderer instance : " << SDL_GetError() << std::endl;
	}
}

SDL_adapter::Renderer::~Renderer()
{
	SDL_DestroyRenderer(ptr);
}

void SDL_adapter::Renderer::setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(ptr, r, g, b, a);
}

void SDL_adapter::Renderer::clear()
{
	SDL_RenderClear(ptr);
}

void SDL_adapter::Renderer::render()
{
	SDL_RenderPresent(ptr);
}
