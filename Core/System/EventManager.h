//
// Created by alice on 15/02/2020.
//

#ifndef IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_EVENTMANAGER_H
#define IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_EVENTMANAGER_H

#include "System/Events/Event.h"
#include "Graphics/graphics.h"
#include "Input.h"
#include "GameObject.h"
#include <vector>


//#todo create messenger functions

class EventManager {
public:
    static EventManager & getManager(graphicsSubSystem * graphics, Input* input);
    EventManager(const EventManager&) = delete;
    void operator = (const  EventManager&) = delete;

    void ProcessEvents();


private:
    EventManager(graphicsSubSystem * graphics, Input* input);
    std::vector<Event> m_EventQueue;
    std::vector<GameObject>m_GameObjects;
    graphicsSubSystem* m_Graphicsptr;
    Input* Inputptr;
};


#endif //IMPLIMENTINGGAMEAUDIOPROJECT_RAYLIB_EVENTMANAGER_H
