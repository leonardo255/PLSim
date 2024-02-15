//
//  gui_node_input.hpp
//  PLSim
//
//  Created by Lennart on 15/02/2024.
//

#ifndef gui_node_input_hpp
#define gui_node_input_hpp


namespace gui {

class GuiNodeInput {
public:
    GuiNodeInput(const char* title, int id);

    void Draw();

private:
    const char* title;
    int id;
};

}

#endif /* gui_node_input_hpp */
