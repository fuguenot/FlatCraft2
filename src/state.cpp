#include "state.h"

#include <SDL_image.h>

#include <error/error.h>

fc2::State::State() : player(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.5, 0) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw error::Error(error::ErrorType::SDL_INIT_ERROR, SDL_GetError());
    if (!IMG_Init(IMG_INIT_PNG))
        throw error::Error(error::ErrorType::IMG_INIT_ERROR, IMG_GetError());
    if (!(win = SDL_CreateWindow("flatcraft2",
                                 SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED,
                                 SCREEN_WIDTH,
                                 SCREEN_HEIGHT,
                                 0)))
        throw error::Error(error::ErrorType::SDL_WINDOW_ERROR, SDL_GetError());
    if (!(rend = SDL_CreateRenderer(
              win,
              -1,
              SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
        throw error::Error(error::ErrorType::SDL_RENDERER_ERROR,
                           SDL_GetError());

    player.renderer.load_textures(rend);
    if (!(spritesheet = IMG_LoadTexture(rend, "../Resources/spritesheet.png")))
        throw error::Error(error::ErrorType::IMG_LOAD_ERROR, IMG_GetError());

    blocks.insert_or_assign(std::pair{0, -1},
                            block::Block{block::Block::Type::STONE});
}

fc2::State::~State() noexcept {
    SDL_DestroyTexture(spritesheet);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
}

bool fc2::State::is_running() const noexcept {
    return running;
}
