//
//  gui_node_output.cpp
//  PLSim
//
//  Created by Lennart on 15/02/2024.
//

#include "gui_node_output.hpp"
#include "imgui.h"
#include "imnodes.h"

namespace gui {

GuiNodeOutput::GuiNodeOutput(const char* title, int id) : title(title), id(id) {}

void GuiNodeOutput::Draw() {
    ImNodes::BeginOutputAttribute(id);
    // in between Begin|EndAttribute calls, you can call ImGui UI functions
    ImGui::TextUnformatted(title);
    ImNodes::EndOutputAttribute();
}

}
