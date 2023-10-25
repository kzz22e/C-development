#pragma warning(disable:4996)  // 특정 경고 메시지를 억제
#include <stdio.h>             // 표준 입력 및 출력 함수를 사용하기 위한 헤더
#include <stdlib.h>            // 표준 라이브러리 함수 및 상수 (예: RAND_MAX) 사용
#include <time.h>              // 시간 및 시계 함수를 사용하기 위한 헤더 (사용되지 않음)
#include <math.h>              // 수학 함수를 사용하기 위한 헤더 (사용되지 않음)
#include <string.h>  
#include <ctype.h>

#define SIZE 10

int main(void) {

    //입력받은 문자열을 저장하는 코드
    char password[SIZE] = { 0 };

    int check_lower, check_upper, check_digit;
    check_lower = check_upper = check_digit = 0;
    
    while(1){
        while(1){
        printf("암호를 생성하시오(6자리이상): ______\b\b\b\b\b\b");
        //scanf()는 공백이 있으면 공백 앞자리까지 저장하기 때문에
        //"%[^\n,\0]s"를 이용해 띄어쓰기나 엔터를 입력하면 그앞까지 저장
        scanf("%[^\0,\n]s", password);
            if(strlen(password)>6){
                break;
            }
            else{
                printf("6자리이상 입력해주세요'\n");
            }
        }
        for (int i = 0; i < strlen(password); i++) {
            if (islower(password[i])){
                check_lower = 1;
            }
            else if (isupper(password[i])){
                check_upper = 1;
            }
            else if (isdigit(password[i])){
                check_digit = 1;
            }
        }
        if (check_lower == 1 && check_upper == 1 && check_digit == 1) {
            printf("적정한 암호입니다.\n");
            break;
        }
        else {
            printf("숫자, 소문자, 대문자를 섞어서 암호를 다시 만드세요!\n");
        }
    }
    return 0;
}
