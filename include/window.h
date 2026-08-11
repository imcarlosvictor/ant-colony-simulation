#include <SDL3/SDL.h>
#include <vector>
#include <string>

#include "tile.h"

class Window {
	pulic:
		Window(); // initialize window variables
		Window(int width, int height, std::string title); 
		~Window(); // clean up window variables
		void destroy(); // clean up window
		void mouseEvent(std::vector<Tile>* maze);
		void createWindow();

	private:
		// window dimensions
		const int WIDTH;
		const int HEIGHT;

		const std::string WINDOW_TITLE;
		std::vector<Tile>* maze;
};
