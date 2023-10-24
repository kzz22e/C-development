// 필요한 헤더 파일을 가져옵니다.
#define _CRT_SECURE_NO_WARNINGS // Microsoft Visual Studio와 관련된 경고를 억제
#pragma warning(disable:4996)  // 특정 경고 메시지를 억제
#include <stdio.h>             // 표준 입력 및 출력 함수를 사용하기 위한 헤더
#include <stdlib.h>            // 표준 라이브러리 함수 및 상수 (예: RAND_MAX) 사용
#include <conio.h>             // 콘솔 입출력 함수를 사용하기 위한 헤더 (사용되지 않음)
#include <Windows.h>           // 윈도우즈 API 함수를 사용하기 위한 헤더 (사용되지 않음)
#include <time.h>              // 시간 및 시계 함수를 사용하기 위한 헤더 (사용되지 않음)
#include <math.h>              // 수학 함수를 사용하기 위한 헤더 (사용되지 않음)
#include <string.h>  



int main(void) {

    //입력받은 문자열을 저장하는 코드
    char s[100] = { 0 };

    //아스키 코드의 범위만큼 범위지정 0~127
    int freq[123] = { 0 };

    printf("텍스트를 입력하시오: ");
    gets_s(s, 99);

    //입력받은 문자열의 크기만큼 반복 : strlen(s) 함수는 문자열 s의 길이를 반환합니다.
    //freq[s[i]]++; : 입력된 문자열에서 문자 s[i]의 빈도수를 증가시킵니다.즉, 
    //해당 문자가 나타날 때마다 freq 배열에서 해당 문자의 ASCII 코드 위치에 있는 요소를 1씩 증가시킵니다.
    for (int i = 0; i < strlen(s); i++) {
        //예:s[i] = 'k' 라고 가정하면 freq[K]++; -> freq[107]++ 
        freq[s[i]]++;
    }
    //if (freq[j] != 0): 문자열에 해당 문자가 하나 이상 나타났다면 아래의 코드를 실행
    for (int j = 'a'; j <= 'z'; j++) {
        if (freq[j] != 0)
            printf("%c 문자가 %d번 등장하였음!\n", j, freq[j]);
    }
    //if (freq[k] != 0): 문자열에 해당 문자가 하나 이상 나타났다면 아래의 코드를 실행
    for (int k = 'A'; k <= 'Z'; k++) {
        if (freq[k] != 0)
            printf("%c 문자가 %d번 등장하였음!\n", k, freq[k]);
    }

    return 0;
}