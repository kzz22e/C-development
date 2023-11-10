#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 상수 정의
#define START_FROM_ONE 96 // 대문자 'A'의 시작을 1로지정
#define UPPER 1           // 대문자 여부를 나타내는 상수
#define LOWER 0           // 소문자 여부를 나타내는 상수
#define SIZE 30            // 문자열의 최대 길이

// 대문자이거나 숫자인지 확인하는 함수
int Check_Capital_Word(char word[]) {
    for (int i = 0; i < strlen(word); i++) {
        if (isupper(word[i]) || isdigit(word[i])) {
            return 1;
        }
    }
    return 0;
}

// 문자열에 할당된 숫자의 합을 계산하는 함수
int SUM_Word(char word[]) {
    int sum = 0;
    for (int i = 0; i < strlen(word); i++) {
        sum += ((int)word[i] - START_FROM_ONE);
        // 각 문자의 인덱스, 문자, 누적 합 출력
        printf("[Index]%d : %c | %d\n", i, word[i], sum);
    }
    return sum;
}

// 프로그램의 시작점
int main(void) {
    char word[SIZE] = { 0 };  // 입력받을 문자열을 저장하는 배열

    // 사용자로부터 소문자로 이루어진 문자열을 입력받음
    while (1) {
        printf("문자열을 입력하시오: ");
        scanf("%[^\n]s", word);
        getchar();  // 개행 문자 처리

        // 문자열에 대문자이거나 숫자가 포함되어 있으면 다시 입력받음
        if (Check_Capital_Word(word) == LOWER) {
            break;
        }
        printf("! 소문자로 입력해주세요 !\n");
    }

    // 문자열에 할당된 숫자의 합을 계산하고 출력
    printf("문자에 할당된 숫자의 합: %d", SUM_Word(word));

    return 0;  // 프로그램 종료
}
