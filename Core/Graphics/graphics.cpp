//
// Created by alice on 09/02/2020.
//

#include "graphics.h"
#include "../Globals.h"

graphicsSubSystem::graphicsSubSystem(int ScreenW, int ScreenH): m_ScreenW(ScreenW), m_ScreenH(ScreenH)
{

    //creating window and setting fps cap

    InitWindow(m_ScreenW,m_ScreenH,"test");

    SetTargetFPS(60);




}

int graphicsSubSystem::getNumLayers() {

    return m_Layers.size();

}

void graphicsSubSystem::addLayertoRender(Layer* layer_to_add) {
    m_Layers.emplace_back(layer_to_add);
}


void graphicsSubSystem::RenderLoop() {

    BeginDrawing();
    ClearBackground(PINK);
    for(auto & RenderLayer : m_Layers)
    {
    RenderTexture2D  Texture = RenderLayer->getLayer();
    DrawTexturePro(Texture.texture,
            (Rectangle){0.0f,0.0f,(float)Texture.texture.width, -(float)Texture.texture.height},
            (Rectangle) {0.0f,0.0f, (float) m_ScreenW, (float) m_ScreenH},
            (Vector2){0,0}, 0.0f,WHITE);
    }
    EndTextureMode();

    EndDrawing();

}
DebugLayer::DebugLayer()
{
    m_LayerData = LoadRenderTexture(GlobalVARS::RENDERW , GlobalVARS::RENDERH);
}



RenderTexture2D DebugLayer::getLayer()
{

BeginTextureMode(m_LayerData);
ClearBackground(BLANK);
DrawFPS(1,1);
DrawText(m_DebugLayernum.c_str(), 1, 20, 10, GREEN);

EndTextureMode();

return m_LayerData;
}


void DebugLayer::updateLayer(void *data)
{
    m_SubsystemPointer = (graphicsSubSystem*) data;
    m_DebugLayernum = "number of Layers: " + std::to_string(m_SubsystemPointer->getNumLayers()) ;



}