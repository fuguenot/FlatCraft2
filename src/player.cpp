#include "player.hpp"

#include <iostream>
#include <string>

#include <SDL_image.h>

#include "arm.hpp"
#include "error.hpp"
#include "head.hpp"
#include "torso.hpp"
#include "leg.hpp"

#define PI 3.14159265

void fc2::Player::load_textures(SDL_Renderer *rend) {
    if (!(head_tex = IMG_LoadTexture(rend, "resources/steve_head.png")))
        throw Error(ErrorType::IMG_LOAD_ERROR, IMG_GetError());
    if (!(arm_tex = IMG_LoadTexture(rend, "resources/steve_arm.png")))
        throw Error(ErrorType::IMG_LOAD_ERROR, IMG_GetError());
    if (!(torso_tex = IMG_LoadTexture(rend, "resources/steve_torso.png")))
        throw Error(ErrorType::IMG_LOAD_ERROR, IMG_GetError());
    if (!(leg_tex = IMG_LoadTexture(rend, "resources/steve_legs.png")))
        throw Error(ErrorType::IMG_LOAD_ERROR, IMG_GetError());
}

fc2::Player::~Player() noexcept {
    SDL_DestroyTexture(head_tex);
    SDL_DestroyTexture(arm_tex);
    SDL_DestroyTexture(torso_tex);
    SDL_DestroyTexture(leg_tex);
}

fc2::Rectangle fc2::Player::get_hitbox() const noexcept {
    return {x - 0.3, y - 1.8, 0.6, 1.8};
}

void fc2::Player::update_angle() noexcept {
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

void fc2::Player::update() {
    update_angle();
}

void fc2::Player::render(SDL_Renderer *rend) const {
    SDL_Rect dst;
    SDL_Rect src = get_head_rect(500, 350, angle, facing, &dst);
    if (SDL_RenderCopy(rend, head_tex, &src, &dst) < 0)
        throw Error(ErrorType::SDL_RENDERCOPY_ERROR, SDL_GetError());
    SDL_Rect outer_leg_src, outer_leg_dst, outer_arm_src, outer_arm_dst;
    if (get_arm_rect(500,
                     350,
                     moving,
                     facing,
                     &src,
                     &dst,
                     &outer_arm_src,
                     &outer_arm_dst))
        if (SDL_RenderCopy(rend, arm_tex, &src, &dst) < 0)
            throw Error(ErrorType::SDL_RENDERCOPY_ERROR, SDL_GetError());
    if (get_leg_rect(500,
                     350,
                     moving,
                     facing,
                     &src,
                     &dst,
                     &outer_leg_src,
                     &outer_leg_dst))
        if (SDL_RenderCopy(rend, leg_tex, &src, &dst) < 0)
            throw Error(ErrorType::SDL_RENDERCOPY_ERROR, SDL_GetError());
    src = get_torso_rect(500, 350, facing, &dst);
    if (SDL_RenderCopy(rend, torso_tex, &src, &dst) < 0)
        throw Error(ErrorType::SDL_RENDERCOPY_ERROR, SDL_GetError());
    if (SDL_RenderCopy(rend, arm_tex, &outer_arm_src, &outer_arm_dst) < 0)
        throw Error(ErrorType::SDL_RENDERCOPY_ERROR, SDL_GetError());
    if (SDL_RenderCopy(rend, leg_tex, &outer_leg_src, &outer_leg_dst) < 0)
        throw Error(ErrorType::SDL_RENDERCOPY_ERROR, SDL_GetError());
}
