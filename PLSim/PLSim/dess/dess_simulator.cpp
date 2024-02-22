//
//  dess_simulator.cpp
//  PLSim
//
//  Created by Lennart on 13/02/2024.
//

#include "dess_simulator.hpp"


void DESS_Simulator::run(){
    
    while(!events.empty()){
        auto next_event = events.top();
        events.pop();
        
        current_time = next_event.first;
        next_event.second->processEvent();
    }
}

void DESS_Simulator::scheduleEventAfterDelay(std::shared_ptr<Event> event, double delay){
    events.push({current_time + delay, event});
}
