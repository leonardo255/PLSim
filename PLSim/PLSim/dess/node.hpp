//
//  node.hpp
//  PLSim
//
//  Created by Lennart on 13/02/2024.
//

#ifndef node_hpp
#define node_hpp

#include <string>
#include "product.hpp"
#include "dess_simulator.hpp"
#include "connector.hpp"


class Node : public std::enable_shared_from_this<Node> {
public:
    Node(std::shared_ptr<DESS_Simulator> simulator, std::string name, int productCount, double processingTime) : simulator(simulator), name(name), product_count(productCount), processing_time(processingTime) {}
    
    void receiveProduct(std::shared_ptr<Product> product);
    void connectTo(std::shared_ptr<Node> targetNode);
    
    const std::vector<std::shared_ptr<Connector>> getOutputConnectors();
    
protected:
    std::string name;
    std::shared_ptr<DESS_Simulator> simulator;
    int product_count;
    double processing_time = 1.0;
    std::vector<std::shared_ptr<Connector>> inputConnectors;
    std::vector<std::shared_ptr<Connector>> outputConnectors;
};

#endif /* node_hpp */
