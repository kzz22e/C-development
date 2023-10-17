#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>		// RAND_MAX
#include <conio.h>
#include <Windows.h>	//srand(GetTickCount());
#include <time.h>		//srand(time(NULL));
#include <math.h>

//선언
long draw(long);
void save(void);

//전역 변수
long money = 0;

int main(void) {
	//지역변수
	long amount = 0;

	while (1) {
		printf("얼마를 저축하시겠습니까?(종료는 -1):");
		scanf("%ld", &amount);

		// -1입력시 종료
		if (money == -1) {
			break;
		}
		else {
			save(draw(amount));
		}
	}

	return 0;
}
//돈을 저금하는 함수
long draw(long amount) {
	return money += amount;
}

//지금까지의 저축액 출력
void save(void) {
	printf("지금까지의 저축액은 %ld\n", money);
}
