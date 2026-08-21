#include <SDL3/SDL.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

#include <string>


enum State {
	FLOOR,
	WALL,
	FOOD,
	PHEROMONE,
};

class Tile {
	public:
		Tile(SDL_Renderer* renderer, int width, int height, int x, int y);
		void setWall();
		void setFloor();
		void setTrail();
		void setFood();
		State getTileInfo();
		int getWidth();
		int getHeight();

	private:
		State tile_state;
		int x;
		int y;
		int width;
		int height;
		SDL_Renderer* renderer;
};
