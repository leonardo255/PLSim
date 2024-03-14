//
//  TransformComponent.h
//  PLSim
//
//  Created by Lennart on 29/02/2024.
//

#ifndef TransformComponent_h
#define TransformComponent_h

#include "imgui.h"

struct TransformComponent
{
    ImVec2 Position = { 0.0f, 0.0f };

    TransformComponent() = default;
    TransformComponent(const TransformComponent&) = default;
};

#endif /* TransformComponent_h */
