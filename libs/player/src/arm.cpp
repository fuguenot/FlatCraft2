#include "arm.h"

#define ARM_TEX_HEIGHT 96

bool player::get_arm_rect(int x,
                          int y,
                          bool moving,
                          Player::Direction facing,
                          SDL_Rect *inner_src,
                          SDL_Rect *inner_dst,
                          SDL_Rect *outer_src,
                          SDL_Rect *outer_dst) noexcept {
    if (moving) {
        if (facing == Player::Direction::LEFT) {
            outer_src->x = 123;
            outer_src->y = 0;
            outer_src->w = 91;
            outer_src->h = 91;

            outer_dst->x = x - 23;
            outer_dst->y = y;
            outer_dst->w = 91;
            outer_dst->h = 91;

            inner_src->x = 32;
            inner_src->y = ARM_TEX_HEIGHT;
            inner_src->w = 91;
            inner_src->h = 91;

            inner_dst->x = x - 68;
            inner_dst->y = y;
            inner_dst->w = 91;
            inner_dst->h = 91;
        } else {
            outer_src->x = 32;
            outer_src->y = 0;
            outer_src->w = 91;
            outer_src->h = 91;

            outer_dst->x = x - 68;
            outer_dst->y = y;
            outer_dst->w = 91;
            outer_dst->h = 91;

            inner_src->x = 123;
            inner_src->y = ARM_TEX_HEIGHT;
            inner_src->w = 91;
            inner_src->h = 91;

            inner_dst->x = x - 23;
            inner_dst->y = y;
            inner_dst->w = 91;
            inner_dst->h = 91;
        }
        return true;
    } else {
        outer_src->x = 0;
        outer_src->y = 0;
        outer_src->w = 32;
        outer_src->h = 96;

        outer_dst->x = x - 16;
        outer_dst->y = y;
        outer_dst->w = 32;
        outer_dst->h = 96;

        return false;
    }
}
