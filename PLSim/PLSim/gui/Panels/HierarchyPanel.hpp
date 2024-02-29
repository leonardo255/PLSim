//
//  HierarchyPanel.hpp
//  PLSim
//
//  Created by Lennart on 22/02/2024.
//

#ifndef HierarchyPanel_hpp
#define HierarchyPanel_hpp

class HierarchyPanel
{
public:
    HierarchyPanel();
    
    void OnImGuiRender(int w, int h);
    
private:
    void DrawScene();
    void DrawNodeEntity();
    void DrawProduct();
};


#endif /* HierarchyPanel_hpp */
