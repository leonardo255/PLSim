//
//  gui_link.h
//  PLSim
//
//  Created by Lennart on 15/02/2024.
//

#ifndef gui_link_hpp
#define gui_link_hpp


namespace gui {


class GuiLink {
public:
    GuiLink(int current_id, int startAttr, int endAttr);

    void Draw() const;
    int GetId() const;

private:
    int id;
    int start_attr;
    int end_attr;
};

}

#endif /* gui_link_hpp */
