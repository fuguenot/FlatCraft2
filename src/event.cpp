#include "state.hpp"

void fc2::State::handle_events() {
    SDL_Event e;

    while (SDL_PollEvent(&e)) {
        switch (e.type) {
        case SDL_QUIT: running = false; break;
        default: break;
        }
    }
}
