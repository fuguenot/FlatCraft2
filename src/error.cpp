#include "error.hpp"

#include <sstream>

fc2::Error::Error(fc2::ErrorType type, const std::string &details) noexcept
    : type(type),
      details(details) {
}

std::string fc2::Error::to_string() noexcept {
    std::ostringstream oss;
    switch (type) {
    case ErrorType::SDL_INIT_ERROR: oss << "SDL Init Error: " << details; break;
    case ErrorType::IMG_INIT_ERROR:
        oss << "SDL_image Init Error: " << details;
        break;
    case ErrorType::SDL_WINDOW_ERROR:
        oss << "SDL_Window Init Error: " << details;
        break;
    case ErrorType::SDL_RENDERER_ERROR:
        oss << "SDL_Renderer Init Error: " << details;
        break;
    default: break;
    }

    return oss.str();
}
