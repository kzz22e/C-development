#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> // RAND_MAX
#include <conio.h>
#include <Windows.h> // GetTickCount()
#include <time.h>
#include <math.h>

//함수 선언
double dist_2d(double, double, double, double);


//7. 두 점 사이의 거리를 계산하는 함수를 작성하여 보자. 2차원 공간에서 
// 두 점 (x₁, y₁)와 (x₂, y₂) 사이의 거리를 계산하는 dist_2d()를 작성하시오. 
// 다음과 같은 두 점 사이의 거리를 계산하는 공식을 사용하라.
int main(void) {
	double x1, x2, y1, y2, result;

	printf("첫번째 점의 좌표를 입력하시오:(입력 형식 :x y)\n_ _\b\b\b");
	scanf("%lf %lf", &x1, &y1);

	printf("두번째 점의 좌표를 입력하시오:(입력 형식 :x y)\n_ _\b\b\b");
	scanf("%lf %lf", &x2, &y2);

	//result 값에 dist_2d(x1, y1, x2, y2)반환값 대입
	result = dist_2d(x1, y1, x2, y2);
	printf("두점 사이의 거리는 %lf입니다.", result);

	return 0;
}

//(x₁, y₁)와 (x₂, y₂) 사이의 거리를 계산하는 dist_2d()함수
double dist_2d(double x1, double y1, double x2, double y2) {
	double result = 0.0;

	//sqrt는 루트 이다.
	result = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));

	//result 반환
	return result;
}