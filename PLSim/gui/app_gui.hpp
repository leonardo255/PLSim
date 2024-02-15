//
//  app.hpp
//  PLSim
//
//  Created by Lennart on 13/02/2024.
//

#ifndef app_gui_hpp
#define app_gui_hpp

#include "app.hpp"
#include "my_menu_bar.hpp"
#include "my_node_editor.hpp"
#include <string>


class AppGUI : public App{
public:
    AppGUI() : App() {}
    
    virtual void startUp() final
    {
    }
    
    virtual void drawGUI() final{
        
        bool open = true; // You can set this based on your needs
        ImGui::Begin("Test", &open,
                     ImGuiWindowFlags_NoMove |
                     ImGuiWindowFlags_NoResize |
                     ImGuiWindowFlags_NoCollapse |
                     ImGuiWindowFlags_MenuBar |
                     ImGuiWindowFlags_NoTitleBar
                     );
        
        // Menu bar
        menu_bar.Draw();
        
        // Left column
        ImGui::Columns(2, "SplitColumns");
        
        // Right column
        ImGui::NextColumn();
        if (!initialOffsetSet) {
            ImGui::SetColumnOffset(1, ImGui::GetColumnOffset(0) + ImGui::GetColumnWidth(0) * initialOffset);
            initialOffsetSet = true;
        }

        // Node editor
        node_editor.Draw();
        
        ImGui::End();
    }
private:
    int display_w, display_h;
    bool initialOffsetSet = false;
    float initialOffset = 0.3;
    
    gui::NodeEditor node_editor;
    gui::MyMenuBar menu_bar;
};

#endif /* app_gui_hpp */
