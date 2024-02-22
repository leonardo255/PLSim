//
//  MyAtomicModel.h
//  PLSim
//
//  Created by Lennart on 11/02/2024.
//

#ifndef MyAtomicModel_h
#define MyAtomicModel_h

#include <iostream>
#include "atomic.h"
#include "bag.h"


namespace dtss {


class MyAtomicModel : public Atomic<int> {
    
public:
    MyAtomicModel(std::string name) : Atomic<int>(name), state(0) {}
    
    void delta(const Bag<int>& input) override {
        
        for (const auto& item : input) {
            state += item;
        }
        
        std::cout << "Delta: " << get_name() << " updated state to " << state << std::endl;
    }
    
    void output_func(Bag<int>& output_bag) override {
        output_bag.insert(state);
        std::cout << "Output Function: " << get_name() << " produced output " << state << std::endl;
    }
    
    void gc_output(Bag<int>& output_bag) override {}
    
    int get_state() const { return state; }
    
private:
    int state;
};

}

#endif /* MyAtomicModel_h */
