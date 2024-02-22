//
//  EditorLayer.cpp
//  PLSim
//
//  Created by Lennart on 16/02/2024.
//

#include "EditorLayer.hpp"
#include "App.hpp"
#include "imgui.h"
#include "IconsMaterialDesignIcons.h"


EditorLayer::EditorLayer() : Layer("EditorLayer") {}

void EditorLayer::OnAttach()
{
}

void EditorLayer::OnDetach()
{
}

void EditorLayer::OnUpdate()
{
    //Switch scene state
    // If simulation -> update simulation
}

void EditorLayer::OnImGuiRender()
{
    ImGuiWindowFlags window_flags =
    ImGuiWindowFlags_MenuBar |
    ImGuiWindowFlags_NoMove |
    ImGuiWindowFlags_NoResize |
    ImGuiWindowFlags_NoCollapse |
    ImGuiWindowFlags_NoTitleBar;
    
    ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->Pos);
    ImGui::SetNextWindowSize(viewport->Size);
    
    /*
    ImGuiIO& io = ImGui::GetIO();
    ImGui::SetNextWindowSize(io.DisplaySize);
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    */
    
    static bool dockspaceOpen = true;
    ImGui::Begin("Test", &dockspaceOpen, window_flags);
    
    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowMinSize.x = 370.0f;
    
    
    // Menu bar
    if (ImGui::BeginMenuBar())
    {
        ImGui::SetWindowSize(ImVec2(ImGui::GetWindowSize().x, ImGui::GetWindowSize().y + 60));
        
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Open Project...", "Ctrl+O"))
                //OpenProject();

            ImGui::Separator();

            if (ImGui::MenuItem("New Scene", "Ctrl+N"))
                //NewScene();

            if (ImGui::MenuItem("Save Scene", "Ctrl+S"))
                //SaveScene();

            if (ImGui::MenuItem("Save Scene As...", "Ctrl+Shift+S"))
                //SaveSceneAs();

            ImGui::Separator();

            if (ImGui::MenuItem("Exit"))
                App::GetInstance().Close();
            
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Script"))
        {
            if (ImGui::MenuItem("Reload assembly", "Ctrl+R"))
                //ScriptEngine::ReloadAssembly();
            
            ImGui::EndMenu();
        }

        ImGui::EndMenuBar();
    }
    
    /*
    // Left column
    ImGui::Columns(2, "SplitColumns");
    
    
    // Right column
    ImGui::NextColumn();
    if (!initial_offset_set) {
        ImGui::SetColumnOffset(1, ImGui::GetColumnOffset(0) + ImGui::GetColumnWidth(0) * initial_offset);
        initial_offset_set = true;
    }
     */
    
    // Pop-up windows
    DrawSimSettings();
    
    
    DrawEditorToolbar();
    
    static float w = 200.0f;
    static float h = 600.0f;
    float minWidth = 100.0f;
    float minHeight = 4.0f;
    
    m_hierarchy_panel.OnImGuiRender(w,h);
    
    ImGui::SameLine();
    ImGui::InvisibleButton("vsplitter", ImVec2(8.0f,h));
    if (ImGui::IsItemActive()){
        w += ImGui::GetIO().MouseDelta.x;
        if (w < minWidth) { w = minWidth; }
    }
    ImGui::SameLine();
    
    m_node_editor.OnImGuiRender(0,h);
    
    ImGui::InvisibleButton("hsplitter", ImVec2(-1,8.0f));
    if (ImGui::IsItemActive()){
        h += ImGui::GetIO().MouseDelta.y;
        if (h < minHeight) { h = minHeight; }
    }
    
    
    m_inspection_panel.OnImGuiRender(0,0);
    
    ImGui::End();
}


void EditorLayer::DrawEditorToolbar()
{
    ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoScrollWithMouse;
    //ImGui::Begin("EditorToolbar", nullptr, flags);
    
    const float buttonSize = 32.0f;
    const float toolbarHeight = buttonSize + 16.0f;
    
    bool isSimulating = m_SceneState == SceneState::Simulate;
    
    
    ImGui::BeginChild("Toolbar", ImVec2(0, toolbarHeight), true, flags);
    
    // Colors
    const char* icon = nullptr;
    auto& colors = ImGui::GetStyle().Colors;
    //const auto& buttonHovered = colors[ImGuiCol_ButtonHovered];
    //ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(buttonHovered.x, buttonHovered.y, buttonHovered.z, 0.5f));
    const auto& button = colors[ImGuiCol_Button];
    const auto& buttonActive = colors[ImGuiCol_ButtonActive];
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(buttonActive.x, buttonActive.y, buttonActive.z, 0.5f));
    
    
    // Settings
    if (ImGui::Button(ICON_MDI_TIMER_COG_OUTLINE, ImVec2(buttonSize, buttonSize)))
    {
        showSimSettings = !showSimSettings;
    }

    // Simulate
    ImGui::SameLine();
    if(m_SceneState == SceneState::Edit) { icon = ICON_MDI_TIMER_PLAY_OUTLINE; }
    else if (m_SceneState == SceneState::Simulate) { icon = ICON_MDI_TIMER_CANCEL_OUTLINE; }
    else { icon = ICON_MDI_TIMER_CANCEL_OUTLINE; }
        
    if (ImGui::Button(icon, ImVec2(buttonSize, buttonSize)))
    {
        if (m_SceneState == SceneState::Edit)
            OnSceneSimulate();
        else if (m_SceneState == SceneState::Simulate)
            OnSceneStop();
    }

    // Pause
    ImGui::SameLine();
    if(!isSimulating) { ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(button.x, button.y, button.z, 0.5f)); }
    
    if (ImGui::Button(ICON_MDI_PAUSE, ImVec2(buttonSize, buttonSize)))
    {
            //m_ActiveScene->SetPaused(!isPaused);
    }
    
    if(!isSimulating) { ImGui::PopStyleColor(1); }

    
    // Step forward
    ImGui::SameLine();
    if (ImGui::Button(ICON_MDI_STEP_FORWARD, ImVec2(buttonSize, buttonSize)))
    {
        // Handle button click action here
    }

    
    // Spacing
    ImGui::SameLine();
    ImGui::Spacing();

    
    // Add node
    ImGui::SameLine();
    if (ImGui::Button(ICON_MDI_PLUS, ImVec2(buttonSize, buttonSize)))
    {
        // Handle button click action here
    }
    
    // Delete node
    ImGui::SameLine();
    if (ImGui::Button(ICON_MDI_TRASH_CAN_OUTLINE, ImVec2(buttonSize, buttonSize)))
    {
        /*
        int numSelectedNodes = ImNodes::NumSelectedNodes();
        if (numSelectedNodes > 0)
        {
            int* selectedNodeIds = new int[numSelectedNodes];
            ImNodes::GetSelectedNodes(selectedNodeIds);

            for (int i = 0; i < numSelectedNodes; ++i)
            {
                // Your code to delete or handle the selected node with ID: selectedNodeIds[i]
            }

            delete[] selectedNodeIds;
        }
         */
    }


    ImGui::PopStyleColor(1);
    ImGui::EndChild();
}

void EditorLayer::DrawSimSettings(){
    
    if(!showSimSettings) return;
    
    ImGuiWindowFlags windowFlags =
    ImGuiWindowFlags_NoCollapse |
    ImGuiWindowFlags_NoScrollbar;
    
    if (ImGui::Begin("Custom Window", &showSimSettings, windowFlags)) {
        // Tab bar
        if (ImGui::BeginTabBar("TimeSettingsTabBar")) {
            // "Time" tab
            if (ImGui::BeginTabItem("Time")) {
                static float simulationStart = 0.0f;
                static float simulationStop = 100.0f;
        
                ImGui::Text("Simulation Start");
                ImGui::SameLine();
                ImGui::InputFloat("##SimulationStart", &simulationStart);

                ImGui::Text("Simulation Stop");
                ImGui::SameLine();
                ImGui::InputFloat("##SimulationStop", &simulationStop);

                ImGui::EndTabItem();
            }

            // End tab bar
            ImGui::EndTabBar();
        }
        
        ImGui::End();
    }
}

void EditorLayer::OnSceneSimulate(){

    m_SceneState = SceneState::Simulate;

    //m_ActiveScene = Scene::Copy(m_EditorScene);
    //m_ActiveScene->OnSimulationStart();
}

void EditorLayer::OnSceneStop() {
    if (m_SceneState == SceneState::Simulate)
        //m_ActiveScene->OnSimulationStop();
        
    m_SceneState = SceneState::Edit;
}

void EditorLayer::OnScenePause() {
    if (m_SceneState == SceneState::Edit)
        return;
    //m_ActiveScene->SetPaused(true);
}
