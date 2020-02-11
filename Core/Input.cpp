//
// Created by alice on 11/02/2020.
//

#include "Input.h"

Input &Input::getManager() {
    Input Instance;


    return Instance;
}

void Input::pollInput() {






}

Input::Input() {

}

void Input::HandleGamePadInput() {
  if ( IsGamepadAvailable(GAMEPAD_PLAYER1))
    {
    
    }
  return;
}

void Input::HandleKeyboardInput() {

}
