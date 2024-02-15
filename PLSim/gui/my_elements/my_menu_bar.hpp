//
//  my_menu_bar.hpp
//  PLSim
//
//  Created by Lennart on 14/02/2024.
//

#ifndef my_menu_bar_hpp
#define my_menu_bar_hpp

#include "menu_bar.hpp"

#include "imgui.h"
#include "my_node_editor.hpp"


namespace gui{


class MyMenuBar : public MenuBar{
public:
    virtual void update() final{
        
        if (ImGui::BeginMenu("File")) {
            // Save action
            ImGui::MenuItem("Save", "Ctrl+S");
            // Load action
            ImGui::MenuItem("Load", "Ctrl+O");
            ImGui::Separator();
            ImGui::MenuItem("Exit", "Alt+F4 / CMD+Q");
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Edit")) {
            ImGui::MenuItem("Cut", "Ctrl+X");
            ImGui::MenuItem("Copy", "Ctrl+C");
            ImGui::MenuItem("Paste", "Ctrl+V");
            ImGui::EndMenu();
        }
    }
};
}

#endif /* my_menu_bar_hpp */
