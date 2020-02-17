//
// Created by alice on 11/02/2020.
//

#include "Input.h"
#include "System/Events/Event.h"
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
    m_totalButtons = magic_enum::enum_count<GamepadButton>();
    m_totalKeys = magic_enum::enum_count<KeyboardKey>();

    m_Buttons.resize(m_totalButtons, false);
    m_Keys.resize(m_totalKeys, false);
}

void Input::HandleGamePadInput() {

    if (IsGamepadAvailable(GAMEPAD_PLAYER1)) {

    for(int i = 0; i < m_totalButtons; i ++ ) {
        if (IsGamepadButtonPressed(GAMEPAD_PLAYER1, i))
            m_Buttons.at(i) = true;


        if (IsGamepadButtonReleased(GAMEPAD_PLAYER1, i));
        m_Buttons.at(i) = false;
    }

    }
}
void Input::HandleKeyboardInput()
{
for(int i = 0 ; i < m_totalKeys; i++)
{
    if (IsKeyPressed(i))
        m_Keys.at(i) = true;


    if (IsKeyReleased( i))
        m_Keys.at(i) = false;

}




}
