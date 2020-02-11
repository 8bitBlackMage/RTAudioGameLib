//
// Created by alice on 09/02/2020.
//

#ifndef IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_LAYERS_H
#define IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_LAYERS_H

#include <raylib.h>
#include <vector>
#include "Drawable.h"



class Layer{
    ///layer class, stores a pointer to textures that are stitched together into render textures before being pushed to the main texture.
public:


    virtual RenderTexture2D getLayer() =0;

    virtual void updateLayer(void * data) = 0;
};


class SimpleImageLayer: public Layer
{
public:
    SimpleImageLayer();
    RenderTexture2D getLayer() override ;

    void updateLayer(void * data) override;
    RenderTexture2D LayerData;
    std::vector<Drawable> LayerImages;
};






#endif //IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_LAYERS_H
