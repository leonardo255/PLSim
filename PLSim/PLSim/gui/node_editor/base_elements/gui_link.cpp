//
//  gui_link.cpp
//  PLSim
//
//  Created by Lennart on 15/02/2024.
//

#include "gui_link.hpp"
#include "imnodes.h"
#include <printf.h>

namespace gui {


GuiLink::GuiLink(int current_id, int startAttr, int endAttr) : id(current_id), start_attr(startAttr), end_attr(endAttr){}

void GuiLink::Draw() const {
    ImNodes::Link(this->id, this->start_attr, this->end_attr);
}

int GuiLink::GetId() const { return this->id; }

}
