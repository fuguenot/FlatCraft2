#pragma once

#include <rect/rect.h>

#include "renderer.h"

namespace player {
    class Player {
    public:
        rect::Rectangle get_hitbox() const noexcept;

        void update();

        void move(Direction direction) noexcept;
        void stop_moving() noexcept;

        Renderer renderer;

    private:
        double x = 0.5;
        double y = 0;
        std::int32_t block_x = 0;
        std::int32_t block_y = 0;
        double vy = 0;
    };
}  // namespace player
