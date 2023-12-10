#pragma once

#include <SDL.h>

#include "direction.h"

namespace player {
    class Renderer {
    public:
        ~Renderer() noexcept;

        void load_textures(SDL_Renderer *rend);

        void calculate_head_angle() noexcept;

        void render(SDL_Renderer *rend);

        Direction facing = Direction::RIGHT;
        std::int16_t head_angle = 0;
        bool moving = false;

    private:
        SDL_Texture *head_tex;
        SDL_Texture *arm_tex;
        SDL_Texture *torso_tex;
        SDL_Texture *leg_tex;

        bool get_arm_rect(int x,
                          int y,
                          SDL_Rect *inner_src,
                          SDL_Rect *inner_dst,
                          SDL_Rect *outer_src,
                          SDL_Rect *outer_dst) const noexcept;

        SDL_Rect get_head_rect(int x, int y, SDL_Rect *rect) const noexcept;

        bool get_leg_rect(int x,
                          int y,
                          SDL_Rect *inner_src,
                          SDL_Rect *inner_dst,
                          SDL_Rect *outer_src,
                          SDL_Rect *outer_dst) const noexcept;

        SDL_Rect get_torso_rect(int x, int y, SDL_Rect *rect) const noexcept;
    };
}  // namespace player
