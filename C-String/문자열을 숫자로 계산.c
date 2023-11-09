#pragma warning(disable:4996)  // 특정 경고 메시지를 억제
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define START_FROM_ONE 96 //대문자
#define UPPER 1 //대문자
#define LOWER 0 //소문자
#define SIZE 30

int Check_Capital_Word(char word[]) {
    for (int i = 0; i < strlen(word); i++) {
        if (isupper(word[i])) {
            return 1;
        }
    }
    return 0;
}

int SUM_Word(char word[]) {
    int sum = 0;
    for (int i = 0; i < strlen(word); i++) {
        sum += ((int)word[i] - START_FROM_ONE);
        printf("[Index]%d : %c | %d\n", i, word[i], sum);
    }
    return sum;
}

int main(void) {
    char word[SIZE] = { 0 };

    while (1) {
        printf("문자열을 입력하시오 :");
        scanf("%[^\n]s", word);
        //문자가 전부소문자가 아니라면 다시 반복
        if (Check_Capital_Word(word) == LOWER) {
            break;
        }
        printf("! 소문자로 입력해주세요 !\n");
    }
    printf("문자에 할당된 숫자의 합:%d", SUM_Word(word));
    return 0;
}
