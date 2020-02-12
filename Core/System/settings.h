//
// Created by alice on 09/02/2020.
//

#ifndef IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_SETTINGS_H
#define IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_SETTINGS_H

//settings collection file,
#include <string>
#include "../../Libraries/tinyxml2/tinyxml2.h"
class settings{
public:

    settings()
    {
        if(LoadFile(SettingsPath) == false){
            CreateFile();
        }
    }

    int G_FPS;
    int G_WinHeight;
    int G_WinWidth;
    bool G_FullScreen;
    const char * ImgPath;
    const char * MapPath;
    const char * MusicPath;
    const char * SFXPath;
    std::string SettingsPath = "Defaultsettings.xml";

private:

    bool LoadFile(std::string filepath){

        tinyxml2::XMLDocument Doc;

        //load file from disk
        tinyxml2::XMLError loadokay = Doc.LoadFile(filepath.c_str());
        //check if load is successful, returns false so the file creation code can be run
        if(loadokay != tinyxml2::XML_SUCCESS){
            return false;
        }

        //obtains root element
        tinyxml2::XMLNode *pRoot = Doc.FirstChildElement();
        //checks if the root element is a valid xml element
        if(pRoot == nullptr)
        {
            return false;
        }
        tinyxml2::XMLElement * VideoSettings = pRoot->FirstChildElement("VideoSettings");
        if(VideoSettings == nullptr)
        {
            return false;
        }

        //get the interger values relating to the video settings
        VideoSettings->QueryIntAttribute("HRes",&G_WinHeight);
        VideoSettings->QueryIntAttribute("WRes",&G_WinWidth);
        VideoSettings->QueryIntAttribute("FPS",&G_FPS);
        VideoSettings->QueryBoolAttribute("Fullscreen", &G_FullScreen);


        //get the string values for file paths
        tinyxml2::XMLElement * Imgpath = VideoSettings->NextSiblingElement("ImagePath");
        if(Imgpath == NULL)
        {
            return false;
        }
        ImgPath = Imgpath->GetText();

        tinyxml2::XMLElement * Mappath = Imgpath->NextSiblingElement("MapPath");
        if(Mappath == NULL)
        {
            return false;
        }
        MapPath = Mappath->GetText();

        tinyxml2::XMLElement * Musicpath = Mappath->NextSiblingElement("MusicPath");
        if(Musicpath == NULL)
        {
            return false;
        }
        MusicPath = Musicpath->GetText();

        tinyxml2::XMLElement * SFXpath = Musicpath->NextSiblingElement("SoundFXPath");
        if(SFXpath == NULL)
        {
            return false;
        }
        SFXPath = SFXpath->GetText();


        return true;
    }
    void CreateFile(){
        //create a new empty document
        tinyxml2::XMLDocument Doc;

        //generate the root element
        tinyxml2::XMLElement * Proot = Doc.NewElement("root");

        //insert as child of the document
        Doc.InsertFirstChild(Proot);



        // generate video attributes
        tinyxml2::XMLElement *VideoS  = Doc.NewElement("VideoSettings");
        VideoS->SetAttribute("WRes",640);
        VideoS->SetAttribute("HRes",480);
        VideoS->SetAttribute("FPSCap",60);
        VideoS->SetAttribute("Fullscreen",false);
        //insert as child of root
        Proot->InsertEndChild(VideoS);

        tinyxml2::XMLElement *IMGpath = Doc.NewElement("ImagePath");
        IMGpath->SetText("./assets/Images/");

        Proot->InsertEndChild( IMGpath);

        tinyxml2::XMLElement *Mappath = Doc.NewElement("MapPath");
        Mappath->SetText("./assets/Maps/");

        Proot->InsertEndChild(Mappath);

        tinyxml2::XMLElement *Musicpath = Doc.NewElement("MusicPath");
        Musicpath->SetText("./assets/Music/");

        Proot->InsertEndChild(Musicpath);

        tinyxml2::XMLElement *SFXpath = Doc.NewElement("SoundFXPath");
        SFXpath->SetText("./assets/sfx");

        Proot->InsertEndChild(SFXpath);


        //write output to file
        tinyxml2::XMLError output =  Doc.SaveFile("Defaultsettings.xml");
    }
};
#endif //IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_SETTINGS_H
