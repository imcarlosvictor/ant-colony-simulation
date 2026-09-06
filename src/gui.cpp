#include "../include/gui.h"


menuGUI::menuGUI() {
}

void menuGUI::textWindow() {
  ImGui::Begin("Debug menu");

	ImGui::Text("Hello, world %d", 123);
  ImGui::Button("Save");

  ImGui::End();
}
