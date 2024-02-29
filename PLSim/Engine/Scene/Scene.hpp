//
//  Scene.hpp
//  PLSim
//
//  Created by Lennart on 20/02/2024.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <string>
#include <entt/entity/registry.hpp>

class Entity;


class Scene
{
    friend class Entity;
    friend class HierarchyPanel;
    
public:
    Scene();
    ~Scene();
    
    Entity CreateEntity(const std::string& name = std::string());
    
    void OnSimulationStart();
    void OnSimulationStop();
    
    
    template<typename... Components>
    auto GetAllEntitiesWith()
    {
        return m_Registry.view<Components...>();
    }
    
private:
    entt::registry m_Registry;
    
    template<typename T>
    void OnComponentAdded(Entity entity, T& component);
    
};

#endif /* Scene_hpp */
