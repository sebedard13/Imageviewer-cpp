#include "Window.h"

#include<iostream>

SDL_adapter::Window::Window(const std::string& title, const int& width, const int& height)
{
    ptr = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
        SDL_WINDOW_SHOWN | 
        SDL_WINDOW_RESIZABLE | 
        SDL_WINDOW_INPUT_FOCUS |
        SDL_WINDOW_MOUSE_FOCUS
    );
    if (!ptr) {
        std::cout << "Error: Unable to create window instance : " << SDL_GetError() << std::endl;
        throw Window_Exception{};
    }
}

SDL_adapter::Window::~Window()
{
    SDL_DestroyWindow(ptr);
    ptr = nullptr;
}
