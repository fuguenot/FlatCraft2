#pragma once

namespace rect {
    class Rectangle {
    public:
        Rectangle(double x, double y, double w, double h) noexcept;

        static bool has_collision(const Rectangle &r1,
                                  const Rectangle &r2) noexcept;

        void move(double dx, double dy) noexcept;

    private:
        double x, y, w, h;
    };
}  // namespace rect
