#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <vector>
#include <string>

#include "tile.h"

class Window {
	public:
		Window(); // initialize window variables
		Window(int width, int height, std::string title); 
		~Window(); // clean up window variables
		void destroy(); // clean up window
		void mouseEvent(std::vector<Tile>* maze);
		void createWindow();

	private:
		// window parameters 
		const int WIDTH;
		const int HEIGHT;
		const std::string WINDOW_TITLE;

		std::vector<Tile>* maze;

		SDL_Window* window;
		SDL_Renderer* renderer;
		SDL_Surface* surface;
		SDL_Texture* texture;
		SDL_Event event;
};
