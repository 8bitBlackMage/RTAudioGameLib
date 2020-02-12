
#include "Core/Graphics/graphics.h"
#include "Core/Graphics/TextureLoading.h"
#include "System/Input.h"
#include "System/settings.h"

settings m_Useroptions;




const int ScreenH = 768 *2;
const int ScreenW = 1024 *2;
graphicsSubSystem m_graphics(m_Useroptions.G_WinWidth, m_Useroptions.G_WinHeight);
TextureManager &m_textures = TextureManager::getManager("assets/Images");
Input &Inputmanager = Input::getManager();
int main()
{
    DebugLayer settings;
    SimpleImageLayer DrawingLayer;
    UserInterfaceLayer TOPLayer;
    Drawable Purin = m_textures.createDrawable("Purin.png");
    UIDrawable test(20,300,600,50,"User Interface object Test");
    Purin.DestRect = {50,50,200,200};
    DrawingLayer.LayerImages.push_back(&Purin);
    TOPLayer.UIElements.push_back(&test);

    m_graphics.addLayertoRender(&DrawingLayer);
    m_graphics.addLayertoRender(&TOPLayer);
    m_graphics.addLayertoRender(&settings);


    //AudioCallback.join();
    while(!WindowShouldClose())
    {
        Inputmanager.pollInput();
        settings.updateLayer((void*) &m_graphics);
        DrawingLayer.updateLayer(NULL);
        m_graphics.RenderLoop();

        Purin.DestRect.x+=1;

    }




    CloseWindow();
}

