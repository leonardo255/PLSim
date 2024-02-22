//
//  node.cpp
//  PLSim
//
//  Created by Lennart on 13/02/2024.
//

#include <iostream>
#include "node.hpp"
#include "product_movement_event.hpp"


void Node::receiveProduct(std::shared_ptr<Product> product){
    std::cout << "Node " << name << " received product " << product_count << " at time " << simulator->getNow() << std::endl;
    product_count++;
    
    auto event = std::make_shared<ProductMovementEvent>(shared_from_this(), product);
    simulator->scheduleEventAfterDelay(event, processing_time);
}

void Node::connectTo(std::shared_ptr<Node> targetNode){
    auto connector = std::make_shared<Connector>(shared_from_this(), targetNode);
    outputConnectors.push_back(connector);
    targetNode->inputConnectors.push_back(connector);
}

const std::vector<std::shared_ptr<Connector>> Node::getOutputConnectors(){
    return outputConnectors;
}
