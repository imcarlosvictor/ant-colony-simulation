#include <vector>
#include <string>


class Map {
	public:
		Map(int width, int height);
		void createMap();
		int getWidth();
		int getHeight();

	private:
		int width;
		int length;
};
