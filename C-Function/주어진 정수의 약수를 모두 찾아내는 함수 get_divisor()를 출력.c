#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> // RAND_MAX
#include <conio.h>
#include <Windows.h> // GetTickCount()
#include <time.h>
#include <math.h>

int save_integer(void);
int get_divisor(int x);

//주어진 정수의 약수를 모두 찾아내는 함수 get_divisor()를 
//작성하여 보라.만약 8이 주어지면 1, 2, 4, 8을 화면에 출력하여야 한다.
//이 함수를 테스트하기 위한 main()를 작성하라.
int main(void) {

	get_divisor(save_integer());

	return 0;
}


//정수의 약수를 찾아내는 함수
int get_divisor(int x) {
	int i;
	printf("%d의 약수: ", x);
	for (i = 1; i <= x; i++) {
		if (x % i == 0) {
			printf("%d|", i);
		}
	}
	return x;
}
//정수를 입력받는 함수
int save_integer(void) {
	int number;

	printf("약수를 입력해주세요 :____\b\b\b\b");
	scanf("%d", &number);

	return number;
}