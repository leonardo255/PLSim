//
//  App.hpp
//  PLSim
//
//  Created by Lennart on 13/02/2024.
//

#ifndef App_hpp
#define App_hpp


#include "Window.hpp"
#include "LayerStack.hpp"
#include "ImGuiLayer.hpp"
#include <mutex>


class App {
private:
    
    
public:
    App();
    App(App& other) = delete;
    void operator=(const App &) = delete;
    virtual ~App();
    
    static App& GetInstance();
    
    gui::Window& GetWindow();

    void Initialise();
    void Run();
    void Close();
    void PushLayer(gui::Layer* layer);
    void PushOverlay(gui::Layer* layer);
    
private:
    static App* s_Instance;
    static std::mutex mutex_;
    
    bool m_running = false;
    gui::Window* m_window;
    gui::LayerStack m_LayerStack;
    gui::ImGuiLayer* m_ImGuiLayer;
};

// Defined in implementation file
App* CreateApplication();

#endif /* app_hpp */
