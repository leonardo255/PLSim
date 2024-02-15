//
//  product.hpp
//  PLSim
//
//  Created by Lennart on 13/02/2024.
//

#ifndef product_hpp
#define product_hpp

#include <vector>
#include <string>


class Product
{
public:
    Product(const std::vector<std::string>& processes) : processes(processes) {}
    const std::vector<std::string> getProcesses();
private:
    std::vector<std::string> processes;
};

#endif /* product_hpp */
