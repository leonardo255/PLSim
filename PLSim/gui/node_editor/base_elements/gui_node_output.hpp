//
//  gui_node_output.hpp
//  PLSim
//
//  Created by Lennart on 15/02/2024.
//

#ifndef gui_node_output_hpp
#define gui_node_output_hpp

namespace gui {

class GuiNodeOutput {
public:
    GuiNodeOutput(const char* title, int id);

    void Draw();

private:
    const char* title;
    int id;
};

}

#endif /* gui_node_output_hpp */
