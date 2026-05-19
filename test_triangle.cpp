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
