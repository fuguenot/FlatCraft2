#pragma once

#include <SDL.h>

#include "direction.h"

namespace player {
    class Renderer {
    public:
        Renderer(std::int16_t x, std::int16_t y) noexcept;
        ~Renderer() noexcept;

        void load_textures(SDL_Renderer *rend);

        void calculate_head_angle() noexcept;

        void render(SDL_Renderer *rend);

        Direction facing = Direction::RIGHT;
        std::int16_t head_angle = 0;
        bool moving = false;

    private:
        const std::int16_t x, y;

        SDL_Texture *head_tex;
        SDL_Texture *arm_tex;
        SDL_Texture *torso_tex;
        SDL_Texture *leg_tex;

        bool get_arm_rect(SDL_Rect *inner_src,
                          SDL_Rect *inner_dst,
                          SDL_Rect *outer_src,
                          SDL_Rect *outer_dst) const noexcept;

        SDL_Rect get_head_rect(SDL_Rect *rect) const noexcept;

        bool get_leg_rect(SDL_Rect *inner_src,
                          SDL_Rect *inner_dst,
                          SDL_Rect *outer_src,
                          SDL_Rect *outer_dst) const noexcept;

        SDL_Rect get_torso_rect(SDL_Rect *rect) const noexcept;
    };
}  // namespace player
