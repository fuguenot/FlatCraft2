cmake_minimum_required(VERSION 3.26)

project(flatcraft2 VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include(FetchContent)

FetchContent_Declare(
    SDL2
    GIT_REPOSITORY "https://github.com/libsdl-org/SDL.git"
    GIT_TAG "release-2.28.5"
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(SDL2)

FetchContent_Declare(
    SDL2_image
    GIT_REPOSITORY "https://github.com/libsdl-org/SDL_image.git"
    GIT_TAG "release-2.6.3"
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)

set(SDL2IMAGE_INSTALL FALSE)

FetchContent_MakeAvailable(SDL2_image)

add_subdirectory(libs/pair_hash)
add_subdirectory(libs/rect)
add_subdirectory(libs/error)
add_subdirectory(libs/fcblock)
add_subdirectory(libs/player)

set(flatcraft2_SOURCES
    "src/main.cpp"
    "src/state.h"
    "src/state.cpp"
    "src/event.cpp"
    "src/update.cpp"
    "src/render.cpp"
)

file(COPY resources DESTINATION .)

add_executable(flatcraft2 ${flatcraft2_SOURCES})
target_link_libraries(flatcraft2 PUBLIC player pair_hash)
