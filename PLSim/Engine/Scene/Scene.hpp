//
//  Scene.hpp
//  PLSim
//
//  Created by Lennart on 20/02/2024.
//

#ifndef Scene_hpp
#define Scene_hpp

#include "UUID.hpp"
#include <string>
#include <entt/entity/registry.hpp>
#include <unordered_map>

class Entity;


class Scene
{
    friend class Entity;
    friend class HierarchyPanel;
    
public:
    Scene();
    ~Scene();
    
    Entity CreateEntity(const std::string& name = std::string());
    Entity CreateEntityWithUUID(UUID uuid, const std::string& name = std::string());
    
    void OnSimulationStart();
    void OnSimulationStop();
    
    void RenderScene();
    
    template<typename... Components>
    auto GetAllEntitiesWith()
    {
        return m_Registry.view<Components...>();
    }
    
private:
    entt::registry m_Registry;
    std::unordered_map<UUID, entt::entity> m_EntityMap;
    
    template<typename T>
    void OnComponentAdded(Entity entity, T& component);
    
};

#endif /* Scene_hpp */
