//
//  Window.hpp
//  PLSim
//
//  Created by Lennart on 16/02/2024.
//

#ifndef Window_hpp
#define Window_hpp

#include <GLFW/glfw3.h>
#include <string>

namespace gui{

class Window{
public:
    Window();
    virtual ~Window();
    
    virtual GLFWwindow* GetNativeWindow() const = 0;
    int GetWidth();
    int GetHeight();
    virtual void Init(const std::string& title,uint32_t width, uint32_t height) = 0;
    virtual void Shutdown() = 0;
    virtual void OnUpdate() = 0;
    
protected:
    std::string title;
    uint32_t width;
    uint32_t height;
    GLFWwindow* window;
    
    
     // Example callback function to close window on ESC key. Callback is registered in constructor
    static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
    }
    
    static void error_callback(int error, const char* description)
    {
        fprintf(stderr, "Error: %s\n", description);
    }
    
};
}

#endif /* Window_hpp */
