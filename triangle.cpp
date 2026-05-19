#include "triangle.h"

TriangleType classifyTriangle(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0)
        return P_IMPOSSIBLE;
    if (a + b <= c || a + c <= b || b + c <= a)
        return P_IMPOSSIBLE;

    if (a == b && b == c)
        return P_EQUILATERAL;

    return P_IMPOSSIBLE;
}
