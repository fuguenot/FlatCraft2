#include "renderer.h"

SDL_Rect player::Renderer::get_torso_rect(SDL_Rect *rect) const noexcept {
    rect->x = x - 16;
    rect->y = y;
    rect->w = 32;
    rect->h = 96;
    return {facing == Direction::LEFT ? 0 : 32, 0, 32, 96};
}
