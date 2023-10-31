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
	char result[SIZE] = { 0 };
	int i = 0, j = 0;

	printf("텍스트를 입력하시오: ");
	gets_s(s, SIZE - 1);

	//널 값이 나올때 까지 반복
	while (s[i] != '\0') {
		//값이 모음이 아니라면 값을 복사해서 저장한다
		if (s[i] != 'a' &&	//a가 아니거나
			s[i] != 'i' &&	//i가 아니거나
			s[i] != 'e' &&	//e가 아니거나
			s[i] != 'o' &&	//o가 아니거나
			s[i] != 'u'){	//u가 아니면
			result[j] = s[i];
			j++;			//최종의 j값은 문자의 마지막이기 때문에 널값을 넣어줘야한다
		}
		//모음이라면 그값을 건너뛴다.
		i++;
	}

	result[j] = '\0';

	printf("최종 텍스트: %s\n", result);

	return 0;
}

//다른 예제
int main(void) {
    char s[SIZE] = { 0 };
    int i = 0;

    printf("텍스트를 입력하시오: ");
    fgets(s, SIZE, stdin); // gets_s 대신 fgets를 사용하고 표준 입력(stdin)을 사용합니다.

    while (s[i] != '\0') {
        if (s[i] == 'a' ||  // 'a' 이거나
            s[i] == 'i' ||  // 'i' 이거나
            s[i] == 'e' ||  // 'e' 이거나
            s[i] == 'o' ||  // 'o' 이거나
            s[i] == 'u') {  // 'u' 이면
            s[i] = ' ';
        }
        i++;
    }

    printf("최종 텍스트: %s\n", s);

    return 0;
}
