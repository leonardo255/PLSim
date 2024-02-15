//
//  dtss_simulator.h
//  PLSim
//
//  Created by Lennart on 11/02/2024.
//

#ifndef dtss_simulator_hpp
#define dtss_simulator_hpp

#include "atomic.h"
#include "bag.h"
#include "event_listener.h"


namespace dtss {


template <typename T>
class DTSS_Simulator
{
public:
    DTSS_Simulator(Atomic<T>* model) : model(model), t(0), output_up_to_date(false) {}
    
    void computeNextState(const Bag<T>& input);
    void computeOutput();
    unsigned int getTime() const { return t; }
    void addEventListener(EventListener<T>* listener) { listeners.push_back(listener); }
    
private:
    Atomic<T>* model;
    unsigned int t;
    bool output_up_to_date;
    std::list<EventListener<T>*> listeners;
};


}

#endif /* dtss_simulator_h */
