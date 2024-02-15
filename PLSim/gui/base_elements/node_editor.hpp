//
//  node_editor.hpp
//  PLSim
//
//  Created by Lennart on 15/02/2024.
//

#ifndef node_editor_hpp
#define node_editor_hpp

#include <vector>
#include "gui_node.h"
#include "gui_link.h"


namespace gui{
    
class NodeEditor{

public:
    NodeEditor() {}
    virtual ~NodeEditor() {}
    
    void display();
    virtual void update() = 0;
    
protected:
    int node_hovered;

    std::vector<gui::GuiNode> nodes;
    std::vector<gui::Link> links;
};
}

#endif /* node_editor_hpp */
