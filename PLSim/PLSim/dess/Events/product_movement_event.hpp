//
//  product_movement_event.hpp
//  PLSim
//
//  Created by Lennart on 13/02/2024.
//

#ifndef product_movement_event_hpp
#define product_movement_event_hpp

#include "event.hpp"
#include "node.hpp"
#include "product.hpp"

class ProductMovementEvent : public Event{
public:
    ProductMovementEvent(std::shared_ptr<Node> source, std::shared_ptr<Product> product) : source(source), product(product) {}
    void processEvent() override;
private:
    std::shared_ptr<Node> source;
    std::shared_ptr<Product> product;
};

#endif /* product_movement_event_hpp */
