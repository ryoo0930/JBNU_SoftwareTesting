#include <gtest/gtest.h>
#include "triangle.h"

// 1단계: 삼각형 불성립 (P_IMPOSSIBLE)

// TC1: 변의 길이가 0인 경우
TEST(ImpossibleTest, ZeroSide) {
    EXPECT_EQ(P_IMPOSSIBLE, classifyTriangle(0, 1, 1));
    EXPECT_EQ(P_IMPOSSIBLE, classifyTriangle(1, 0, 1));
    EXPECT_EQ(P_IMPOSSIBLE, classifyTriangle(1, 1, 0));
}

// TC2: 변의 길이가 음수인 경우
TEST(ImpossibleTest, NegativeSide) {
    EXPECT_EQ(P_IMPOSSIBLE, classifyTriangle(-1, 1, 1));
    EXPECT_EQ(P_IMPOSSIBLE, classifyTriangle(1, -1, 1));
    EXPECT_EQ(P_IMPOSSIBLE, classifyTriangle(1, 1, -1));
}

// TC3: 두 변의 합이 나머지 한 변보다 작은 경우
TEST(ImpossibleTest, SumLessThanThird) {
    EXPECT_EQ(P_IMPOSSIBLE, classifyTriangle(1, 2, 4));  // 1+2=3 < 4
    EXPECT_EQ(P_IMPOSSIBLE, classifyTriangle(1, 1, 3));  // 1+1=2 < 3
    EXPECT_EQ(P_IMPOSSIBLE, classifyTriangle(5, 1, 2));  // 1+2=3 < 5
}

// TC4: 두 변의 합이 나머지 한 변과 같은 경우 (경계값)
TEST(ImpossibleTest, SumEqualToThird) {
    EXPECT_EQ(P_IMPOSSIBLE, classifyTriangle(1, 2, 3));  // 1+2=3
    EXPECT_EQ(P_IMPOSSIBLE, classifyTriangle(3, 4, 7));  // 3+4=7
    EXPECT_EQ(P_IMPOSSIBLE, classifyTriangle(7, 3, 4));  // 3+4=7, 순서 무관
}

// 2단계: 정삼각형 (P_EQUILATERAL)

// TC5: 세 변이 모두 같은 경우
TEST(EquilateralTest, AllSidesEqual) {
    EXPECT_EQ(P_EQUILATERAL, classifyTriangle(3, 3, 3));
}

// 3단계: 이등변삼각형 (P_ISOSCELES)

// TC6: a == b, b != c
TEST(IsoscelesTest, FirstTwoEqual) {
    EXPECT_EQ(P_ISOSCELES, classifyTriangle(3, 3, 4));
}

// TC7: a == c, a != b
TEST(IsoscelesTest, FirstLastEqual) {
    EXPECT_EQ(P_ISOSCELES, classifyTriangle(3, 4, 3));
}

// TC8: b == c, a != b
TEST(IsoscelesTest, LastTwoEqual) {
    EXPECT_EQ(P_ISOSCELES, classifyTriangle(4, 3, 3));
}

// TC9: 정삼각형은 P_ISOSCELES가 아님
TEST(IsoscelesTest, EquilateralIsNotIsosceles) {
    EXPECT_NE(P_ISOSCELES, classifyTriangle(3, 3, 3));
}

// 4단계: 직각삼각형 (P_RIGHTANGLED)

// TC10: 빗변이 c인 경우 (a² + b² == c²)
TEST(RightAngledTest, HypotenuseAtC) {
    EXPECT_EQ(P_RIGHTANGLED, classifyTriangle(3, 4, 5));   // 9+16=25
}

// TC11: 빗변 위치가 달라도 판별 (순서 무관)
TEST(RightAngledTest, HypotenuseAtAnyPosition) {
    EXPECT_EQ(P_RIGHTANGLED, classifyTriangle(5, 3, 4));   // 빗변이 a
    EXPECT_EQ(P_RIGHTANGLED, classifyTriangle(4, 5, 3));   // 빗변이 b
}

// TC12: 부동소수점 직각삼각형 - 30-60-90 (1, √3, 2), 세 변이 모두 다름
// (1, 1, √2)는 이등변이므로 우선순위상 P_ISOSCELES에 해당되어 제외
TEST(RightAngledTest, FloatingPoint) {
    EXPECT_EQ(P_RIGHTANGLED, classifyTriangle(1.0, 1.7320508075688772, 2.0)); // 1²+(√3)²=4=2²
}
