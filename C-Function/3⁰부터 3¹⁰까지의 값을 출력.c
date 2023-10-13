#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> // RAND_MAX
#include <conio.h>
#include <Windows.h> // GetTickCount()
#include <time.h>
#include <math.h>

double power(double x, double y);


//본문에 등장한 거듭제곱 계산 함수 power()를 호출하여 
// 3⁰부터 3¹⁰까지의 값을 출력하는 프로그램을 작성하라.

int main(void) {

	for (int i = 0; i <= 10; i++)
		printf("%.0lf ", power((double)3, (double)i));

	return 0;
}

//거듭제곱을 계산하는 함수
double power(double x, double y) {
	//0의 값에 어떤 값을 곱해도 0이기 때문에 1로 초기화 한다
	double result = 1.0;

	for (int i = 0; i < y; i++)
		result *= x;

	return result;
}

/* 주의사항
double c = int a / int b; 일때 연산결과의 자료형은(double c)
피연산자의 자료형과(int a, int b) 일치한다고 한다고 합니다.

double c = int a / int b; 일때 c의 값은 int로 계산된 이후 출력이 되는 것입니다.

double c = 2 / 3; 이라는 문장이 있어도 답이 소수점으로 나오지 않고
0으로 계산된 이후 double 형으로 출력이 되어 0.00으로 표기됩니다.
*/