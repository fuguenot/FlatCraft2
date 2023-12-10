#include "player.h"

void player::Player::stop_moving() noexcept {
    renderer.moving = false;
}

void player::Player::move(Direction direction) noexcept {
    renderer.moving = true;
    x += direction == Direction::LEFT ? -0.15 : 0.15;
}

rect::Rectangle player::Player::get_hitbox() const noexcept {
    return {x - 0.3, y - 1.8, 0.6, 1.8};
}

void player::Player::update() {
}
