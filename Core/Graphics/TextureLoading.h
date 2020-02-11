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

void loadFromFile(std::string filename); 
void setAutoLoad(bool flag);
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



