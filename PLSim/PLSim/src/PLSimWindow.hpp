//
//  PLSimWindow.hpp
//  PLSim
//
//  Created by Lennart on 17/02/2024.
//

#ifndef PLSimWindow_hpp
#define PLSimWindow_hpp

#include "Window.hpp"


class PLSimWindow : public gui::Window
{
public:
    PLSimWindow();
    virtual ~PLSimWindow() {}
    
    void OnUpdate() override;
    void Init(const std::string& title,uint32_t width, uint32_t height) override;
    void Shutdown() override;
    
    GLFWwindow* GetNativeWindow() const override { return m_window; }
    
private:
    GLFWwindow* m_window;
};


#endif /* PLSimWindow_hpp */
