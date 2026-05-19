# 삼각형 종류 판별 프로그램 - TDD TODO 리스트

## 반환값 정의

| 반환값 | 조건 |
|---|---|
| `P_EQUILATERAL` | 세 변의 길이가 모두 같음 (정삼각형) |
| `P_ISOSCELES` | 두 변의 길이가 같음 (이등변삼각형) |
| `P_RIGHTANGLED` | 직각삼각형 |
| `P_SCALENE` | 세 변의 길이가 모두 다름 (부등변삼각형) |
| `P_IMPOSSIBLE` | 삼각형이 성립하지 않음 |

---

## 우선순위 결정 (구현 전 합의 필요)

복합 케이스(예: 직각 이등변삼각형) 처리를 위한 판별 우선순위:

```
P_IMPOSSIBLE > P_EQUILATERAL > P_ISOSCELES > P_RIGHTANGLED > P_SCALENE
```

---

## TODO 리스트

### 1단계: 삼각형 불성립 (P_IMPOSSIBLE)
- [x] 변의 길이가 0 이하일 때 → `P_IMPOSSIBLE`
- [x] 두 변의 합이 나머지 한 변보다 작을 때 → `P_IMPOSSIBLE`
- [x] 두 변의 합이 나머지 한 변과 같을 때 → `P_IMPOSSIBLE` (경계값)

### 2단계: 정삼각형 (P_EQUILATERAL)
- [x] 세 변이 모두 같을 때 → `P_EQUILATERAL`

### 3단계: 이등변삼각형 (P_ISOSCELES)
- [x] a == b, b != c → `P_ISOSCELES`
- [x] a == c, a != b → `P_ISOSCELES`
- [x] b == c, a != b → `P_ISOSCELES`
- [x] 정삼각형(세 변 동일)은 `P_ISOSCELES`가 아님을 확인

### 4단계: 직각삼각형 (P_RIGHTANGLED)
- [x] a² + b² == c² → `P_RIGHTANGLED`
- [x] 빗변이 어느 위치에 있어도 판별 (a, b, c 순서 무관)
- [x] 부동소수점 오차 처리 필요 여부 검토 (epsilon 1e-9 적용)

### 5단계: 부등변삼각형 (P_SCALENE)
- [ ] 세 변이 모두 다르고, 직각도 아닐 때 → `P_SCALENE`

### 6단계: 복합 케이스 검증
- [ ] 직각 이등변삼각형 (예: 1, 1, √2) → `P_ISOSCELES` (우선순위에 따라)
- [ ] 직각 부등변삼각형 (예: 3, 4, 5) → `P_RIGHTANGLED`
