//
//  Window.cpp
//  PLSim
//
//  Created by Lennart on 16/02/2024.
//

#define GL_SILENCE_DEPRECATION

#include "Window.hpp"
#include <iostream>

namespace gui
{


Window::Window()
{
}

Window::~Window(){}

int Window::GetWidth(){
    return width;
}

int Window::GetHeight(){
    return height;
}

}
