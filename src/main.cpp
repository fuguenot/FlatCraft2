#include <iostream>

#include "error.hpp"
#include "state.hpp"

int main() {
    try {
        fc2::State state;

        while (state.running) {
            state.handle_events();
            state.update();
            state.render();
        }

    } catch (fc2::Error &e) {
        std::cerr << e.to_string();
        std::exit(1);
    }
}
