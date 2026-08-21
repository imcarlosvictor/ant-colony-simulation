#include "../include/map.h"


Map::Map(int window_width, int window_height, SDL_Renderer* renderer) {
	this->width = window_width / 10;
	this->height = window_height / 10;
	this->renderer = renderer;
}

void Map::createMap() {
	// Coorindates for each til:e
	int grid_x = 0;
	int grid_y = 0;

	for (int i = 0; i < this->height; i++) {
		this->map.push_back(new Tile(this->renderer, this->width, this->height, grid_y, grid_x));
		for (int j = 0; j < this->width; j++) {
			this->map.push_back(new Tile(this->renderer, this->width, this->height, grid_y, grid_x));
			grid_x += 10;
		}
		grid_y += 10;
	}
	std::cout << "map size: "<< this->map.size() << std::endl;
}

int Map::getWidth() {
	return this->width;
}

int Map::getHeight() {
	return this->height;
}
