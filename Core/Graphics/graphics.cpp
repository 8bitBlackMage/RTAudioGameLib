//
// Created by alice on 09/02/2020.
//

#include "graphics.h"


graphicsSubSystem::graphicsSubSystem(int ScreenW, int ScreenH): m_ScreenW(ScreenW), m_ScreenH(ScreenH)
{

    //creating window and setting fps cap

    InitWindow(m_ScreenW,m_ScreenH,"test");

    SetTargetFPS(60);




}

int graphicsSubSystem::getNumLayers() {

    return Layers.size();

}

void graphicsSubSystem::addLayertoRender(Layer* layer_to_add) {
    Layers.emplace_back(layer_to_add);
}


void graphicsSubSystem::RenderLoop() {

    BeginDrawing();
    ClearBackground(PINK);
    for(auto & RenderLayer : Layers)
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
    LayerData = LoadRenderTexture(320 ,240);
}



RenderTexture2D DebugLayer::getLayer()
{

BeginTextureMode(LayerData);
ClearBackground(BLANK);
DrawFPS(1,1);
DrawText(DebugLayernum.c_str(),1,20,10,GREEN);

EndTextureMode();

return LayerData;
}


void DebugLayer::updateLayer(void *data)
{
   SubsystemPointer = (graphicsSubSystem*) data;
   DebugLayernum = "number of Layers: "+ std::to_string(SubsystemPointer->getNumLayers()) ;



}