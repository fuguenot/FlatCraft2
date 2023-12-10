#pragma once

#include <memory>

#include <SDL.h>

namespace fc2 {
    class State {
        SDL_Window *win;
        SDL_Renderer *rend;

    public:
        bool running = true;

        State();
        ~State() noexcept;

        void handle_events();
        void update();
        void render();
    };
}  // namespace fc2
