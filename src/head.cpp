#include "head.hpp"

#define HEAD_TEX_WIDTH    962
#define HEAD_TEX_HEIGHT   272
#define HEAD_TEX_2_HEIGHT 544

SDL_Rect fc2::get_head_rect(int x,
                            int y,
                            short angle,
                            Player::Direction facing,
                            SDL_Rect *rect) noexcept {
    SDL_Rect src;
    if (angle > 82) {
        rect->x = x - 80;
        rect->y = y - 48;
        rect->w = 96;
        rect->h = 96;
        src = {249, HEAD_TEX_2_HEIGHT - 96, 96, 96};
    } else if (angle > 67) {
        rect->x = x - 88;
        rect->y = y - 67;
        rect->w = 118;
        rect->h = 118;
        src = {131, HEAD_TEX_2_HEIGHT - 118, 118, 118};
    } else if (angle > 52) {
        rect->x = x - 91;
        rect->y = y - 83;
        rect->w = 131;
        rect->h = 131;
        src = {0, HEAD_TEX_2_HEIGHT - 131, 131, 131};
    } else if (angle > 37) {
        rect->x = x - 88;
        rect->y = y - 90;
        rect->w = 136;
        rect->h = 136;
        src = {345, HEAD_TEX_HEIGHT, 136, 136};
    } else if (angle > 22) {
        rect->x = x - 79;
        rect->y = y - 93;
        rect->w = 131;
        rect->h = 131;
        src = {214, HEAD_TEX_HEIGHT, 131, 131};
    } else if (angle > 7) {
        rect->x = x - 66;
        rect->y = y - 90;
        rect->w = 118;
        rect->h = 118;
        src = {96, HEAD_TEX_HEIGHT, 118, 118};
    } else if (angle > -8) {
        rect->x = x - 48;
        rect->y = y - 80;
        rect->w = 96;
        rect->h = 96;
        src = {0, 0, 96, 96};
    } else if (angle > -23) {
        rect->x = x - 52;
        rect->y = y - 88;
        rect->w = 118;
        rect->h = 118;
        src = {96, 0, 118, 118};
    } else if (angle > -38) {
        rect->x = x - 51;
        rect->y = y - 91;
        rect->w = 131;
        rect->h = 131;
        src = {214, 0, 131, 131};
    } else if (angle > -53) {
        rect->x = x - 47;
        rect->y = y - 89;
        rect->w = 136;
        rect->h = 136;
        src = {345, 0, 136, 136};
    } else if (angle > -68) {
        rect->x = x - 40;
        rect->y = y - 80;
        rect->w = 131;
        rect->h = 131;
        src = {0, HEAD_TEX_HEIGHT - 131, 131, 131};
    } else if (angle > -83) {
        rect->x = x - 30;
        rect->y = y - 68;
        rect->w = 118;
        rect->h = 118;
        src = {131, HEAD_TEX_HEIGHT - 118, 118, 118};
    } else {
        rect->x = x - 16;
        rect->y = y - 48;
        rect->w = 96;
        rect->h = 96;
        src = {249, HEAD_TEX_HEIGHT - 96, 96, 96};
    }
    if (facing == fc2::Player::Direction::LEFT) {
        rect->x -= x;
        rect->x = x - rect->x - rect->w;
        src.x = HEAD_TEX_WIDTH - src.x - src.w;
    }
    return src;
}
