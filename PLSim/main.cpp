//
//  main.cpp
//  PLSim
//
//  Created by Lennart on 11/02/2024.
//

#include <iostream>
#include "MyAtomicModel.h"
#include "MyEventListener.h"
#include "dtss_simulator.hpp"


int main(int argc, const char * argv[]) {
    
    dtss::MyAtomicModel my_model("Source");
    dtss::MyEventListener my_listener(&my_model);
    
    dtss::DTSS_Simulator<int> simulator(&my_model);
    //simulator.addEventListener(&my_listener);
    
    dtss::Bag<int> inputBag;
    int input;
    
    while(true){
        std::cin >> input;
        inputBag.clear();
        inputBag.insert(input);
        simulator.computeNextState(inputBag);
    }
    
    return 0;
}
