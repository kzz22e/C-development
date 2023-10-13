#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> // RAND_MAX
#include <conio.h>
#include <Windows.h> // GetTickCount()
#include <time.h>
#include <math.h>

double equation(double x, double y);
double SaveEquation(void);

// f(x, y) = 1.5*x+3.0*y를 계산하는 함수를 작성하시오
int main(void) {
	double x, y, result;

	x = SaveEquation();
	printf("x : %.2lf\n", x);
	y = SaveEquation();
	printf("y : %.2lf\n", y);

	result = equation(x, y);
	printf("f(x, y) = %.2lf\n", result);

	return 0;
}


//f(x, y) = 1.5*x+3.0*y 계산하는 함수
double equation(double x, double y) {
	return 1.5 * x + 3.0 * y;
}


//값을 입력받기
double SaveEquation() {
	double number;
	static int i = 0;
	if (i == 0) {
		printf("x값을 입력하세요 :");
		scanf("%lf", &number);
		getchar();
		i++;
	}
	else if (i == 1) {
		printf("y값을 입력하세요 :");
		scanf("%lf", &number);
		getchar();
		i = 0;
	}
	return number;
}