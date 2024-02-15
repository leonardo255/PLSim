//
//  my_node_editor.cpp
//  PLSim
//
//  Created by Lennart on 15/02/2024.
//

#include "my_node_editor.hpp"

#include <fstream>
#include "imnodes.h"


namespace gui{


NodeEditor::NodeEditor(){
    
    current_id = 0;
    
    // Setup nodes
    gui::GuiNode& source = AddNode("Source");
    source.AddOutputAttribute("Output");
    
    gui::GuiNode& manu1 = AddNode("Manufacturer1");
    manu1.AddInputAttribute("Input");
    manu1.AddOutputAttribute("Output");
    
    gui::GuiNode& manu2 = AddNode("Manufacturer2");
    manu2.AddInputAttribute("Input");
    manu2.AddInputAttribute("Input2");
    manu2.AddOutputAttribute("Output");
    
    gui::GuiNode& drain = AddNode("Drain");
    drain.AddInputAttribute("Input");
}

void NodeEditor::Draw(){
    
    ImNodes::BeginNodeEditor();
    
    /*
    if (ImGui::IsWindowFocused(ImGuiFocusedFlags_RootAndChildWindows) && ImNodes::IsEditorHovered() && ImGui::IsKeyDown(ImGuiKey_A))
    {
        AddNode("New node");
    }
     */
    
    for (auto& node : nodes) { node.Draw(); }
    for (auto& link : links) { link.Draw(); }
    
    ImNodes::EndNodeEditor();
    
    int startAttr, endAttr;
    if (ImNodes::IsLinkCreated(&startAttr, &endAttr)) {
        GuiLink link(current_id++, startAttr, endAttr);
        links.push_back(link);
    }

}

gui::GuiNode& NodeEditor::AddNode(const char* title) {
    
    int node_id = current_id++;
    gui::GuiNode new_node(node_id, title);
    //ImNodes::SetNodeScreenSpacePos(node_id, ImGui::GetMousePos());
    ImNodes::SnapNodeToGrid(node_id);
    
    nodes.emplace_back(new_node);
        
    return nodes.back();
}

} // namespace


