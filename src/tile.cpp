#include "../include/tile.h"


Tile::Tile(SDL_Renderer* renderer, int width, int height, int x, int y) {
	this->grid_x = x;
	this->grid_y = y;
	this->width = width;
	this->height = height;
	this->renderer = renderer;
}

void Tile::renderTile() {
	/* SDL_FRect tile = SDL_FRect(this->x, this->y, this->width, this->height); */
	// Create a tile using a typedef struct
	SDL_FRect rect;
	rect.x = this->grid_x;
	rect.y = this->grid_y;
	rect.w = this->width;
	rect.h = this->height;

	// Determine the tile type and set the color
	switch (this->tile_state) {
		case 0:
			/* SDL_SetRenderDrawColor(this->renderer, 32, 32, 32, 1); // Floor, black */
			SDL_SetRenderDrawColor(this->renderer, 97, 142, 247, 1); // Food, blue
			break;
		case 1:
			SDL_SetRenderDrawColor(this->renderer, 218, 218, 218, 1); // Wall, grey 
			break;
		case 2:
			SDL_SetRenderDrawColor(this->renderer, 97, 142, 247, 1); // Food, blue
			break;
		case 3:
			SDL_SetRenderDrawColor(this->renderer, 247, 224, 97, 1); // Pheromone, yellow
			break;
	};

	SDL_RenderFillRect(this->renderer, &rect);
}

void Tile::setTrail() {

}

void Tile::setFood() {

}

TileState Tile::getTileInfo() {
	return this->tile_state;
}

int Tile::getWidth() {
	return this->width;
}

int Tile::getHeight() {
	return this->height;
}

