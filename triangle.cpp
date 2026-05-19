#include "triangle.h"
#include <algorithm>
#include <cmath>

bool isImpossible(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0)
        return true;
    if (a + b <= c || a + c <= b || b + c <= a)
        return true;
    return false;
}

TriangleType classifyTriangle(double a, double b, double c) {
    if (isImpossible(a, b, c))
        return P_IMPOSSIBLE;

    if (a == b && b == c)
        return P_EQUILATERAL;

    if (a == b || b == c || a == c)
        return P_ISOSCELES;

    double sides[3] = {a, b, c};
    std::sort(sides, sides + 3);
    if (std::abs(sides[0]*sides[0] + sides[1]*sides[1] - sides[2]*sides[2]) < 1e-9)
        return P_RIGHTANGLED;

    return P_SCALENE;
}
