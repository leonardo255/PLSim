//
//  gui_node_input.cpp
//  PLSim
//
//  Created by Lennart on 15/02/2024.
//

#include "gui_node_input.hpp"
#include "imgui.h"
#include "imnodes.h"

namespace gui {

GuiNodeInput::GuiNodeInput(const char* title, int id) : title(title), id(id) {}

void GuiNodeInput::Draw() {
    ImNodes::BeginInputAttribute(id);
    // in between Begin|EndAttribute calls, you can call ImGui UI functions
    ImGui::TextUnformatted(title);
    ImNodes::EndInputAttribute();
}

}
