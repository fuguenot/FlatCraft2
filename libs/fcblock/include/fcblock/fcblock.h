#pragma once

#include <SDL.h>

namespace block {
    class Block {
    public:
        static const std::uint8_t SCALE = 8;

        enum class Type : std::uint8_t { STONE, DIRT, GRASS, LOG, PLANK };

        Block(Type type) noexcept;

        void render(SDL_Texture *spritesheet,
                    SDL_Renderer *rend,
                    std::int16_t x,
                    std::int16_t y) const;

    private:
        Type type;
        SDL_Rect spritesheet_rect;

        SDL_Rect get_spritesheet_rect() const noexcept;
    };
}  // namespace block
