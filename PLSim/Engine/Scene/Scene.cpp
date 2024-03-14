//
//  Scene.cpp
//  PLSim
//
//  Created by Lennart on 20/02/2024.
//

#include "Scene.hpp"
#include "Entity.hpp"
#include "UUID.hpp"
#include "Renderer2D.hpp"

#include "IDComponent.h"
#include "TagComponent.h"
#include "TransformComponent.h"


Entity Scene::CreateEntity(const std::string& name)
{
    return CreateEntityWithUUID(UUID(), name);
}

Entity Scene::CreateEntityWithUUID(UUID uuid, const std::string& name)
{
    Entity entity = { m_Registry.create(), this };
    entity.AddComponent<IDComponent>(uuid);
    entity.AddComponent<TransformComponent>();
    auto& tag = entity.AddComponent<TagComponent>();
    tag.Tag = name.empty() ? "Entity" : name;

    m_EntityMap[uuid] = entity;

    return entity;
}

void Scene::RenderScene()
{
    // Draw Nodes
    {
        auto group = m_Registry.group<TransformComponent>(entt::get<TagComponent>);
        for (auto entity : group)
        {
            auto [transform, tag] = group.get<TransformComponent, TagComponent>(entity);
            Renderer2D::DrawNode(transform.Position, tag.Tag);
        }
    }
}
