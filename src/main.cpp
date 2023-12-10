#include <iostream>

#include <error/error.h>

#include "state.h"

int main() {
    try {
        fc2::State state;

        while (state.is_running()) {
            state.handle_events();
            state.update();
            state.render();
        }

    } catch (error::Error &e) {
        std::cerr << e.to_string() << std::endl;
        std::exit(1);
    }
}
