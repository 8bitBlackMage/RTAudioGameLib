//
// Created by alice on 10/02/2020.
//
#include "Layers.h"
#include "../Globals.h"

SimpleImageLayer::SimpleImageLayer() {
    LayerData = LoadRenderTexture(GlobalVARS::RENDERW,GlobalVARS::RENDERH);
}


void SimpleImageLayer::updateLayer(void *data) {
    for(auto & Texture : LayerImages)
    {
        Texture->SrcRect.height = Texture->Image.height;
        Texture->SrcRect.width = Texture->Image.width;
    }
}


RenderTexture2D SimpleImageLayer::getLayer()
{

    BeginTextureMode(LayerData);
    ClearBackground(BLANK);
    for(auto & Texture : LayerImages)
    {
        DrawTexturePro(Texture->Image, Texture->SrcRect, Texture->DestRect, Texture->Origin, Texture->Rotation,WHITE);
    }
    EndTextureMode();
    return LayerData;
}

UserInterfaceLayer::UserInterfaceLayer() {
    LayerData = LoadRenderTexture(GlobalVARS::RENDERW,GlobalVARS::RENDERH);
}

RenderTexture2D UserInterfaceLayer::getLayer() {
    BeginTextureMode(LayerData);
    ClearBackground(BLANK);
    for(auto & uiElement: UIElements)
    {
        DrawRectangleRec(uiElement->Background, uiElement->BackgroundColour);
        DrawRectangleRoundedLines(uiElement->Background, 0.1f,1 ,uiElement->HighlightThickness, uiElement->HighlightColor);
        DrawText(uiElement->TextToDraw, (uiElement->Background.x + uiElement->HighlightThickness)
                ,(uiElement->Background.y + uiElement->HighlightThickness)
                ,20,WHITE);
    }
    EndTextureMode();
    return LayerData;
}

void UserInterfaceLayer::updateLayer(void *data) {

}
