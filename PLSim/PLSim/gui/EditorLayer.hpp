//
//  EditorLayer.hpp
//  PLSim
//
//  Created by Lennart on 16/02/2024.
//

#ifndef EditorLayer_hpp
#define EditorLayer_hpp

#include "Layer.hpp"
#include "NodeEditorPanel.hpp"
#include "HierarchyPanel.hpp"
#include "InspectionPanel.hpp"


class EditorLayer : public gui::Layer
{
public:
    EditorLayer();
    virtual ~EditorLayer() = default;
    
    virtual void OnAttach() override;
    virtual void OnDetach() override;
    
    void OnUpdate() override;
    virtual void OnImGuiRender() override;
    //void OnEvent(Event& e) override;
    
    void OnSceneSimulate();
    void OnSceneStop();
    void OnScenePause();
    
    void DrawEditorToolbar();
    void DrawSimSettings();
    
private:
    bool showSimSettings = false;
    
    enum class SceneState
    {
        Edit = 0, Simulate = 1
    };
    SceneState m_SceneState = SceneState::Edit;
    
    // Panels
    gui::NodeEditorPanel m_node_editor;
    HierarchyPanel m_hierarchy_panel;
    InspectionPanel m_inspection_panel;
};

#endif /* EditorLayer_hpp */
