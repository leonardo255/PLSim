//
//  HierarchyPanel.cpp
//  PLSim
//
//  Created by Lennart on 22/02/2024.
//

#include "HierarchyPanel.hpp"
#include "IconsMaterialDesignIcons.h"
#include "imgui.h"

HierarchyPanel::HierarchyPanel()
{}

void HierarchyPanel::OnImGuiRender(int w, int h)
{
    ImGui::BeginChild("HierarchyPanel", ImVec2(w,h), true);
    
    ImGui::BeginChild("SceneHierarchyPanel", ImVec2(w,h*0.48), true);
    ImGui::Text("Scene");
    ImGui::Separator();
    
    // List of Scenes
    // m_Registry->GetScenes()
    // For each Entity in Scene -> DrawNodeEntity();
    
    if (ImGui::Button(ICON_MDI_PLUS "Add Scene")){}
    ImGui::EndChild();
    
    ImGui::BeginChild("ProductHierarchyPanel", ImVec2(w,h*0.48), true);
    ImGui::Text("Products");
    ImGui::Separator();
    
    // List of Products
    // m_Registry->GetProducts()
    // For each Products -> DrawProduct();
    
    if (ImGui::Button(ICON_MDI_PLUS "Add Product")){}
    ImGui::EndChild();
    
    ImGui::EndChild();
}

void HierarchyPanel::DrawNodeEntity()
{
    // Get Tag component
    
    if (ImGui::IsItemClicked())
    {
        // Set selection context in Scene/EditorLayer?
    }
}

void HierarchyPanel::DrawProduct()
{
    // Get Tag component?
}
