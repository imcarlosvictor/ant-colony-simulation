#pragma once
#include <vector>
#include <iostream>

#include "tile.h"


class Map {
	public:
		Map();
		Map(int width, int height, SDL_Renderer* renderer);
		void createMap(); // initialize map
		void renderMap(); // renders the map while the window is active
		int getWidth();
		int getHeight();

	private:
		int width;
		int height;
		std::vector<Tile*> map;

		SDL_Renderer* renderer;
};
