#pragma once

namespace fc2 {
    class Rectangle {
        double x, y, w, h;

    public:
        Rectangle(double x, double y, double w, double h) noexcept;

        static bool has_collision(const Rectangle &r1,
                                  const Rectangle &r2) noexcept;

        void move(double dx, double dy) noexcept;
    };
}  // namespace fc2
