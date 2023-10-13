#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> // RAND_MAX
#include <conio.h>
#include <Windows.h> // GetTickCount()
#include <time.h>
#include <math.h>

int check_prime(int);


//본문에 등장한 소수(prime number)인지를 검사하는 함수 check_prime()를 사용하여 
//1부터 100 사이에 존재하는 소수들을 모두 출력하는 프로그램을 작성한다.
int main(void) {

	int i;

	for (i = 1; i <= 100; i++) {
		if (check_prime(i) == 1) {
			printf("%d | ", i);
		}
	}

	return 0;
}

//정수의 소수를 찾아내는 함수
int check_prime(int x) {
	int i;
	if (x == 1) {
		return 1;
	}
	for (i = 2; i < x; i++) {
		if (x % i == 0) {
			return 0; //소수가 아니다
		}
	}
	return 1; // 소수이다
}