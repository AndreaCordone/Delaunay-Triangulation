#include "Point2D.hpp"

// Compute distance from a point B
[[nodiscard]] constexpr double Point2D::distance_to(const Point2D &B) const noexcept
{
    // Computing disctance from a give point B
    double dx = mx - B.xcord();
    double dy = my - B.ycord();
    return std::sqrt(dx * dx + dy * dy);
};

// Comparison methods
constexpr bool Point2D::operator==(const Point2D &B) const
{
    const double eps = 1e-12;
    const double dx = mx - B.xcord();
    const double dy = my - B.ycord();

    // The rusult of this comparison is a bool
    return std::fabs(dx) < eps && std::fabs(dy) < eps;
}

// Less than comparison of two point, this methods is needed in case the Point2D class
// is used in ordered contained like map, set, etc..
// Questo metodo di ordinamento è importate perche verra utilizzato per ordinare gli edge
constexpr bool Point2D::operator<(const Point2D &B) const
{
    // The make_tuple function create a tuple, in the tuple the < operator is alredy defined.
    return std::make_tuple(mx, my) < std::make_tuple(B.xcord(), B.ycord());
}

// Getter function for x coordinate
[[nodiscard]] constexpr double Point2D::xcord() const noexcept
{
    return (mx);
};

// Getter function for y coordinate
[[nodiscard]] constexpr double Point2D::ycord() const noexcept
{
    return (my);
};