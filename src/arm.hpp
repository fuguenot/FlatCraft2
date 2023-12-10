#pragma once

#include "player.hpp"

namespace fc2 {
    bool get_arm_rect(int x,
                      int y,
                      bool moving,
                      Player::Direction facing,
                      SDL_Rect *inner_src,
                      SDL_Rect *inner_dst,
                      SDL_Rect *outer_src,
                      SDL_Rect *outer_dst) noexcept;
}
