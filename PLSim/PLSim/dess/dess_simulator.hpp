//
//  dess_simulator.hpp
//  PLSim
//
//  Created by Lennart on 13/02/2024.
//

#ifndef dess_simulator_hpp
#define dess_simulator_hpp

#include <queue>
#include "event.hpp"


class DESS_Simulator{
public:
    void run();
    void scheduleEventAfterDelay(std::shared_ptr<Event> event, double time);
    double getNow() const { return current_time; }
private:
    double current_time = 0.0;
    std::priority_queue<std::pair<double, std::shared_ptr<Event>>> events;
};

#endif /* dess_simulator_hpp */
