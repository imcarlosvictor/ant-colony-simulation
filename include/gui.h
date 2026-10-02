#pragma once
#include "../lib/imgui/imgui.h"
#include "../lib/imgui/backends/imgui_impl_sdl3.h"
#include "../lib/imgui/backends/imgui_impl_sdlrenderer3.h"

#include <iostream>


class menuGUI {
	public:
		menuGUI();
		/* void textWindow(bool* test_bool); */
		void textWindow(bool* ants_bool, bool* markers_bool, bool* density_bool, bool* wall_bool, bool* food_bool, bool* erase_bool, int* brush_slider_value);

};
