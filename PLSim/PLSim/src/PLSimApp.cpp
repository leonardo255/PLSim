//
//  PLSimApp.cpp
//  PLSim
//
//  Created by Lennart on 17/02/2024.
//

#include "App.hpp"
#include "EditorLayer.hpp"


class PLSimApp : public App
{
public:
    PLSimApp()
    {
        PushLayer(new EditorLayer());
    }
};

App* CreateApp()
{
    return new PLSimApp;
}
