#pragma once

#include "player.hpp"

namespace fc2 {
    SDL_Rect get_torso_rect(int x,
                            int y,
                            Player::Direction facing,
                            SDL_Rect *rect) noexcept;
}
