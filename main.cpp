
#include <raylib.h>
#include <complex>
#include "AudioWrapper.h"


AudioWrapper& SoundDevice = AudioWrapper::getWrapper();

int main()
{
    const int height = 1024;
    const int width = 768;
    double currentAngle =0;
    double cyclesPerSample = 0.00916666666;
    double angleDelta = cyclesPerSample * 2.0 *3.14159265358979323846264338327950288419716939937510;
    //creating window and setting fps cap

    InitWindow(height,width,"test");
  //  SetTargetFPS();
    std::array<std::array<double,256>*, 2 > WritePointers = SoundDevice.getWritePointers();
    while(!WindowShouldClose())
    {

        for(int i = 0; i < 256; i++)
        {
            double Val = 0;
            Val = std::sin(currentAngle) * 0.5;
            WritePointers.at(0)->at(i) = Val;
            WritePointers.at(1)->at(i) = Val;
            currentAngle += angleDelta;


        }



        //main drawing loop
       BeginDrawing();


        EndDrawing();
    }




    CloseWindow();
}
