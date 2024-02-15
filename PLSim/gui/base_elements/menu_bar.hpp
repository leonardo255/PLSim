//
//  menu_bar.hpp
//  PLSim
//
//  Created by Lennart on 14/02/2024.
//

#ifndef menu_bar_hpp
#define menu_bar_hpp

namespace gui{
    
class MenuBar{

public:
    MenuBar() {}
    virtual ~MenuBar() {}
    
    void Draw();
    virtual void update() = 0;
    
protected:
    
};
}

#endif /* menu_bar_hpp */
