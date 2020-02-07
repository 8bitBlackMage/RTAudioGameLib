cmake_minimum_required(VERSION 3.15)
project(ImplimentingGameAudioProject_Raylib)

set(CMAKE_CXX_STANDARD 17)

add_executable(ImplimentingGameAudioProject_Raylib main.cpp AudioWrapper.cpp AudioWrapper.h)

target_link_libraries(ImplimentingGameAudioProject_Raylib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -lrtaudio)