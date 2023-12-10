#pragma once

#include "player.h"

namespace player {
    SDL_Rect get_torso_rect(int x,
                            int y,
                            Player::Direction facing,
                            SDL_Rect *rect) noexcept;
}
