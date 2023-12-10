#pragma once

#include <SDL.h>

#include "rect.hpp"

namespace fc2 {
    class Player {
    public:
        enum class Direction { LEFT, RIGHT };

    private:
        SDL_Texture *head_tex;
        SDL_Texture *arm_tex;
        SDL_Texture *torso_tex;

        double x = 0;
        double y = 0;
        double vy = 0;
        Direction facing = Direction::RIGHT;
        short angle = 0;
        bool moving = false;

        void update_angle() noexcept;

    public:
        ~Player() noexcept;

        void load_textures(SDL_Renderer *rend);

        Rectangle get_hitbox() const noexcept;

        void update();
        void render(SDL_Renderer *rend) const;
    };
}  // namespace fc2
