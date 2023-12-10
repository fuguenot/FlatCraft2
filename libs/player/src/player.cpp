#include "player.h"

#include <string>

#include <SDL_image.h>

#include <error/error.h>

#include "arm.h"
#include "head.h"
#include "torso.h"
#include "leg.h"

#define PI 3.14159265

void player::Player::load_textures(SDL_Renderer *rend) {
    if (!(head_tex = IMG_LoadTexture(rend, "resources/steve_head.png")))
        throw error::Error(error::ErrorType::IMG_LOAD_ERROR, IMG_GetError());
    if (!(arm_tex = IMG_LoadTexture(rend, "resources/steve_arms.png")))
        throw error::Error(error::ErrorType::IMG_LOAD_ERROR, IMG_GetError());
    if (!(torso_tex = IMG_LoadTexture(rend, "resources/steve_torso.png")))
        throw error::Error(error::ErrorType::IMG_LOAD_ERROR, IMG_GetError());
    if (!(leg_tex = IMG_LoadTexture(rend, "resources/steve_legs.png")))
        throw error::Error(error::ErrorType::IMG_LOAD_ERROR, IMG_GetError());
}

player::Player::~Player() noexcept {
    SDL_DestroyTexture(head_tex);
    SDL_DestroyTexture(arm_tex);
    SDL_DestroyTexture(torso_tex);
    SDL_DestroyTexture(leg_tex);
}

bool player::Player::is_moving() const noexcept {
    return moving;
}

void player::Player::stop_moving() noexcept {
    moving = false;
}

void player::Player::move(Direction direction) noexcept {
    facing = direction;
    moving = true;
    x += direction == Direction::LEFT ? -0.15 : 0.15;
    head_angle = 0;
}

rect::Rectangle player::Player::get_hitbox() const noexcept {
    return {x - 0.3, y - 1.8, 0.6, 1.8};
}

void player::Player::update_angle() noexcept {
    int mx, my;
    SDL_GetMouseState(&mx, &my);
    int dx = mx - 500;
    if (dx < 0) {
        facing = Direction::LEFT;
        dx = -dx;
    } else
        facing = Direction::RIGHT;
    int dy = -(my - 350);
    head_angle = std::atan((double)dy / (double)dx) / PI * 180;
    if (head_angle > 90) head_angle = 360 - head_angle;
}

void player::Player::update() {
}

void player::Player::render(SDL_Renderer *rend) const {
    SDL_Rect dst;
    SDL_Rect src = get_head_rect(500, 350, head_angle, facing, &dst);
    if (SDL_RenderCopy(rend, head_tex, &src, &dst) < 0)
        throw error::Error(error::ErrorType::SDL_RENDERCOPY_ERROR,
                           SDL_GetError());
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
            throw error::Error(error::ErrorType::SDL_RENDERCOPY_ERROR,
                               SDL_GetError());
    if (get_leg_rect(500,
                     350,
                     moving,
                     facing,
                     &src,
                     &dst,
                     &outer_leg_src,
                     &outer_leg_dst))
        if (SDL_RenderCopy(rend, leg_tex, &src, &dst) < 0)
            throw error::Error(error::ErrorType::SDL_RENDERCOPY_ERROR,
                               SDL_GetError());
    src = get_torso_rect(500, 350, facing, &dst);
    if (SDL_RenderCopy(rend, torso_tex, &src, &dst) < 0)
        throw error::Error(error::ErrorType::SDL_RENDERCOPY_ERROR,
                           SDL_GetError());
    if (SDL_RenderCopy(rend, arm_tex, &outer_arm_src, &outer_arm_dst) < 0)
        throw error::Error(error::ErrorType::SDL_RENDERCOPY_ERROR,
                           SDL_GetError());
    if (SDL_RenderCopy(rend, leg_tex, &outer_leg_src, &outer_leg_dst) < 0)
        throw error::Error(error::ErrorType::SDL_RENDERCOPY_ERROR,
                           SDL_GetError());
}
