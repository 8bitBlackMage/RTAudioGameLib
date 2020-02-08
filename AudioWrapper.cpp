//
// Created by alice on 04/02/2020.
//

#include "AudioWrapper.h"
#include <iostream>
#include <cstdlib>
#include <random>
int AudioCallback(void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames, double streamTime,
                                RtAudioStreamStatus status, void *userData){
    unsigned int i, j;
    double *buffer = (double *) outputBuffer;
   //double *lastValues = (double *) userData;
  std::array<std::array<double,256>*,2> *WritePointer = (std::array<std::array<double,256>*,2> *) userData;

    if ( status )
        std::cout << "Stream underflow detected!" << std::endl;
    // Write interleaved audio data.
    for ( i=0; i<nBufferFrames; i++ ) {
        for ( j=0; j<2; j++ ) {
        *buffer++ = WritePointer->at(j)->at(i);



        }
    }
    return 0;
}

AudioWrapper::AudioWrapper(unsigned int buffersize, int samplerate, int nbuffers, int device)
{
    std::cout << "init of RT audio" << std::endl;


    Channels.at(0) = &LeftChannel;
    Channels.at(1) = &RightChannel;
   soundDevice = new RtAudio(RtAudio::LINUX_PULSE);
    if(soundDevice != 0) {


        RtAudio::StreamParameters Parameters;
        Parameters.deviceId = soundDevice->getDefaultOutputDevice();
        Parameters.nChannels = 2;
        Parameters.firstChannel = 0;

        RtAudio::StreamOptions Options;
        Options.numberOfBuffers = nbuffers;


        soundDevice->openStream(&Parameters, NULL, RTAUDIO_FLOAT64, samplerate, &buffersize, &AudioCallback,
                                (void *) &Channels, &Options);
        if (soundDevice->isStreamOpen() == true) {
            std::cout << "init successful, stream open" << std::endl;
            std::cout << "audio backend in use: " << soundDevice->getApiDisplayName(soundDevice->getCurrentApi())
                      << std::endl;
            std::cout << "sample rate: " << soundDevice->getStreamSampleRate() << "  RT audio version "
                      << soundDevice->getVersion() << std::endl;
            soundDevice->startStream();
        }
    }
}

AudioWrapper& AudioWrapper::getWrapper()
{
    static AudioWrapper instance(256,48000,1,1);


    return instance;
}

AudioWrapper& AudioWrapper::getWrapper(unsigned int buffersize, int samplerate, int nbuffers, int device)
{
    static AudioWrapper instance(buffersize,samplerate,nbuffers,device);


    return instance;


}

unsigned int AudioWrapper::generateID(std::string name)
{



}
AudioWrapper::~AudioWrapper()
{
soundDevice->closeStream();
}

std::array<std::array<double, 256> *, 2> &AudioWrapper::getWritePointers()
{
    return Channels;
}

