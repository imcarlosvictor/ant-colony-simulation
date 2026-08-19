#include "../include/window.h"


Window::Window(int width, int height, std::string title) {
	this->width = width;
	this->height = height;
	this->title = title;
	this->window = nullptr;
	this->renderer = nullptr;
	this->surface = nullptr;
	this->texture = nullptr;
	this->window_flags = 0;
}

Window::~Window() {
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

	/* /1* this->surface = SDL_LoadBMP("sample.bmp"); *1/ */
	/* this->surface = SDL_LoadJPG("../assets/ant.jpg"); */
	/* if (!surface) { */
	/* 	SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError()); */
	/* 	return 3; */
	/* } */

	/* this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface); */
	/* SDL_DestroySurface(this->surface); */
	/* this->surface = nullptr; */
	/* if (!texture) { */
	/* 	SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError()); */
	/* 	return 3; */
	/* } */

	// Logic for window creation and deletion from user inputs
	bool quit = false;
	while (!quit) {
		while (SDL_PollEvent(&this->event)) {
			if (this->event.type == SDL_EVENT_QUIT) {
				quit = true;
			}
		}
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(this->renderer);
		SDL_RenderTexture(this->renderer, this->texture, NULL, NULL);
		SDL_RenderPresent(this->renderer);
	}	
	
	return 0;
}

void Window::mouseEvent(std::vector<Tile>* maze) {

}
