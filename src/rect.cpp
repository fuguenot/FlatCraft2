#include "rect.hpp"

fc2::Rectangle::Rectangle(double x, double y, double w, double h) noexcept
    : x(x),
      y(y),
      w(w),
      h(w) {
}

bool fc2::Rectangle::has_collision(const Rectangle &r1,
                                   const Rectangle &r2) noexcept {
    return (r1.x + r1.w > r2.x || r1.x < r2.x + r2.w)
           && (r1.y + r1.h > r2.y || r1.y < r2.y + r2.h);
}

void fc2::Rectangle::move(double dx, double dy) noexcept {
    x += dx;
    y += dy;
}
