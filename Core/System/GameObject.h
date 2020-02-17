//
// Created by alice on 17/02/2020.
//

#ifndef IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_GAMEOBJECT_H
#define IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_GAMEOBJECT_H

#include <memory>
#include "Graphics/Drawable.h"



//#TODO impliment rest of gameobject systems



class GameObject
{
    //holding type for Event management system
    int ObjectID;
};

class SpriteObject : public GameObject
{
    std::unique_ptr<Drawable>m_DrawableObject;
};

#endif //IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_GAMEOBJECT_H
