#ifndef POINT2D_HPP
#define POINT2D_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>

class Point2D
{

public:
    // Construtor
     Point2D(double x = 0.0, double y = 0.0) noexcept : mx(x), my(y) {}

    // Compute distance from a point B
    [[nodiscard]]  double distance_to(const Point2D &) const noexcept;

    // Equality operator
     bool operator==(const Point2D &) const;

    // Less then operator
     bool operator<(const Point2D &) const;

    // Getter function
    [[nodiscard]]  double xcord() const noexcept;
    [[nodiscard]]  double ycord() const noexcept;

private:
    double mx{};
    double my{};
};

#endif