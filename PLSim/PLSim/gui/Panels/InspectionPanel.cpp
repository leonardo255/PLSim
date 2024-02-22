//
//  InspectionPanel.cpp
//  PLSim
//
//  Created by Lennart on 22/02/2024.
//

#include "InspectionPanel.hpp"
#include "imgui.h"

InspectionPanel::InspectionPanel()
{}

void InspectionPanel::OnImGuiRender(int w, int h)
{
    ImGui::BeginChild("InspectionPanel", ImVec2(w,h), true, ImGuiChildFlags_None);
    
    if (ImGui::BeginTabBar("#tabs"))
    {
        if (ImGui::BeginTabItem("Properties")) {
            ImGui::Text("Properties");
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Console")) {
            ImGui::Text("Console");
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Results")) {
            ImGui::Text("Simulation Results");
            ImGui::EndTabItem();
        }
                    
        ImGui::EndTabBar();
    }
    
    ImGui::EndChild();
}

