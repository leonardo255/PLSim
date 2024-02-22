//
//  event.hpp
//  PLSim
//
//  Created by Lennart on 13/02/2024.
//

#ifndef event_hpp
#define event_hpp

class Event{
public:
    virtual void processEvent() = 0;
    virtual ~Event() = default;
};

#endif /* event_hpp */
