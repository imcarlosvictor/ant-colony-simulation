#pragma once
#include <iostream>
#include <string>
#include <vector>

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "map.h"
#include "tile.h"
#include "gui.h"
#include "../lib/imgui/backends/imgui_impl_sdl3.h"
#include "../lib/imgui/backends/imgui_impl_sdlrenderer3.h"

class Window {
	public:
		Window(int width, int height, std::string title); 
		~Window(); // clean up window variables
		int createWindow();
		void mouseEvent(std::vector<Tile>* maze);
		void startSimulation();

	private:
		int width;
		int height;
		std::string title;
		Map* simulation_map;

		SDL_Window* window;
		SDL_Renderer* renderer;
		SDL_Surface* surface;
		SDL_Texture* texture;
		SDL_Event event;
		SDL_WindowFlags window_flags;

		menuGUI* mGUI;
};
