#pragma warning(disable:4996)  // 특정 경고 메시지를 억제
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 30

int PasswordValid(char password[SIZE]) {
    int check[3] = { 0 }; // 0: 숫자, 1: 소문자, 2: 대문자

    // 암호의 길이 확인
    if (strlen(password) <= 6) {
        printf("6자리 이상 입력해주세요.\n");
        return 0; // 유효하지 않음
    }

    for (int i = 0; i < strlen(password); i++) {
        // 소문자이면 !=0을 반환
        if (islower(password[i])) {
            check[0] = 1;
        }
        // 대문자면 !=0을 반환
        else if (isupper(password[i])) {
            check[1] = 1;
        }
        // 숫자이면 !=0을 반환
        else if (isdigit(password[i])) {
            check[2] = 1;
        }
    }

    // check[0] && check[1] && check[2]과 전부 1이면
    if (check[0] && check[1] && check[2]) {
        return 1; // 유효함
    }
    else {
        printf("숫자, 소문자, 대문자를 섞어서 암호를 다시 만드세요!\n");
        return 0; // 유효하지 않음
    }
}

int main(void) {
    char password[SIZE] = { 0 };

    while (1) {
        printf("암호를 생성하시오 (6자리 이상): ");
        //scanf()는 공백이 있으면 공백 앞자리까지 저장하기 때문에 %[^\n]s 사용
        scanf(" %[^\n]s", password);

        if (PasswordValid(password)) {
            printf("적절한 암호입니다.\n");
            break;
        }
    }
    return 0;
}
