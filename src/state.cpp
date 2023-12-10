#include "state.hpp"

#include <SDL_image.h>

#include <error/error.h>

fc2::State::State() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw error::Error(error::ErrorType::SDL_INIT_ERROR, SDL_GetError());
    if (!IMG_Init(IMG_INIT_PNG))
        throw error::Error(error::ErrorType::IMG_INIT_ERROR, IMG_GetError());
    if (!(win = SDL_CreateWindow("flatcraft2",
                                 SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED,
                                 1000,
                                 700,
                                 0)))
        throw error::Error(error::ErrorType::SDL_WINDOW_ERROR, SDL_GetError());
    if (!(rend = SDL_CreateRenderer(
              win,
              -1,
              SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
        throw error::Error(error::ErrorType::SDL_RENDERER_ERROR,
                           SDL_GetError());

    player.load_textures(rend);
}

fc2::State::~State() noexcept {
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
}

bool fc2::State::is_running() const noexcept {
    return running;
}
