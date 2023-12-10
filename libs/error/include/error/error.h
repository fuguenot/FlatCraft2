#pragma once

#include <string>

namespace error {
    enum class ErrorType : std::uint8_t {
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
}  // namespace error
