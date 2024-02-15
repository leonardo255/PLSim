//
//  product_movement_event.cpp
//  PLSim
//
//  Created by Lennart on 13/02/2024.
//

#include "product_movement_event.hpp"
#include "connector.hpp"

void ProductMovementEvent::processEvent()
{
    if (!source->getOutputConnectors().empty()) {
        std::shared_ptr<Connector> connector = source->getOutputConnectors()[0];
        connector->sendProduct(product);
    }
}
