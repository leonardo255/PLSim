//
//  app.cpp
//  PLSim
//
//  Created by Lennart on 13/02/2024.
//

#define GL_SILENCE_DEPRECATION
#include "app.hpp"
#include <OpenGL/OpenGL.h>
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl2.h"
#include "imnodes.h"


void App::Run() {
    this->startUp();

    while (!glfwWindowShouldClose(window)) {
        // Poll events at the beginning of the loop
        glfwPollEvents();

        // Update ImGui DisplaySize
        glfwGetFramebufferSize(window, &display_w, &display_h);
        io->DisplaySize = ImVec2((float)display_w, (float)display_h);
        
        // Start Frame
        ImGui_ImplOpenGL2_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        
        ImGui::SetNextWindowSize(io->DisplaySize);
        ImGui::SetNextWindowPos(ImVec2(0, 0));

        this->drawGUI();

        ImGui::Render();

        // Set OpenGL viewport and clear the buffer
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Render ImGui DrawData using OpenGL2
        ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

        // Swap buffers
        glfwSwapBuffers(window);
    }
}


bool App::InitGLFW() {
    if (!glfwInit()) {
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);  // Use OpenGL 2
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);  // Use OpenGL 2
    glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);

    window = glfwCreateWindow(display_w, display_h, "Simulai", NULL, NULL);
    
    if (!window) {
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);

    return true;
}
