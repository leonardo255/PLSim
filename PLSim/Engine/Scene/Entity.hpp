//
//  Entity.hpp
//  PLSim
//
//  Created by Lennart on 29/02/2024.
//

#ifndef Entity_hpp
#define Entity_hpp

#include "Scene.hpp"


class Entity{
  
public:
    Entity() = default;
    Entity(entt::entity handle, Scene* scene);
    Entity(const Entity& other) = default;
    
    
    template<typename T, typename... Args>
    T& AddComponent(Args&&... args)
    {
        T& component = m_Scene->m_Registry.emplace<T>(m_EntityID, std::forward<Args>(args)...);
        m_Scene->OnComponentAdded<T>(*this, component);
        return component;
    }
    
    
    template<typename T>
    bool HasComponent()
    {
        return m_Scene->m_Registry.all_of<T>(m_EntityID);
    }
    
    
    template<typename T>
    void RemoveComponent()
    {
        //HZ_CORE_ASSERT(HasComponent<T>(), "Entity does not have component!");
        m_Scene->m_Registry.remove<T>(m_EntityID);
    }
    
    operator entt::entity() const { return m_EntityID; }
    operator uint32_t() const { return (uint32_t)m_EntityID; }
    
private:
    entt::entity m_EntityID { entt::null };
    Scene* m_Scene = nullptr;
};


#endif /* Entity_hpp */
