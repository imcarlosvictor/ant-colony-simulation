#include "../include/gui.h"


menuGUI::menuGUI() {
}

void menuGUI::textWindow(bool* ants_bool, bool* markers_bool, bool* density_bool, bool* wall_bool, bool* food_bool, bool* erase_bool, int* brush_slider_value) {
  ImGui::Begin("SETTINGS");
	ImGui::Text("Welcome to the Ant Colony Simulator");
  ImGui::NewLine();

  // Display Options
  if (ImGui::CollapsingHeader("DISPLAY OPTIONS", ImGuiTreeNodeFlags_DefaultOpen)) {
    ImGui::Checkbox("Ants", ants_bool);
    ImGui::SameLine();
    ImGui::Checkbox("Markers", markers_bool);
    ImGui::SameLine();
    ImGui::Checkbox("Density", density_bool);
    ImGui::NewLine();
    ImGui::NewLine();
  }

  // Map Editor
  if (ImGui::CollapsingHeader("MAP EDITOR", ImGuiTreeNodeFlags_DefaultOpen)) {
    ImGui::Checkbox("Wall", wall_bool);
    ImGui::Checkbox("Food", food_bool);
    ImGui::Checkbox("Erase", erase_bool);
    ImGui::SliderInt("Brush size", brush_slider_value, 0, 10); // brush size
  }

  ImGui::End();
}
