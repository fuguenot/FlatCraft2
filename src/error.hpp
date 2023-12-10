#pragma once

#include <string>

namespace fc2 {
    enum class ErrorType {
        SDL_INIT_ERROR,
        IMG_INIT_ERROR,
        SDL_WINDOW_ERROR,
        SDL_RENDERER_ERROR,
        IMG_LOAD_ERROR,
        SDL_RENDERCOPY_ERROR,
    };

    class Error {
        ErrorType type;
        std::string details;

    public:
        Error(ErrorType type, const std::string &details) noexcept;
        std::string to_string() noexcept;
    };
}  // namespace fc2
