#include "../include/map.h"


Map::Map(int width, int height, SDL_Renderer* renderer) {
	this->width = width;
	this->height = height;
	this->renderer = renderer;
}

void Map::createMap() {
	int grid_x = 0;
	int grid_y = 0;

	for (int i = 0; i < grid_y; i++) {
		for (int j = 0; j < grid_x; j++) {
			this->maze.push_back(new Tile(this->renderer, this->width, this->height, grid_y, grid_x));
			grid_x += this->width;
		}
		grid_x = 0; // set to 0 once starting a new row
	}
}

int Map::getWidth() {
	return this->width;
}

int Map::getHeight() {
	return this->height;
}
