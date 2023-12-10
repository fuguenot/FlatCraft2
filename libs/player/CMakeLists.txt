add_library(player STATIC
    "include/player/player.h"
    "include/player/renderer.h"
    "include/player/direction.h"
    "src/player.cpp"
    "src/renderer.cpp"
    "src/arm.cpp"
    "src/head.cpp"
    "src/leg.cpp"
    "src/torso.cpp"
)

target_include_directories(player PUBLIC "include" ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} PRIVATE "include/player" "src")
target_link_libraries(player PUBLIC ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} rect error)
