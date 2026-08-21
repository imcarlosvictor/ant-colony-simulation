#pragma once
#include <SDL3/SDL.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

#include <iostream>


enum TileState {
	FLOOR,
	WALL,
	FOOD,
	PHEROMONE,
};

class Tile {
	public:
		Tile(SDL_Renderer* renderer, int width, int height, int x, int y);
		void renderTile();
		void setTrail();
		void setFood();
		TileState getTileInfo();
		int getWidth();
		int getHeight();

	private:
		TileState tile_state;
		int grid_x;
		int grid_y;
		int width;
		int height;
		SDL_Renderer* renderer;
};
