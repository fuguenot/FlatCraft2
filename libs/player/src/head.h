#pragma once

#include "player.h"

namespace player {
    SDL_Rect get_head_rect(int x,
                           int y,
                           std::int16_t angle,
                           Player::Direction facing,
                           SDL_Rect *rect) noexcept;
}
