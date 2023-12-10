#include "fcblock.h"

block::Block::Block(Type type) noexcept
    : type(type),
      spritesheet_rect(get_spritesheet_rect()) {
}

SDL_Rect block::Block::get_spritesheet_rect() const noexcept {
    switch (type) {
    case Type::STONE: return {20 * 16, 9 * 16, 16, 16};
    case Type::DIRT: return {8 * 16, 6 * 16, 16, 16};
    case Type::GRASS: return {12 * 16, 10 * 16, 16, 16};
    case Type::LOG: return {3 * 16, 14 * 16, 16, 16};
    case Type::PLANK: return {16 * 16, 4 * 16, 16, 16};
    }
}

void block::Block::render(SDL_Texture *spritesheet,
                          SDL_Renderer *rend,
                          std::int16_t x,
                          std::int16_t y) const {
    SDL_Rect dst{x, y, 16 * SCALE, 16 * SCALE};
    SDL_RenderCopy(rend, spritesheet, &spritesheet_rect, &dst);
}
