#define _CRT_SECURE_NO_WARNINGS		// Microsoft Visual Studio와 관련된 경고를 억제
#pragma warning(disable:4996)		// 특정 경고 메시지를 억제
#include <stdio.h>					// 표준 입력 및 출력 함수를 사용하기 위한 헤더
#include <stdlib.h>					// 표준 라이브러리 함수 및 상수 (예: RAND_MAX) 사용
#include <conio.h>					// 콘솔 입출력 함수를 사용하기 위한 헤더 (사용되지 않음)
#include <Windows.h>				// 윈도우즈 API 함수를 사용하기 위한 헤더 (사용되지 않음)
#include <time.h>					// 시간 및 시계 함수를 사용하기 위한 헤더 (사용되지 않음)
#include <math.h>					// 수학 함수를 사용하기 위한 헤더 (사용되지 않음)
#include <string.h>  
#include <ctype.h>						  
#define SIZE 100

int main(void) {

	//입력받은 문자열을 저장
	char text[SIZE] = { 0 };

	printf("텍스트를 입력하시오: ");
	gets_s(text, SIZE - 1);

	//대문자로 변경 후 출력
	//문자열의 길이 strlen(s)만큼 반복
	for (int i = 0; i < strlen(text); i++) {
		//대문자로 변경한값을 다시 문자열에 저장
		text[i] = toupper(text[i]);
		printf("%c", text[i]);
	}

	//소문자로 변경 후 출력
	//문자열의 길이 strlen(s)만큼 반복
	for (int i = 0; i < strlen(text); i++) {
		//대문자로 변경한값을 다시 문자열에 저장
		text[i] = tolower(text[i]);
		printf("%c", text[i]);
	}

	return 0;
}


