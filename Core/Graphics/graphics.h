//
// Created by alice on 09/02/2020.
//

#ifndef IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_GRAPHICS_H
#define IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_GRAPHICS_H

#include <raylib.h>


///the graphicsSubSystem class operates as a container for all core graphics related functions and variables
class graphicsSubSystem
{
public:
graphicsSubSystem(int ScreenW, int ScreenH);


void RenderLoop(); 

private:
    RenderTexture2D TextureTarget;

};


#endif //IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_GRAPHICS_H
