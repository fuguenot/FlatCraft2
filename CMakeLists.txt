cmake_minimum_required(VERSION 3.27)

project(flatcraft2 VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package(SDL2 REQUIRED CONFIG PATHS "Frameworks" NO_DEFAULT_PATH)
find_package(SDL2_image REQUIRED CONFIG PATHS "Frameworks" NO_DEFAULT_PATH)

add_subdirectory("libs/pair_hash")
add_subdirectory("libs/rect")
add_subdirectory("libs/error")
add_subdirectory("libs/fcblock")
add_subdirectory("libs/player")

file(COPY "Resources" DESTINATION "flatcraft2.app/Contents")
file(COPY "Frameworks" DESTINATION "flatcraft2.app/Contents")

set(APP_NAME "FlatCraft2")

set(APPLE_GUI_BUNDLE_NAME ${APP_NAME})
# set_source_files_properties("Resources/flatcraft2.icns" PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
# set(APPLE_GUI_ICON flatcraft2)

add_executable(flatcraft2 MACOSX_BUNDLE
    "src/main.cpp"
    "src/state.h"
    "src/state.cpp"
    "src/event.cpp"
    "src/update.cpp"
    "src/render.cpp")

set_target_properties(flatcraft2 PROPERTIES
    BUNDLE ON
    MACOSX_BUNDLE_GUI_IDENTIFIER "com.fuguenot.flatcraft2"
    MACOSX_BUNDLE_BUNDLE_NAME ${APP_NAME}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION}
    MACOSX_BUNDLE_INFO_PLIST "${CMAKE_SOURCE_DIR}/cmake/AppleInfo.plist"
    BUILD_RPATH "${CMAKE_SOURCE_DIR}/build/flatcraft2.app/Contents/Frameworks"
    INSTALL_RPATH "flatcraft2.app/Contents/Frameworks"
)

install(DIRECTORY "${CMAKE_SOURCE_DIR}/Frameworks/SDL2.framework" DESTINATION "flatcraft2.app/Contents/Frameworks")
install(DIRECTORY "${CMAKE_SOURCE_DIR}/Frameworks/SDL2_image.framework" DESTINATION "flatcraft2.app/Contents/Frameworks")

install(TARGETS flatcraft2 DESTINATION "${CMAKE_SOURCE_DIR}/build")

target_link_libraries(flatcraft2 PRIVATE player pair_hash)
