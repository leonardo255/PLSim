//
//  NodeEditorPanel.hpp
//  PLSim
//
//  Created by Lennart on 15/02/2024.
//

#ifndef NodeEditorPanel_hpp
#define NodeEditorPanel_hpp

#include <vector>
#include "gui_node.hpp"
#include "gui_link.hpp"


namespace gui{


class NodeEditorPanel{
public:
    NodeEditorPanel();
    
    void OnImGuiRender(int w, int h);
    gui::GuiNode& AddNode(const char* title);
    
    void Save();
    void Load();
    
private:
    std::vector<gui::GuiNode> nodes;
    std::vector<gui::GuiLink> links;
    
    int current_id;
};

}

#endif /* NodeEditorPanel_hpp */
