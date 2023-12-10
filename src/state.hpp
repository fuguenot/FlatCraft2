#pragma once

#include <player/player.h>

namespace fc2 {
    class State {
    public:
        State();
        ~State() noexcept;

        bool is_running() const noexcept;

        void handle_events();
        void update();
        void render();

    private:
        SDL_Window *win;
        SDL_Renderer *rend;

        bool running = true;

        player::Player player;
    };
}  // namespace fc2
