cmake_minimum_required(VERSION 3.26)

project(flatcraft2 VERSION 0.1.0 LANGUAGES CXX)

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED SDL2)
pkg_search_module(SDL2_IMAGE REQUIRED SDL2_image)

add_subdirectory(libs/rect)
add_subdirectory(libs/error)
add_subdirectory(libs/player)

set(flatcraft2_SOURCES
    src/main.cpp
    src/state.cpp
    src/event.cpp
    src/update.cpp
    src/render.cpp
)

file(COPY resources DESTINATION .)

add_executable(flatcraft2 ${flatcraft2_SOURCES})
target_link_libraries(flatcraft2 PUBLIC ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} player)
