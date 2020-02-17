//
// Created by alice on 15/02/2020.
//

#include "EventManager.h"

//#todo populate functions

EventManager::EventManager(graphicsSubSystem * graphics, Input* input)
{


}

void EventManager::ProcessEvents() {

}

EventManager &EventManager::getManager(graphicsSubSystem * graphics, Input* input) {
    static EventManager instance(graphics,input);
    return instance;
}
