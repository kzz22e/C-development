#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> // RAND_MAX
#include <conio.h>
#include <Windows.h> // GetTickCount()
#include <time.h>
#include <math.h>

//선언
double quad_eqn(double, double, double);
double Save_Number();


//2차 방정식의 근을 계산하는 함수 quad_eqn()를 작성하라. 
//quad_eqn()함수는 a, b, c를 나타내는 double형의 3개의 인수를 받는다. 
//판별식이 양수인 경우에만 근을 출력하라. 만약 판별식의 값이 음수이면 근이 없다는 메시지를 출력하라.


int main(void) {

	double a = 0.0, b = 0.0, c = 0.0;

	printf("2차 방정식의 계수를 입력하시오:\n");

	a = Save_Number();
	b = Save_Number();
	c = Save_Number();

	quad_eqn(a, b, c);

	return 0;
}
//계수 값을 입력받는 함수
double Save_Number() {
	double n;
	static int i = 0;

	if (i == 0) {
		printf("a: ");
		scanf("%lf", &n);
		i++;

		return n;
	}
	else if (i == 1) {
		printf("b: ");
		scanf("%lf", &n);
		i++;

		return n;
	}
	else if (i == 2) {
		printf("c: ");
		scanf("%lf", &n);
		i = 0;

		return n;
	}
}

//2차 방정식의 근을 계산하는 함수 quad_eqn()함수
double quad_eqn(double a, double b, double c) {
	double result = 0.0;
	double D;
	double first_value = 0.0, second_value = 0.0;


	//판별식
	D = b * b - (4 * a * c);

	//서로 다른 두 실근
	if (D > 0) {
		first_value = (-b + sqrt(D)) / (2.0 * a);
		second_value = (-b - sqrt(D)) / (2.0 * a);
		printf("D>0 이므로 이차방정식의 근은 2개이다\n");
		printf("첫 번째 근 %.6lf\n", first_value);
		printf("두 번째 근 %.6lf\n", second_value);
		return first_value;
	}
	//중근
	else if (D == 0) {
		first_value = (-b + sqrt(D)) / (2.0 * a);
		printf("D=0 이므로 이차방정식의 근은 1개이다\n");
		printf("첫 번째 근 %.6lf\n", first_value);
		return first_value;
	}
	//허근
	else if (D < 0) {
		printf("방정식의 근이 없습니다.\n");
		return 0;
	}
}
//