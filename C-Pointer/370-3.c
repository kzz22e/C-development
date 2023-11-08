#include <stdio.h>
#include <math.h>

// 이 함수는 이차 방정식의 해를 계산하는 함수입니다.
// a, b, c는 방정식 ax^2 + bx + c = 0의 계수입니다.
// xplus와 xminus는 실근을 저장하기 위한 포인터입니다.
void quadratic(int a, int b, int c, double* xplus, double* xminus) {
    // 이차 방정식의 근의 공식을 사용하여 xplus와 xminus 값을 계산합니다.
    *xminus = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    *xplus = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

int main(void) {
    int a = 10, b = 40, c = 30;
    double xminus, xplus;

    // quadratic 함수를 호출하여 이차 방정식의 해를 계산합니다.
    quadratic(a, b, c, &xplus, &xminus);

    // 계산된 실근을 출력합니다.
    printf("첫번째 실근: %lf\n", xplus);
    printf("두번째 실근: %lf\n", xminus);

    return 0;
}