//
//  app.cpp
//  PLSim
//
//  Created by Lennart on 13/02/2024.
//

#include "App.hpp"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl2.h"
#include "imnodes.h"

#include "PLSimWindow.hpp"
#include "EditorLayer.hpp"

#include <iostream>
#include <filesystem>
#include <OpenGL/OpenGL.h>

App* App::s_Instance = nullptr;
std::mutex App::mutex_;


App::App()
{
    s_Instance = this;
    m_running = true;
    
    std::filesystem::current_path("/Users/Lennart/Documents/C++/PLSim/PLSim/PLSim");
    
    m_window = new PLSimWindow;
    m_window->Init("SimulAI", 1600, 900);
    
    m_ImGuiLayer = new gui::ImGuiLayer();
    PushOverlay(m_ImGuiLayer);
}

App::~App()
{
}

App& App::GetInstance()
{
    return *s_Instance;
}

void App::Initialise(){
    
}


gui::Window& App::GetWindow(){
    return *m_window;
}

void App::PushLayer(gui::Layer* layer)
{
    m_LayerStack.PushLayer(layer);
    layer->OnAttach();
}

void App::PushOverlay(gui::Layer* layer)
{
    m_LayerStack.PushOverlay(layer);
    layer->OnAttach();
}

void App::Close()
{
    m_running = false;
}

void App::Run()
{
    while(!glfwWindowShouldClose(GetWindow().GetNativeWindow())) {

        glfwPollEvents();
        
        for (gui::Layer* layer : m_LayerStack)
            layer->OnUpdate();
        
        m_ImGuiLayer->Begin();
        
        for (gui::Layer* layer : m_LayerStack)
            layer->OnImGuiRender();
        
        m_ImGuiLayer->End();

        m_window->OnUpdate();
    }
}
