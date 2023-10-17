#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>		// RAND_MAX
#include <conio.h>
#include <Windows.h>	//srand(GetTickCount());
#include <time.h>		//srand(time(NULL));
#include <math.h>

//선언
long long Save_integer();
long long exponential(long long);

//전역 변수
long long int integer = 0;
int savePM = 0; //1은 양수 0은 음수

//실행
int main(void) {
	long long base = 0;
	while (1) {
		base = exponential(Save_integer());
		if (savePM == 0) {
			base = -base; //다시 음수로 변환
			printf("%lld\n", base);
		}
		else if (savePM == 1) {
			printf("%lld\n", base);
		}
	}

	return 0;
}

//정수를 입력받는 함수
long long Save_integer() {

	printf("정수를 입력하시오 : ");
	scanf("%lld", &integer);

	//음수라면 일단 savePM 음수라고 저장하고 양수로 바꿔준다
	if (integer < 0) {
		savePM = 0;			//음수라고 저장
		return -integer;	//양수로 변환후 반환
	}
	//양수라면 일단 savePM 양수라고 저장
	savePM = 1;			//양수라고 저장
	return integer;		//양수값 반환
}

//입력받은 정수를 세제곱해서 내림차순으로 더하는 재귀 함수
long long exponential(long long integer) {
	if (integer == 1) {
		return 1;
	}
	return pow(integer, 3) + exponential(integer - 1);
}

