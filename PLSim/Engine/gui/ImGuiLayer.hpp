//
//  ImGuiLayer.hpp
//  PLSim
//
//  Created by Lennart on 16/02/2024.
//

#ifndef ImGuiLayer_hpp
#define ImGuiLayer_hpp

#include "Layer.hpp"

namespace gui {

    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer() = default;

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        //virtual void OnEvent(Event& e) override;

        void Begin();
        void End();

        //void BlockEvents(bool block) { m_BlockEvents = block; }
        
        void SetDarkThemeColors();

        //uint32_t GetActiveWidgetID() const;
    private:
        //bool m_BlockEvents = true;
    };

}

#endif /* ImGuiLayer_hpp */
