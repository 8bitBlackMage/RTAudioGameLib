//
// Created by alice on 11/02/2020.
//

#include "Input.h"
#include <assert.h>
#include "../../Libraries/magicEnum/include/magic_enum.hpp"
Input &Input::getManager() {
    static Input Instance;


    return Instance;
}

void Input::pollInput() {
HandleGamePadInput();
HandleKeyboardInput();




}

Input::Input() {
    totalButtons = magic_enum::enum_count<GamepadButton>();
    totalKeys = magic_enum::enum_count<KeyboardKey>();

    Buttons.resize(totalButtons, false);
    Buttons.resize(totalKeys,false);
}

void Input::HandleGamePadInput() {

    if (IsGamepadAvailable(GAMEPAD_PLAYER1)) {

    for(int i = 0; i < totalButtons; i ++ ) {
        if (IsGamepadButtonPressed(GAMEPAD_PLAYER1, i))
            Buttons.at(i) = true;


        if (IsGamepadButtonReleased(GAMEPAD_PLAYER1, i));
            Buttons.at(i) = false;
    }

    }
}
void Input::HandleKeyboardInput()
{
for(int i = 0 ; i < totalKeys; i++)
{
    if (IsKeyPressed(i))
        Keys.at(i) = true;


    if (IsKeyReleased( i))
        Keys.at(i) = false;

}




}
