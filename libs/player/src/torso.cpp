#include "torso.h"

SDL_Rect player::get_torso_rect(int x,
                                int y,
                                Player::Direction facing,
                                SDL_Rect *rect) noexcept {
    rect->x = x - 16;
    rect->y = y;
    rect->w = 32;
    rect->h = 96;
    return {facing == Player::Direction::LEFT ? 0 : 32, 0, 32, 96};
}
