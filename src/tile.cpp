#include "../include/tile.h"


Tile::Tile(SDL_Renderer* renderer, int width, int height, int col, int row) {
	this->width = width;
	this->height = height;
	this->grid_x = col * this->width; // determine the x coordinate
	this->grid_y = row * this->height; // determine the y coordinate
	this->renderer = renderer;
	this->tile_state = FLOOR; // initialize all tiles as floor
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
			/* SDL_SetRenderDrawColor(this->renderer, 32, 32, 32, 255); // Floor, black */
			SDL_SetRenderDrawColor(this->renderer, 247, 224, 97, 255); // Pheromone, yellow
			break;
		case 1:
			SDL_SetRenderDrawColor(this->renderer, 218, 218, 218, 255); // Wall, grey 
			break;
		case 2:
			SDL_SetRenderDrawColor(this->renderer, 97, 142, 247, 255); // Food, blue
			break;
		case 3:
			SDL_SetRenderDrawColor(this->renderer, 247, 224, 97, 255); // Pheromone, yellow
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

