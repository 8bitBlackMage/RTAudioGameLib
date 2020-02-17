#pragma once
#include <raylib.h>
#include <map>
#include <vector>
#include <string.h>
#include "Drawable.h"

class TextureManager
{
public:


//instance creation
static TextureManager& getManager(std::string path);

//removal of copy constructor
TextureManager(TextureManager const&) = delete;
void operator = (TextureManager const&) = delete;
Drawable createDrawable(std::string filename);


//runs commands to load into VRam, takes string for file name to load, has checks in place to prevent double loading
void loadFromFile(std::string filename); 


//generates unique hash for a texture, takes filename to generate hash to be attached to Texture in Vector
uint generateID(std::string filename);


//access to texture memory via a map, but also with vector based indexing
std::map<uint,Texture2D>m_Textures;
std::map<std::string,uint>m_lookup;

private:
//init
TextureManager(std::string path);
//standard Desconstructor 
~TextureManager();

};



