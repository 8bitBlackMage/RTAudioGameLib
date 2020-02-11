//
// Created by alice on 11/02/2020.
//

#ifndef IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_INPUT_H
#define IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_INPUT_H

#include <raylib.h>
#include <array>
enum GameKeys{
    Up,Down,Left,Right,Cross,Triangle,Square,Circle,total
};



class Input {
//singleton class for getting input
public:
static Input & getManager();
void pollInput();


Input (Input const&) = delete;
void operator = (Input const&) = delete;
private:
    Input();
    std::array<bool,GameKeys::total>Keys;
    void HandleGamePadInput();
    void HandleKeyboardInput();



};


#endif //IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_INPUT_H
