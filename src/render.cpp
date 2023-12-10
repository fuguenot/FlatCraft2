#include "state.hpp"

#define SKY_COLOR 0x78, 0xa7, 0xff, SDL_ALPHA_OPAQUE

void fc2::State::render() {
    SDL_SetRenderDrawColor(rend, SKY_COLOR);
    SDL_RenderClear(rend);

    SDL_RenderPresent(rend);
}
