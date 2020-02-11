//
// Created by alice on 09/02/2020.
//

#ifndef IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_GRAPHICS_H
#define IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_GRAPHICS_H

#include <raylib.h>
#include <vector>
#include "Layers.h"
#include <string>
///the graphicsSubSystem class operates as a container for all core graphics related functions and variables
class graphicsSubSystem
{
public:
graphicsSubSystem(int ScreenW, int ScreenH);


void RenderLoop();
int getNumLayers();
void addLayertoRender(Layer* layer_to_add);
private:

    std::vector<Layer*> Layers;

    int m_ScreenH;
    int m_ScreenW ;
    const int m_Renderheight = 240;
    const int m_Renderwidth = 320;



};



class DebugLayer: public Layer{
public:
    DebugLayer();
    RenderTexture2D getLayer() override;
    void updateLayer(void * data) override;

private:
    graphicsSubSystem* SubsystemPointer;
    std::string DebugLayernum;
    RenderTexture2D LayerData;
};





#endif //IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_GRAPHICS_H
