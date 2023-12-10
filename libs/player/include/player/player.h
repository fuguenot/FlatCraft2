#pragma once

#include <SDL.h>

#include "rect/rect.h"

namespace player {
    class Player {
    public:
        enum class Direction : bool { LEFT, RIGHT };

        ~Player() noexcept;

        void load_textures(SDL_Renderer *rend);

        rect::Rectangle get_hitbox() const noexcept;

        void update();
        void update_angle() noexcept;

        void render(SDL_Renderer *rend) const;

        bool is_moving() const noexcept;
        void move(Direction direction) noexcept;
        void stop_moving() noexcept;

    private:
        SDL_Texture *head_tex;
        SDL_Texture *arm_tex;
        SDL_Texture *torso_tex;
        SDL_Texture *leg_tex;

        double x = 0.5;
        double y = 0;
        std::int32_t block_x = 0;
        std::int32_t block_y = 0;
        double vy = 0;
        Direction facing = Direction::RIGHT;
        std::int16_t head_angle = 0;
        bool moving = false;
    };
}  // namespace player
