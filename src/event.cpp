#include "state.hpp"

void fc2::State::handle_events() {
    SDL_Event e;

    while (SDL_PollEvent(&e)) {
        player.stop_moving();

        switch (e.type) {
        case SDL_QUIT: running = false; break;
        default: break;
        }

        const uint8_t *state = SDL_GetKeyboardState(NULL);
        if (state[SDL_SCANCODE_A])
            player.move(player::Direction::LEFT);
        else if (state[SDL_SCANCODE_D])
            player.move(player::Direction::RIGHT);
    }
}
