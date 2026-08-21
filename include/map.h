#pragma once
#include <vector>
#include <string>

#include "tile.h"


class Map {
	public:
		Map(int width, int height, SDL_Renderer* renderer);
		void createMap();
		int getWidth();
		int getHeight();

	private:
		int width;
		int height;
		std::vector<Tile*> map;

		SDL_Renderer* renderer;
};
