//
//  gui_node.h
//  PLSim
//
//  Created by Lennart on 15/02/2024.
//

#ifndef gui_node_hpp
#define gui_node_hpp

#include <vector>
#include "imgui.h"
#include "imnodes.h"
#include "gui_node_input.hpp"
#include "gui_node_output.hpp"


namespace gui {


class GuiNode {
public:
    GuiNode(const int id, const char* title);

    void Draw();
    int GetId() const;
    
    void AddInputAttribute(const char* inputTitle);
    void AddStaticAttribute(const char* staticTitle);
    void AddOutputAttribute(const char* outputTitle);

private:
    int current_attr_id = 0;
    const int id;
    const char* title;
    std::vector<GuiNodeInput> input_attributes;
    std::vector<GuiNodeOutput> static_attributes;  // Fix
    std::vector<GuiNodeOutput> output_attributes;
};

}

#endif /* gui_node_hpp */
