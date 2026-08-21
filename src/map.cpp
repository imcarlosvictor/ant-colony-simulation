#include "../include/map.h"


Map::Map(int width, int height, SDL_Renderer* renderer) {
	this->width = width;
	this->height = height;
	this->renderer = renderer;
}

void Map::createMap() {
	int x = 0;
	int y = 0;

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			this->maze.push_back(new Tile(this->renderer, this->width, this->height, y, x));
			x += this->width;
		}
		x = 0; // set to 0 once starting a new row
	}
}

int Map::getWidth() {
	return this->width;
}

int Map::getHeight() {
	return this->height;
}
