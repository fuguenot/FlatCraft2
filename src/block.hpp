#pragma once

namespace fc2 {
    class Block {
    public:
        enum class Type : std::uint8_t { STONE, DIRT, GRASS, LOG, PLANK };

    private:
        std::int32_t x, y;
    };
}  // namespace fc2
