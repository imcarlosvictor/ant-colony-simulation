#include "../include/map.h"


Map::Map() {
	this->width = 0;
	this->height = 0;
	this->renderer = nullptr;
}

Map::Map(int window_width, int window_height, SDL_Renderer* renderer) {
	this->width = window_width / 10;
	this->height = window_height / 10;
	this->renderer = renderer;
}

void Map::createMap() {
	const int TILE_SIZE = 10;

	std::cout << "map size: "<< this->map.size() << std::endl;
	for (int row = 0; row < this->height; row++) {
		for (int col = 0; col < this->width; col++) {
			TileState state = (col % 10 == 0) ? PHEROMONE : FLOOR;
				this->map.push_back(new Tile(this->renderer, TILE_SIZE, TILE_SIZE, col, row, state));
		}
	}
	std::cout << "map size: "<< this->map.size() << std::endl;
}

void Map::renderMap() {
	/*
	 * Renders the map while the window is active
	 */
	for (auto* tile : this->map) {
		tile->renderTile();
	}
}

int Map::getWidth() {
	return this->width;
}

int Map::getHeight() {
	return this->height;
}
