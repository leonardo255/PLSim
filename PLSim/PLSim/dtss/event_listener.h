//
//  event_listener.h
//  PLSim
//
//  Created by Lennart on 11/02/2024.
//

#ifndef event_listener_h
#define event_listener_h

#include "bag.h"
#include "atomic.h"


namespace dtss {


template <typename T>
class EventListener{
    
public:
    virtual void stateChange(Atomic<T>* model, unsigned int t) = 0;
    virtual void outputEvent(Atomic<T>* model, const T& value, unsigned int t) = 0;
};

}

#endif /* event_listener_h */
