#include "../include/window.h"
#include "../include/map.h"
#include "../include/gui.h"


Window::Window(int width, int height, std::string title) {
	this->width = width;
	this->height = height;
	this->title = title;
	this->window = nullptr;
	this->renderer = nullptr;
	this->surface = nullptr;
	this->texture = nullptr;
	this->window_flags = 0;
	/* this->simulation_map = Null; */
}

Window::~Window() {
	// ImGui
	ImGui_ImplSDLRenderer3_Shutdown();
	ImGui_ImplSDL3_Shutdown();
	ImGui::DestroyContext();	

	// SDL
	if (this->mGUI) delete this->mGUI;
	if (this->simulation_map) delete this->simulation_map;
	if (this->texture) SDL_DestroyTexture(this->texture);
	if (this->renderer) SDL_DestroyRenderer(this->renderer);
	if (this->window) SDL_DestroyWindow(this->window);
	SDL_Quit();
}

int Window::createWindow() {
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL %s", SDL_GetError());
		return 1;
	}

	if (!SDL_CreateWindowAndRenderer(this->title.c_str(), this->width, this->height, this->window_flags, &this->window, &this->renderer)) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
		return 1;
	}

	// Create map
	this->startSimulation();
	
	// ----[ GUI | One-Time SETUP ]----
	IMGUI_CHECKVERSION();
	ImGui::CreateContext(); // Context (the data); points the ImGui's global struct (Text, Button, Begin, etc.)
	ImGui_ImplSDL3_InitForSDLRenderer(this->window, this->renderer); // Platform Backend (get input in); wires SDL's window/input system to ImGui's internal input model
	ImGui_ImplSDLRenderer3_Init(this->renderer); // Renderer backend (get pixels out); translate abstract intructions from ImGui to SDL Render
	this->mGUI= new menuGUI();
	// --------------------------------

	// Logic for window creation and deletion from user inputs
	bool quit = false;
	while (!quit) {
		while (SDL_PollEvent(&this->event)) { 
			ImGui_ImplSDL3_ProcessEvent(&this->event); // allow for ImGui to see input events
																								 
			if (this->event.type == SDL_EVENT_QUIT) {
				quit = true;
			}
		}

		// ----[ GUI | Per-Frame Loop SETUP ]----
		// Build ImGui frame before building any UI (order matters!)
		ImGui_ImplSDLRenderer3_NewFrame(); // resets render-specific frame state
		ImGui_ImplSDL3_NewFrame(); // computes per-frame data (window size, mouse cursor shape, etc.)
		ImGui::NewFrame(); // drop cuurent frame for a new frame
		// add methods here
		this->mGUI->textWindow(); 
		ImGui::Render(); // translates draw data (Begin/Text/Button) from ImGui to SDL
		// --------------------------------------

		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(this->renderer);
		SDL_RenderTexture(this->renderer, this->texture, NULL, NULL);
		
		// Render the map & GUI each loop for updates
		this->simulation_map->renderMap(); // render map
		ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), this->renderer); // render GUI
		SDL_RenderPresent(this->renderer); // displays everything drawn/renderered
	}	
	
	return 0;
}

void Window::mouseEvent(std::vector<Tile>* maze) {

}

void Window::startSimulation() {
	this->simulation_map = new Map(this->width, this->height, this->renderer);
	this->simulation_map->createMap();
}
