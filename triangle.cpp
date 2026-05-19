#include "triangle.h"
#include <algorithm>
#include <array>
#include <cmath>

bool isImpossible(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return true;
    }
    if (a + b <= c || a + c <= b || b + c <= a) {
        return true;
    }
    return false;
}

TriangleType classifyTriangle(double a, double b, double c) {
    if (isImpossible(a, b, c)) {
        return P_IMPOSSIBLE;
    }

    if (a == b && b == c) {
        return P_EQUILATERAL;
    }

    const bool isIsos = (a == b || b == c || a == c);

    std::array<double, 3> sides = {a, b, c};
    std::sort(sides.begin(), sides.end());
    const bool isRight = std::abs(sides[0]*sides[0] + sides[1]*sides[1] - sides[2]*sides[2]) < 1e-9;

    if (isIsos && isRight)  { return P_RIGHT_ISOSCELES; }
    if (isIsos)             { return P_ISOSCELES; }
    if (isRight)            { return P_RIGHTANGLED; }

    return P_SCALENE;
}
