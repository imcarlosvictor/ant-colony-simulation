#include <string>


enum State {
	FLOOR,
	WALL,
	FOOD,
};

class Tile {
	public:
		Tile();
		Tile(int width, int ehgiht, int x, int y);
		~Tile();
		void destroy();
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
		int length;
		int width;
};
