//
//  gui_node.cpp
//  PLSim
//
//  Created by Lennart on 15/02/2024.
//

#include "gui_node.hpp"
#include <iostream>

namespace gui {


GuiNode::GuiNode(const int id, const char* title) : id(id), title(title) {}


void GuiNode::Draw() {
    
    ImNodes::BeginNode(this->id);
    
    // Title Bar
    ImNodes::BeginNodeTitleBar();
    ImGui::TextUnformatted(title);
    ImNodes::EndNodeTitleBar();
    
    // Inputs
    for (size_t i = 0; i < input_attributes.size(); ++i) {
        input_attributes[i].Draw();
    }

    // Outputs
    for (size_t i = 0; i < output_attributes.size(); ++i) {
        output_attributes[i].Draw();
    }
    
    ImNodes::EndNode();
}


int GuiNode::GetId() const {
    return id;
}

void GuiNode::AddInputAttribute(const char* inputTitle) {
    input_attributes.emplace_back(inputTitle, (id << 8) + current_attr_id++);
}

void GuiNode::AddStaticAttribute(const char* staticTitle) {
    static_attributes.emplace_back(staticTitle, (id << 16) + current_attr_id++);
}

void GuiNode::AddOutputAttribute(const char* outputTitle) {
    output_attributes.emplace_back(outputTitle, (id << 24) + current_attr_id++);
}

}
