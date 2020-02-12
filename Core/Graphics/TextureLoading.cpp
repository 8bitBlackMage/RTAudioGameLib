#include "TextureLoading.h"


//texture management singleton implimentation! 
TextureManager::TextureManager(std::string path)
{

}






Drawable TextureManager::createDrawable(std::string filename)
{


        loadFromFile(filename);
        Drawable ret(m_Textures.at(m_lookup.at(filename)));
        return ret;

}





void TextureManager::loadFromFile(std::string Path)
{

    //format the string for key generation / texture loading
    std::string Fullpath = "./assets/Images/" + Path;
    size_t lastdot = Path.find_last_of(".");

    std::string ShortPath = Path.substr(0,lastdot);

    //generate integer key from the string
    uint Key = generateID(ShortPath);
    
    //check if the texture manager has already got that texture in memory
    if(m_Textures.count(Key) == 0){
    
        //if it is not present load it into VRAM 
        Texture2D Vram = LoadTexture(Fullpath.c_str());
        // add it to texture lookup to be used later
        m_Textures.emplace(Key,Vram);
        m_lookup.emplace(Path,Key);

        printf("%lu", m_Textures.size() );
        printf("\n");
    }


}





unsigned int TextureManager::generateID(std::string Path)
{
        size_t i = 0;
        uint32_t hash = 0;
        size_t length = Path.length();

        while (i != length) {
            hash += Path[i++];
            hash += hash << 10;
            hash ^= hash >> 6;
        }
        hash += hash << 3;
        hash ^= hash >> 11;
        hash += hash << 15;
        return hash;

}


//remove all textures from Vram and clear out the arrays
TextureManager::~TextureManager()
{

    m_Textures.empty();

}


//static instance producer 
TextureManager & TextureManager::getManager(std::string path)
{
    static TextureManager instance(path);

    return instance;

}