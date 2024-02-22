//
//  connector.hpp
//  PLSim
//
//  Created by Lennart on 13/02/2024.
//

#ifndef connector_hpp
#define connector_hpp

#include "product.hpp"

class Node;

class Connector{
public:
    Connector(std::shared_ptr<Node> sourceNode, std::shared_ptr<Node>targetNode) : source_node{sourceNode}, target_node(targetNode) {}
    void sendProduct(std::shared_ptr<Product> product);
private:
    std::shared_ptr<Node> source_node;
    std::shared_ptr<Node> target_node;
};


#endif /* connector_hpp */
