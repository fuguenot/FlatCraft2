#pragma once

#include <memory>

#include "player.hpp"

namespace fc2 {
    class State {
        SDL_Window *win;
        SDL_Renderer *rend;

        bool running = true;

        Player player;

    public:
        State();
        ~State() noexcept;

        bool is_running() const noexcept;

        void handle_events();
        void update();
        void render();
    };
}  // namespace fc2
