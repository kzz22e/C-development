#pragma warning(disable:4996)  // 특정 경고 메시지를 억제
#include <stdio.h>             // 표준 입력 및 출력 함수를 사용하기 위한 헤더
#include <stdlib.h>            // 표준 라이브러리 함수 및 상수 (예: RAND_MAX) 사용
#include <time.h>              // 시간 및 시계 함수를 사용하기 위한 헤더 (사용되지 않음)
#include <math.h>              // 수학 함수를 사용하기 위한 헤더 (사용되지 않음)
#include <string.h>  
#include <ctype.h>

#define SIZE 100

//희문인지 아닌지 판단하는 함수
int checkPalindrome(char word[]) {
    int savePalindrome = 1; //일단 회문이라고 저장

    for (int i = 0; i < strlen(word); i++) {
        if (word[i] != word[strlen(word) - 1 - i]) {
            savePalindrome = 0; //회문이 아니라면 0이라고 저장
            break;
        }
    }
    if (savePalindrome) {
        printf("%s는 회문입니다", word);
        return 1;
    }
    else {
        printf("%s는 회문이 아닙니다\n", word);
        getchar(); //무한반복 방지
        return 0;
    }
}

int main(void) {

    //입력받은 문자열을 저장하는 코드
    char word[SIZE] = { 0 };


    while (1) {

        printf("문자열을 입력하세요: ");
        //scanf()는 공백이 있으면 공백 앞자리까지 저장하기 때문에 %[^\n]s 사용
        scanf("%[^\n]s", word);

        //checkPalindrome(word) == 0이면 회문이 아니다, 반복문 실행 
        //checkPalindrome(word) == 1이면 회문이다, 반복문 종료
        if (checkPalindrome(word)) {
            break;
        }

    }
    return 0;
}