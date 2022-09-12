#pragma once
#include <string>
#include <SDL2/SDL_render.h>
#include "Renderer.h"


namespace SDL_adapter {
	class Texture
	{
	public:
		Texture();
		Texture(const Texture& other) = delete;
		Texture(Texture&& other) noexcept;
		Texture& operator=(const Texture& other) = delete;
		Texture& operator=(Texture&& other) noexcept;
		~Texture();

		bool loadFromFile(Renderer&, std::string path);
		void free();

		int getWidth()  const;
		int getHeight()  const;
		double getHWRatio()  const;

		//The actual hardware texture
		SDL_Texture* ptr;
	private:
		//Image dimensions
		int mWidth;
		int mHeight;
	};
}

