//
//  Renderer2D.hpp
//  PLSim
//
//  Created by Lennart on 05/03/2024.
//

#ifndef Renderer2D_hpp
#define Renderer2D_hpp

#include <string>
#include "imgui.h"

class Renderer2D
{
    
public:
    Renderer2D();
    ~Renderer2D();
    
    static void DrawNode(const ImVec2 position, const std::string& name);
    
private:
    
};

#endif /* Renderer2D_hpp */
