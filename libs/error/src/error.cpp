#include "error.h"

#include <sstream>

error::Error::Error(ErrorType type, const std::string &details) noexcept
    : type(type),
      details(details) {
}

std::string error::Error::to_string() noexcept {
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
    case ErrorType::IMG_LOAD_ERROR:
        oss << "IMG_LoadTexture Error: " << details;
        break;
    case ErrorType::SDL_RENDERCOPY_ERROR:
        oss << "SDL_RenderCopy Error: " << details;
        break;
    default: break;
    }

    return oss.str();
}
