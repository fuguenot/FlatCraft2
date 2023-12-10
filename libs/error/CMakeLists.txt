add_library(error STATIC "include/error/error.h" "src/error.cpp")

target_include_directories(error PUBLIC "include" PRIVATE "include/error")
