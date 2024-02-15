//
//  menu_bar.cpp
//  PLSim
//
//  Created by Lennart on 14/02/2024.
//

#include "menu_bar.hpp"
#include "imgui.h"

void gui::MenuBar::Draw(){
    
    if(ImGui::BeginMenuBar())
    {
        this->update();
        ImGui::EndMenuBar();
    }
}
