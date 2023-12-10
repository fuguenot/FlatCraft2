#pragma once

#include "player.hpp"

namespace fc2 {
    SDL_Rect get_head_rect(int x,
                           int y,
                           short angle,
                           fc2::Player::Direction facing,
                           SDL_Rect *rect);
}
