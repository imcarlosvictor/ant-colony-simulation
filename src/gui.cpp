#include "../include/gui.h"


menuGUI::menuGUI() {
}

void menuGUI::textWindow(bool* ants_bool, bool* markers_bool, bool* density_bool, bool* wall_bool, bool* food_bool, bool* erase_bool, int* brush_slider_value) {
  ImGui::Begin("Debug menu");
	ImGui::Text("Hello, world %d", 123);
  ImGui::Button("Save");
  ImGui::End();

  // Display Options
  ImGui::Begin("Display Options");
  ImGui::Checkbox("Ants", ants_bool);
  ImGui::Checkbox("Markers", markers_bool);
  ImGui::Checkbox("Density", density_bool);
  ImGui::End();

  // Map Editor
  ImGui::Begin("Map Editor");
  ImGui::Checkbox("Wall", wall_bool);
  ImGui::Checkbox("Food", food_bool);
  ImGui::Checkbox("Erase", erase_bool);
  ImGui::SliderInt("Brush size", brush_slider_value, 0, 10); // brush size
  ImGui::End();
}
