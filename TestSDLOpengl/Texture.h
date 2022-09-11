#pragma once
#include <string>
#include <SDL2/SDL_render.h>
#include "Renderer.h"


namespace SDL_adapter {
	class Texture
	{
	public:
		//Initializes variables
		Texture();

		Texture(const Texture& other) = delete;

		Texture(Texture&& other) noexcept
			: ptr(other.ptr),
			mWidth(other.mWidth),
			mHeight(other.mHeight)
		{
			other.ptr = nullptr;
		}

		Texture& operator=(const Texture& other) = delete;

		Texture& operator=(Texture&& other) noexcept
		{
			if (this == &other)
				return *this;
			ptr = other.ptr;
			mWidth = other.mWidth;
			mHeight = other.mHeight;
			other.ptr = nullptr;
			return *this;
		}

		//Deallocates memory
		~Texture();

		//Loads image at specified path
		bool loadFromFile(Renderer&, std::string path);


		//Deallocates texture
		void free();

		//Gets image dimensions
		int getWidth();
		int getHeight();
		double getHWRatio();

		//The actual hardware texture
		SDL_Texture* ptr;
	private:
		//Image dimensions
		int mWidth;
		int mHeight;
	};
}

