#include "renderer.h"

#define LEG_TEX_HEIGHT 96

bool player::Renderer::get_leg_rect(SDL_Rect *inner_src,
                                    SDL_Rect *inner_dst,
                                    SDL_Rect *outer_src,
                                    SDL_Rect *outer_dst) const noexcept {
    if (moving) {
        if (facing == Direction::LEFT) {
            outer_src->x = 123;
            outer_src->y = LEG_TEX_HEIGHT;
            outer_src->w = 91;
            outer_src->h = 91;

            outer_dst->x = x - 13;
            outer_dst->y = y + 86;
            outer_dst->w = 91;
            outer_dst->h = 91;

            inner_src->x = 32;
            inner_src->y = LEG_TEX_HEIGHT;
            inner_src->w = 91;
            inner_src->h = 91;

            inner_dst->x = x - 78;
            inner_dst->y = y + 86;
            inner_dst->w = 91;
            inner_dst->h = 91;
        } else {
            outer_src->x = 32;
            outer_src->y = 0;
            outer_src->w = 91;
            outer_src->h = 91;

            outer_dst->x = x - 78;
            outer_dst->y = y + 86;
            outer_dst->w = 91;
            outer_dst->h = 91;

            inner_src->x = 123;
            inner_src->y = 0;
            inner_src->w = 91;
            inner_src->h = 91;

            inner_dst->x = x - 13;
            inner_dst->y = y + 86;
            inner_dst->w = 91;
            inner_dst->h = 91;
        }
        return true;
    } else {
        outer_src->x = 0;
        outer_src->y = facing == Direction::LEFT ? 96 : 0;
        outer_src->w = 32;
        outer_src->h = 96;

        outer_dst->x = x - 16;
        outer_dst->y = y + 96;
        outer_dst->w = 32;
        outer_dst->h = 96;

        return false;
    }
}
