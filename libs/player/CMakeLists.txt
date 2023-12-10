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

target_include_directories(player PUBLIC "include" PRIVATE "include/player" "src")
target_link_libraries(player PUBLIC fcblock rect error)
