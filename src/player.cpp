#include "player.hpp"

#include <iostream>
#include <string>

#include <SDL_image.h>

#include "error.hpp"
#include "head.hpp"

#define PI 3.14159265

void fc2::Player::load_textures(SDL_Renderer *rend) {
    if (!(head_tex = IMG_LoadTexture(rend, "resources/steve_head.png")))
        throw Error(ErrorType::IMG_LOAD_ERROR, IMG_GetError());
}

fc2::Player::~Player() noexcept {
    SDL_DestroyTexture(head_tex);
}

fc2::Rectangle fc2::Player::get_hitbox() const noexcept {
    return {x - 0.3, y - 1.8, 0.6, 1.8};
}

void fc2::Player::update() {
    int mx, my;
    SDL_GetMouseState(&mx, &my);
    int dx = mx - 500;
    if (dx < 0) {
        facing = Direction::LEFT;
        dx = -dx;
    } else
        facing = Direction::RIGHT;
    int dy = -(my - 350);
    angle = std::atan((double)dy / (double)dx) / PI * 180;
    if (angle > 90) angle = 360 - angle;
}

void fc2::Player::render(SDL_Renderer *rend) const {
    SDL_Rect dst;
    SDL_Rect src = get_head_rect(500, 350, angle, facing, &dst);
    if (SDL_RenderCopy(rend, head_tex, &src, &dst) < 0)
        throw Error(ErrorType::SDL_RENDERCOPY_ERROR, SDL_GetError());
}
