add_library(player STATIC
    "include/player/player.h"
    "src/player.cpp"
    "src/arm.h"
    "src/arm.cpp"
    "src/head.h"
    "src/head.cpp"
    "src/leg.h"
    "src/leg.cpp"
    "src/torso.h"
    "src/torso.cpp"
)

target_include_directories(player PUBLIC "include" ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} PRIVATE "include/player" "src")
target_link_libraries(player PUBLIC ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} rect error)
