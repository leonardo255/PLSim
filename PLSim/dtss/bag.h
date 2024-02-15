//
//  bag.h
//  PLSim
//
//  Created by Lennart on 11/02/2024.
//

#ifndef bag_h
#define bag_h

#include<list>


namespace dtss {


template <typename T>
class Bag
{
public:
    void insert(const T& item) { items.push_back(item); }
    void remove(const T& item) { items.remove(item); }
    void clear() { items.clear(); }
    size_t size() const { return items.size(); }
    
    typename std::list<T>::const_iterator begin() const { return items.begin(); }
    typename std::list<T>::const_iterator end() const { return items.end(); }
    
private:
    std::list<T> items;
};

}

#endif /* bag_h */
