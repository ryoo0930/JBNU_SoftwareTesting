#ifndef TRIANGLE_H
#define TRIANGLE_H

enum TriangleType {
    P_EQUILATERAL,
    P_ISOSCELES,
    P_RIGHTANGLED,
    P_SCALENE,
    P_IMPOSSIBLE
};

TriangleType classifyTriangle(double a, double b, double c);

#endif
