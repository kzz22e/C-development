#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> // RAND_MAX
#include <conio.h>
#include <Windows.h> // GetTickCount()
#include <time.h>
#include <math.h>

int Monte_Carlo();


int main() {

	int choice;

	while (1) {
		printf("앞(0) 또는 뒤(1)를 선택하시오(종료는 -1): ");
		scanf("%d", &choice);

		if (choice < 0) {
			printf("게임을 종료합니다.");
			break;
		}
		//값이 같으면 컴퓨터가 승리
		else if (choice == Monte_Carlo()) {
			printf("컴퓨터가 이겼습니다.\n");
		}
		//값이 다르면 사용자의 승리
		else if (choice != Monte_Carlo()) {
			printf("당신이 이겼습니다.\n");
		}
		//다른 값을 입력했을 시
		else {
			printf("잘못된 입력입니다.\n");
		}
	}

	return 0;
}
// 0과1중에 랜덤한 값을 반환하는 함수
int Monte_Carlo() {

	srand(time(NULL));

	return rand() % 2;
}