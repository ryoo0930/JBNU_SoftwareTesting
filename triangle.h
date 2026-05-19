#ifndef TRIANGLE_H
#define TRIANGLE_H

enum TriangleType {
    P_EQUILATERAL,
    P_RIGHT_ISOSCELES,
    P_ISOSCELES,
    P_RIGHTANGLED,
    P_SCALENE,
    P_IMPOSSIBLE
};

bool isImpossible(double a, double b, double c);
TriangleType classifyTriangle(double a, double b, double c);

#endif
