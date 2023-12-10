#include "player.h"

#include <cmath>

player::Player::Player(std::int16_t rx,
                       std::int16_t ry,
                       double x,
                       double y) noexcept
    : renderer(rx, ry),
      x(x),
      y(y),
      bx(std::floor(x - 0.5)),
      by(std::floor(y)) {
}

void player::Player::stop_moving() noexcept {
    renderer.moving = false;
}

void player::Player::move(Direction direction) noexcept {
    renderer.moving = true;
    x += direction == Direction::LEFT ? -0.15 : 0.15;
}

rect::Rectangle player::Player::get_hitbox() const noexcept {
    return {x - 0.3, y - 2.0, 0.6, 2.0};
}

std::pair<double, double> player::Player::get_pos() const noexcept {
    return {x, y};
}

void player::Player::update() {
}
