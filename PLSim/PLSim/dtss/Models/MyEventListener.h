//
//  MyEventListener.h
//  PLSim
//
//  Created by Lennart on 11/02/2024.
//

#ifndef MyEventListener_h
#define MyEventListener_h

#include <iostream>
#include "event_listener.h"
#include "MyAtomicModel.h"


namespace dtss {

class MyEventListener : public EventListener<int> {
public:
    MyEventListener(MyAtomicModel* m) : model(m) {}

    void stateChange(Atomic<int>* model, unsigned int t) override {
        std::cout << "State Change at time " << t << ": New state is " << this->model->get_state() << std::endl;
    }

    void outputEvent(Atomic<int>* model, const int& value, unsigned int t) override {
        std::cout << "Output Event at time " << t << ": Received output " << value << std::endl;
    }
private:
    MyAtomicModel* model;
};

}

#endif /* MyEventListener_h */
