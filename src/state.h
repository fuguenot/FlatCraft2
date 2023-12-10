#pragma once

#include <unordered_map>

#include <fcblock/fcblock.h>
#include <pair_hash/pair_hash.hpp>
#include <player/player.h>

namespace fc2 {
    class State {
    public:
        static const std::int16_t SCREEN_WIDTH = 1'000;
        static const std::int16_t SCREEN_HEIGHT = 700;

        State();
        ~State() noexcept;

        bool is_running() const noexcept;

        void handle_events();
        void update();
        void render();

    private:
        SDL_Window *win;
        SDL_Renderer *rend;

        SDL_Texture *spritesheet;

        bool running = true;

        player::Player player;

        std::unordered_map<std::pair<int32_t, int32_t>,
                           block::Block,
                           pair_hash::pair_hash>
            blocks;
    };
}  // namespace fc2
