//
// Created by alice on 11/02/2020.
//

#ifndef IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_INPUT_H
#define IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_INPUT_H

#include <raylib.h>
#include <vector>




class Input {
//singleton class for getting input
public:
static Input & getManager();
void pollInput();


Input (Input const&) = delete;
void operator = (Input const&) = delete;
private:
    Input();
    std::vector<bool>m_Keys;
    std::vector<bool>m_Buttons;
    void HandleGamePadInput();
    void HandleKeyboardInput();
    int m_totalButtons;
    int m_totalKeys;


};


#endif //IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_INPUT_H
