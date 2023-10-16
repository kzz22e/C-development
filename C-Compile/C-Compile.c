#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>		// RAND_MAX
#include <conio.h>
#include <Windows.h>	//srand(GetTickCount());
#include <time.h>		//srand(time(NULL));
#include <math.h>

//선언
double Calculator(double , char , double);


int main(void){
	double x = 0.0, y = 0.0;
	char a;
	while (1) {
		printf("연산을 입력하시오(종료는 Ctrl-Z):");
		scanf("%lf %c %lf", &x, &a, &y);

		// Ctrl-Z 반복 종료
		if (x == EOF || a == NULL || y == EOF){
			break;
		}
		Calculator(x, a, y);
	}

		return 0;
}

double Calculator(double x,char a,double y){
	double result;
	//정적 지역 변수
	static int plus_count = 0, minus_count = 0, multiple_count = 0, division_count = 0; 

	if (a == '+') {
		result = x + y;
		plus_count++;
		printf("덧셈은 총 %d번 호출되었습니다\n", plus_count);
		printf("연산결과 : %.2lf\n", result);
		return result;
	}
	else if (a == '-') {
		result = x - y;
		minus_count++;
		printf("뺄셈은 총 %d번 호출되었습니다\n", minus_count);
		printf("연산결과 : %.2lf\n", result);
		return result;
	}
	else if (a == '*') {
		result = x * y;
		multiple_count++;
		printf("곱셈은 총 %d번 호출되었습니다\n", multiple_count);
		printf("연산결과 : %.2lf\n", result);
		return result;
	}
	else if (a == '/') {
		result = x / y;
		division_count++;
		printf("나눗셈은 총 %d번 호출되었습니다\n", division_count);
		printf("연산결과 : %.2lf\n", result);
		return result;
	}
}