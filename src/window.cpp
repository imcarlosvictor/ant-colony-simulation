#include "include/window.h"


Window::Window() {

}

Window::Window(int width, int height, std::string title) {
	this->WIDTH = width;
	this->HEIGHT = height;
	this->WINDOW_TITLE = title;
}

Window::~Window() {
	this->destroy();
}

Window::destroy() {
	SDL_DestroyTexture();
	SDL_DestroyRenderer();
	SDL_DestroySurface();
	SDL_DestroyWindow();
	SDL_Quit();
}

Window::CreateWindow() {
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL %s", SDL_GetError());
		return 3;
	}

	if (!SDL_CreateWindowAndRenderer(this->title, this->width, this->height, SDL_WINDOW_RESIZABLE, this->window, this->renderer)) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
		return 3;
	}

	this->surface = SDL_LoadBMP("sample.bmp");
	if (!surface) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError());
		return 3;
	}

	this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
	if (!texture) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError());
		return 3;
	}

	SDL_DestroySurface(this->surface);

	while (1) {
		SDL_PollEvent(this->event);
		if (this->event.type == SDL_EVENT_QUIT) {
			break;
		}
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(this->renderer);
		SDL_RenderTexture(this->renderer, this->texture, NULL, NULL);
		SDL_RenderPresent(this->renderer);
	}	

	this->destroy();
}
