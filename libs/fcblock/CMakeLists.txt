add_library(fcblock STATIC
    "include/fcblock/fcblock.h"
    "src/fcblock.cpp"
)

target_include_directories(fcblock PUBLIC "include" PRIVATE "include/fcblock")
target_link_libraries(fcblock PUBLIC SDL2::SDL2 SDL2_image::SDL2_image rect error)
