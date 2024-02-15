//
//  my_node_editor.hpp
//  PLSim
//
//  Created by Lennart on 15/02/2024.
//

#ifndef my_node_editor_hpp
#define my_node_editor_hpp

#include <vector>
#include "gui_node.hpp"
#include "gui_link.hpp"


namespace gui{


class NodeEditor{
public:
    NodeEditor();
    
    void Draw();
    gui::GuiNode& AddNode(const char* title);
    
    void Save();
    void Load();
    
private:
    std::vector<gui::GuiNode> nodes;
    std::vector<gui::GuiLink> links;
    
    int current_id;
};

}

#endif /* my_node_editor_hpp */
