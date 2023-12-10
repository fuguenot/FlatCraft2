#pragma once

#include <utility>

#include <rect/rect.h>

#include "renderer.h"

namespace player {
    class Player {
    public:
        Player(std::int16_t rx, std::int16_t ry, double x, double y) noexcept;

        rect::Rectangle get_hitbox() const noexcept;

        std::pair<double, double> get_pos() const noexcept;

        void update();

        void move(Direction direction) noexcept;
        void stop_moving() noexcept;

        Renderer renderer;

    private:
        double x, y;
        std::int32_t bx, by;
        double vy = 0;
    };
}  // namespace player
