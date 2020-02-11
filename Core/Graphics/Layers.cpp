//
// Created by alice on 10/02/2020.
//
#include "Layers.h"


SimpleImageLayer::SimpleImageLayer() {
    LayerData = LoadRenderTexture(320,240);
}


void SimpleImageLayer::updateLayer(void *data) {
    for(auto & Texture : LayerImages)
    {
        Texture.SrcRect.height = Texture.Image.height;
        Texture.SrcRect.width = Texture.Image.width;
    }
}


RenderTexture2D SimpleImageLayer::getLayer()
{

    BeginTextureMode(LayerData);
    ClearBackground(BLANK);
    for(auto & Texture : LayerImages)
    {
        DrawTexturePro(Texture.Image, Texture.SrcRect, Texture.DestRect, Texture.Origin, Texture.Rotation,WHITE);
    }
    EndTextureMode();
    return LayerData;
}