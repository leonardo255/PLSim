//
//  TagComponent.h
//  PLSim
//
//  Created by Lennart on 29/02/2024.
//

#ifndef TagComponent_h
#define TagComponent_h

#include <string>

struct TagComponent
{
    std::string Tag;

    TagComponent() = default;
    TagComponent(const TagComponent&) = default;
    TagComponent(const std::string& tag) : Tag(tag) {}
};

#endif /* TagComponent_h */
