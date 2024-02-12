//
//  dtss_simulator.cpp
//  PLSim
//
//  Created by Lennart on 11/02/2024.
//

#include "dtss_simulator.hpp"


namespace dtss{


template <typename T>
void DTSS_Simulator<T>::computeNextState(const Bag<T>& input){
    computeOutput();
    t++;
    model->delta(input);
    for (auto listener : listeners) {
        listener->stateChange(model, t);
    }
    model->gc_output(model->output_bag);
    model->output_bag.clear();
    output_up_to_date = false;
}


template <typename T>
void DTSS_Simulator<T>::computeOutput(){
    
    if (output_up_to_date) return;
    
    output_up_to_date = true;
    model->output_func(model->output_bag);
    
    for(auto item_iter = model->output_bag.begin(); item_iter != model->output_bag.end(); item_iter++){
        for(auto listener : listeners){
            listener->outputEvent(model, *item_iter, t);
        }
    }
}

template class dtss::DTSS_Simulator<int>;

}
