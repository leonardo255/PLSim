//
//  connector.cpp
//  PLSim
//
//  Created by Lennart on 13/02/2024.
//

#include "connector.hpp"
#include "node.hpp"

void Connector::sendProduct(std::shared_ptr<Product> product){
    target_node->receiveProduct(product);
}
