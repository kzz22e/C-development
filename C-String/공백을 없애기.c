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
	char s[SIZE] = { 0 };
	int count = 0;
	int tmp;

	printf("텍스트를 입력하시오: ");
	gets_s(s, SIZE - 1);

	printf("입력받은 텍스트: %s\n", s);

	//문자열 크기 strlen(s)만큼 반복해서 공백을 삭제
	while (count < strlen(s)) {
		//strlen(s)까지 문자열을 검사해서
		for (int i = 0; i < strlen(s); i++) {
			//공백이 있으면 뒷 문자랑 자리를 교환한다
			if (s[i] == ' ') {
				tmp = s[i];
				s[i] = s[i + 1];
				s[i + 1] = tmp;
			}
		}
		count++;
	}
	s[count] = '\0';
	printf("공백이 제거된 텍스트: %s", s);

	return 0;
}




