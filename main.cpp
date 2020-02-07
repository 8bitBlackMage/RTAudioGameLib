
#include <raylib.h>
#include "AudioWrapper.h"


AudioWrapper& SoundDevice = AudioWrapper::getWrapper();

int main()
{
    const int height = 1024;
    const int width = 768;

    //creating window and setting fps cap

    InitWindow(height,width,"test");
    SetTargetFPS(60);

    while(!WindowShouldClose())
    {

        //main drawing loop
        BeginDrawing();




        EndDrawing();
    }




    CloseWindow();
}
