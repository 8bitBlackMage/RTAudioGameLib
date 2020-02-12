cmake_minimum_required(VERSION 3.15)
project(ImplimentingGameAudioProject_Raylib)


set(CMAKE_CXX_STANDARD 17)
include_directories("${PROJECT_SOURCE_DIR}/Core")
include_directories(${PROJECT_SOURCE_DIR}/Libraries)




add_executable(ImplimentingGameAudioProject_Raylib main.cpp
        Core/Graphics/graphics.cpp
        Core/Graphics/TextureLoading.cpp
        Core/Graphics/Layers.cpp
        Core/System/Input.cpp
        Libraries/tinyxml2/tinyxml2.cpp)

target_link_libraries(ImplimentingGameAudioProject_Raylib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 )