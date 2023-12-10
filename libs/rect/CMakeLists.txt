add_library(rect STATIC "include/rect/rect.h" "src/rect.cpp")

target_include_directories(rect PUBLIC "include" PRIVATE "include/rect")
