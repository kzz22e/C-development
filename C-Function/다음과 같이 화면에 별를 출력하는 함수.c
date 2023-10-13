#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> // RAND_MAX
#include <conio.h>
#include <Windows.h> // GetTickCount()
#include <time.h>
#include <math.h>


void draw_star(void);

//다음과 같이 화면에 *****************
//를 출력하는 함수를 작성하고 이것을 호출하여서 다음과 같은 출력을 만들어 보자.
int main(void) {

	draw_star();
	printf("hello world!\n");
	draw_star();

	return 0;
}


// ***************** 를 출력하는 프로그램
void draw_star(void) {

	printf("*****************\n");

	return;
}