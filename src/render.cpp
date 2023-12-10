#include "state.h"

#define SKY_COLOR 0x78, 0xa7, 0xff, SDL_ALPHA_OPAQUE

void fc2::State::render() {
    SDL_SetRenderDrawColor(rend, SKY_COLOR);
    SDL_RenderClear(rend);

    const auto &[px, py] = player.get_pos();

    for (const auto &[pos, block] : blocks) {
        block.render(spritesheet,
                     rend,
                     static_cast<std::int16_t>((pos.first - px) * 16
                                               * block::Block::SCALE)
                         + SCREEN_WIDTH / 2,
                     static_cast<std::int16_t>((pos.second - py) * 16
                                               * block::Block::SCALE)
                         + SCREEN_HEIGHT / 2);
    }

    player.renderer.render(rend);

    SDL_RenderPresent(rend);
}
