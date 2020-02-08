//
// Created by alice on 04/02/2020.
//

#ifndef IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_AUDIOWRAPPER_H
#define IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_AUDIOWRAPPER_H
#include <RtAudio.h>
#include "HeaderOnlyLibs/AudioFile.h"



struct Song{

AudioFile<double>AudioFileData;
int BPM;
unsigned int ID;
};

struct SoundEffect{
AudioFile<double>AudioFileData;
unsigned int ID;
};





class AudioWrapper {
public:
    static AudioWrapper& getWrapper();
  static AudioWrapper& getWrapper(unsigned int buffersize,int samplerate,int nbuffers, int device);
  AudioWrapper (AudioWrapper const&) = delete;
  unsigned int generateID(std::string name);
  void operator = (AudioWrapper const&)  =delete;

    std::array<std::array<double,256>*, 2 >& getWritePointers();


private:


    AudioWrapper(unsigned int buffersize,int samplerate,int nbuffers, int device);
    ~AudioWrapper();
    RtAudio *soundDevice =0;
    int BufferSize;
    int SampleRate;
    int nBuffers;
    int Device;
    std::array<double,256>LeftChannel;
    std::array<double,256>RightChannel;
    std::array<std::array<double,256>*, 2 >Channels;
    unsigned int BufferFrames = 256;
    std::vector<Song>Songs;
    std::vector<SoundEffect>Sfx;
};


#endif //IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_AUDIOWRAPPER_H
