#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>		// RAND_MAX
#include <conio.h>
#include <Windows.h>	//srand(GetTickCount());
#include <time.h>		//srand(time(NULL));
#include <math.h>


int main() {
	int integer;

	printf("정수를 입력하시오: ");
	scanf("%d", &integer);

	//값이 0이면 0값을 반환하고 종료
	if (integer == 0) {
		printf("0");
		return 0;
	}
	//값이 음수라면 -표시를 먼저 출력한뒤 음수를 양수로 변경 후 함수 실행
	else if (integer < 0) {
		//음수에서 양수값으로 변환 
		integer = -integer;
		printf("- ");
		show_digit(integer);
	}
	else {
		show_digit(integer);
	}
	return 0;
}

void show_digit(int x) {
	//더이상 나눌 값이 0보다 작으면 재귀 호출 중지한다
	if (x < 1) return;

	//순차적으로 출력 예) 234 -> 2 3 4 
	//아래 printf()코드를 show_digit()앞에 작성하면 반대로 출력
	show_digit(x / 10);
	printf("%d ", x % 10);
}

/* 실행과정 int x = 326;
4.	show_digit(326);
3.		show_digit(32);
2.			show_digit(3);
1.				show_digit(0);
1.				return;
2.			printf("%d ", x % 10);
3.		printf("%d ", x % 10);
4.	printf("%d ", x % 10);
*/

//출력: 3 2 6
