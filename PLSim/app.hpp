//
//  app.hpp
//  PLSim
//
//  Created by Lennart on 13/02/2024.
//

#ifndef app_hpp
#define app_hpp

#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_opengl2.h"
#include "imgui_impl_glfw.h"
#include "imnodes.h"

class App {
public:
    App() {
        display_w = 640;
        display_h = 380;
        show_demo_window = false;
        
        InitGLFW();
        
        // Setup context
        ImGui::CreateContext();
        ImGui::StyleColorsDark();
        ImNodes::CreateContext();
        
        // Setup backends
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL2_Init();
        
        glfwSetKeyCallback(window, KeyCallback);
        
        io = &ImGui::GetIO();
    }

    virtual ~App() {
        ImGui_ImplOpenGL2_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImNodes::DestroyContext();
        ImGui::DestroyContext();
        glfwTerminate();
    }

    void Run();
    virtual void startUp() = 0;
    virtual void drawGUI() = 0;

protected:
    GLFWwindow* window;
    ImGuiIO* io;
    int display_w, display_h;
    bool show_demo_window;
    
private:
    static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
    }

    bool InitGLFW();
};

#endif /* app_hpp */
