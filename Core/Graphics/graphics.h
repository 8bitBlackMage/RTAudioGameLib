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

    //default constructor, takes screen width and height commands inits the window and renderer, sets up all graphics related perameters
graphicsSubSystem(int ScreenW, int ScreenH);


    //rendering loop function, runs through vector of layers and applies the rendertextures to the output buffer
void RenderLoop();

    //function returns number of layers for debug uses
int getNumLayers();

    //setter function that adds a pointer to the layerbuffer,
void addLayertoRender(Layer* layer_to_add);
private:

    std::vector<Layer*> m_Layers;

    int m_ScreenH;
    int m_ScreenW ;




};



class DebugLayer: public Layer{
public:
    DebugLayer();
    RenderTexture2D getLayer() override;
    void updateLayer(void * data) override;

private:
    graphicsSubSystem* m_SubsystemPointer;
    std::string m_DebugLayernum;
    RenderTexture2D m_LayerData;
};





#endif //IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_GRAPHICS_H
