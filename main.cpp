
#include "Core/Graphics/graphics.h"
#include "Core/Graphics/TextureLoading.h"
#include "Core/Input.h"
#include "Core/settings.h"


const int ScreenH = 768 *2;
const int ScreenW = 1024 *2;
graphicsSubSystem m_graphics(ScreenW,ScreenH);
TextureManager &m_textures = TextureManager::getManager("assets/Images");
int main()
{

    DebugLayer settings;
    SimpleImageLayer DrawingLayer;
    Drawable Purin = m_textures.createDrawable("Purin.png");

    Purin.DestRect = {50,50,100,100};
    DrawingLayer.LayerImages.push_back(Purin);

    m_graphics.addLayertoRender(&DrawingLayer);
    m_graphics.addLayertoRender(&settings);


    //AudioCallback.join();
    while(!WindowShouldClose())
    {
        settings.updateLayer((void*) &m_graphics);
        DrawingLayer.updateLayer(NULL);
        m_graphics.RenderLoop();



    }




    CloseWindow();
}

