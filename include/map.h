#include <vector>
#include <string>


class Map {
	public:
		Map();
		Map(int width, int height);
		~Map();
		void destroy();
		void createMap();
		int getWidth();
		int getHeight();

	private:
		int width;
		int height;
};
