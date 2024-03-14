//
//  IDComponent.h
//  PLSim
//
//  Created by Lennart on 05/03/2024.
//

#ifndef IDComponent_h
#define IDComponent_h

struct IDComponent
{
    UUID ID;

    IDComponent() = default;
    IDComponent(const IDComponent&) = default;
};

#endif /* IDComponent_h */
