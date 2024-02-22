//
//  Layer.hpp
//  PLSim
//
//  Created by Lennart on 16/02/2024.
//

#ifndef Layer_hpp
#define Layer_hpp

#include <string>


namespace gui {

    class Layer
    {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer() = default;

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnImGuiRender() {}
        //virtual void OnEvent(Event& event) {}

        const std::string& GetName() const { return m_DebugName; }
        
    protected:
        std::string m_DebugName;
    };

}

#endif /* Layer_hpp */
