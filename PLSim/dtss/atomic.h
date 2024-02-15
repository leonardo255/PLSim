//
//  atomic.h
//  PLSim
//
//  Created by Lennart on 11/02/2024.
//

#ifndef atomic_h
#define atomic_h

#include <string>
#include "bag.h"


namespace dtss {

template <typename T>
class DTSS_Simulator;


template <typename T>
class Atomic {
    friend class DTSS_Simulator<T>;
    
public:
    Atomic(const std::string& name) : model_name(name) {}
    
    virtual void delta(const Bag<T>& input) = 0;
    virtual void output_func(Bag<T>& output_bag) = 0;
    virtual void gc_output(Bag<T>& output_bag) = 0;
    
    std::string get_name() const { return model_name; }
private:
    std::string model_name;
    Bag<T> output_bag;
};

}

#endif /* atomic_h */
