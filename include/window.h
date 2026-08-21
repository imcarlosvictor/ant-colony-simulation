#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <string>
#include <vector>

#include "tile.h"

class Window {
	public:
		Window(int width, int height, std::string title); 
		~Window(); // clean up window variables
		int createWindow();
		void mouseEvent(std::vector<Tile>* maze);
		void initilizeSimulation();

	private:
		// window parameters 
		int width;
		int height;
		std::string title;

		std::vector<Tile>* maze;

		SDL_Window* window;
		SDL_Renderer* renderer;
		SDL_Surface* surface;
		SDL_Texture* texture;
		SDL_Event event;
		SDL_WindowFlags window_flags;
};
