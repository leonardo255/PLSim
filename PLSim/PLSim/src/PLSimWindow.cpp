//
//  PLSimWindow.cpp
//  PLSim
//
//  Created by Lennart on 17/02/2024.
//
#define GL_SILENCE_DEPRECATION

#include "PLSimWindow.hpp"
#include <iostream>


static uint8_t s_windowCount = 0;


PLSimWindow::PLSimWindow() {}


void PLSimWindow::Init(const std::string& title,uint32_t width, uint32_t height)
{
    if (s_windowCount == 0) {
        if (!glfwInit()) {
            std::cerr << "Error: Failed to initialize GLFW." << std::endl;
            // Handle error appropriately
        } else {
            std::cout << "GLFW initialized successfully." << std::endl;
        }
        glfwSetErrorCallback(error_callback);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);

    m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    
    if (!m_window && s_windowCount == 0) {
        glfwTerminate();
    }
    else{
        ++s_windowCount;
    }

    glfwMakeContextCurrent(m_window);
    glfwSetKeyCallback(m_window, KeyCallback);
}

void PLSimWindow::Shutdown()
{
    glfwDestroyWindow(m_window);
    --s_windowCount;

    if (s_windowCount == 0)
    {
        glfwTerminate();
    }
}

void PLSimWindow::OnUpdate(){
    
    //glViewport(0, 0, width, height);
    //glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
    //glClear(GL_COLOR_BUFFER_BIT);
    
    glfwSwapBuffers(m_window);
}


