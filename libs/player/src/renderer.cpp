#include "renderer.h"

#include <SDL_image.h>

#include <error/error.h>
#include <fcblock/fcblock.h>

#define PI 3.14159265

player::Renderer::Renderer(std::int16_t x, std::int16_t y) noexcept
    : x(x),
      y(y - block::Block::SCALE * 16 / 2) {
}

player::Renderer::~Renderer() noexcept {
    SDL_DestroyTexture(head_tex);
    SDL_DestroyTexture(arm_tex);
    SDL_DestroyTexture(torso_tex);
    SDL_DestroyTexture(leg_tex);
}

void player::Renderer::load_textures(SDL_Renderer *rend) {
    if (!(head_tex = IMG_LoadTexture(rend, "resources/steve_head.png")))
        throw error::Error(error::ErrorType::IMG_LOAD_ERROR, IMG_GetError());
    if (!(arm_tex = IMG_LoadTexture(rend, "resources/steve_arms.png")))
        throw error::Error(error::ErrorType::IMG_LOAD_ERROR, IMG_GetError());
    if (!(torso_tex = IMG_LoadTexture(rend, "resources/steve_torso.png")))
        throw error::Error(error::ErrorType::IMG_LOAD_ERROR, IMG_GetError());
    if (!(leg_tex = IMG_LoadTexture(rend, "resources/steve_legs.png")))
        throw error::Error(error::ErrorType::IMG_LOAD_ERROR, IMG_GetError());
}

void player::Renderer::calculate_head_angle() noexcept {
    int mx, my;
    SDL_GetMouseState(&mx, &my);
    int dx = mx - x;
    if (dx < 0) {
        facing = Direction::LEFT;
        dx = -dx;
    } else
        facing = Direction::RIGHT;
    int dy = -(my - y);
    head_angle = std::atan((double)dy / (double)dx) / PI * 180;
    if (head_angle > 90) head_angle = 360 - head_angle;
}

void player::Renderer::render(SDL_Renderer *rend) {
    calculate_head_angle();
    if (moving) head_angle = 0;
    SDL_Rect dst;
    SDL_Rect src = get_head_rect(&dst);
    if (SDL_RenderCopy(rend, head_tex, &src, &dst) < 0)
        throw error::Error(error::ErrorType::SDL_RENDERCOPY_ERROR,
                           SDL_GetError());
    SDL_Rect outer_leg_src, outer_leg_dst, outer_arm_src, outer_arm_dst;
    if (get_arm_rect(&src, &dst, &outer_arm_src, &outer_arm_dst))
        if (SDL_RenderCopy(rend, arm_tex, &src, &dst) < 0)
            throw error::Error(error::ErrorType::SDL_RENDERCOPY_ERROR,
                               SDL_GetError());
    if (get_leg_rect(&src, &dst, &outer_leg_src, &outer_leg_dst))
        if (SDL_RenderCopy(rend, leg_tex, &src, &dst) < 0)
            throw error::Error(error::ErrorType::SDL_RENDERCOPY_ERROR,
                               SDL_GetError());
    src = get_torso_rect(&dst);
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
