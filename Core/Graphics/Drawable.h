//
// Created by alice on 10/02/2020.
//

#ifndef IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_DRAWABLE_H
#define IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_DRAWABLE_H
#include <raylib.h>

//the drawable struct contains data around a texture such as its position on a layer, if its part of a spritesheet, rotation and clear color data
//everything thats needed for calling in a "DrawTexturePro()" function


struct Drawable
{
    Drawable(Texture2D & m_image): Image(m_image){

    }
    Texture2D & Image;
    Rectangle SrcRect{0,0,0,0};
    Rectangle DestRect{0,0,0,0};
    float Rotation =0.0f;
    Vector2 Origin{0,0};

    //unique id is generated from the file name, allows texture manager to check if a file is already in memory without slow string comparisons
    unsigned int UniqueID;

};


struct UIDrawable
{
    UIDrawable();
    UIDrawable(float x, float y, float width, float height, const char * text){
        Background = {x,y,width,height};
        TextToDraw = text;
    }
    Rectangle Background{0,0,0,0};
    Color BackgroundColour = {0, 73, 255,255};
    float HighlightThickness = 5;
    Color HighlightColor = {219, 219, 255,255};
    const char * TextToDraw;
};
#endif //IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_DRAWABLE_H
