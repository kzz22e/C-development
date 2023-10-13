#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> // RAND_MAX
#include <conio.h>
#include <Windows.h> // GetTickCount()
#include <time.h>
#include <math.h>

double get_bigger(double x, double y);
double SaveNumber(void);

// 두 수 중에서 더 큰 수를 반환하는 함수 get_bigger()를 다음과 같이 작성하고 이것을 이용해서 
// 사용자로부터 받은 실수 두 개 중에서 더 큰 수를 출력하는 프로그램을 작성하여 본다.
int main(void) {
	double x, y, result;

	x = SaveNumber();
	printf("x : %.2lf\n", x);
	y = SaveNumber();
	printf("y : %.2lf\n", y);

	result = get_bigger(x, y);
	printf("더 큰 수는 : %.2lf\n", result);

	return 0;
}


// 두 수 중에서 더 큰 수를 반환
double get_bigger(double x, double y) {
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
}


//값을 입력받기
double SaveNumber() {
	double number;

	printf("x값을 입력하세요 :");
	scanf("%lf", &number);
	getchar();

	return number;
}