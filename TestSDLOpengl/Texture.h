#pragma once
#include <string>
#include <SDL2/SDL_render.h>
#include "Renderer.h"


namespace SDL_adaptater {
	class Texture
	{
	public:
		//Initializes variables
		Texture();

		Texture(Texture&&);

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

