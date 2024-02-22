//
//  main.cpp
//  PLSim
//
//  Created by Lennart on 11/02/2024.
//

#include <iostream>

#include "dess_simulator.hpp"
#include "product_movement_event.hpp"
#include "EditorLayer.hpp"
#include "App.hpp"

extern App* CreateApp();


int main(int argc, const char * argv[]) {
    
    auto app = CreateApp();
    app->Run();
    delete app;
    
    /*
    std::shared_ptr<DESS_Simulator> simulator = std::make_shared<DESS_Simulator>();
    
    auto product = std::make_shared<Product>(std::vector<std::string>{"Source", "Assembly", "Drain"});
    
    auto source = std::make_shared<Node>(simulator, "Source", 0, 0.0);
    auto manufacturing = std::make_shared<Node>(simulator, "Manufacturing", 0, 24.5);
    auto assembly = std::make_shared<Node>(simulator, "Assembly", 0, 4.5);
    auto drain = std::make_shared<Node>(simulator, "Drain", 0, 10.2);
    
    source->connectTo(manufacturing);
    manufacturing->connectTo(assembly);
    assembly->connectTo(drain);
    
    std::shared_ptr<ProductMovementEvent> initialEvent = std::make_shared<ProductMovementEvent>(source, product);
    simulator->scheduleEventAfterDelay(initialEvent, 0.0);
    
    simulator->run();
    
     */
    return 0;
}
