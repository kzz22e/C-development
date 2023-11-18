#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>

//상수 선언
#define NAME_SIZE 30
#define ITEM_SIZE 10
#define ITEM_LIST 10

//구조체 선언
struct Inventory_Management {
    char ITEM_name[NAME_SIZE];
    unsigned long ITEM_price;
    unsigned int ITEM_quantity;
};

//재고를 저장하는 함수
void Save_Inventory_Management(struct Inventory_Management Y_STORE[]) {
    char Text_Print[100] = { 0 };
    for (int i = 0; i < ITEM_SIZE; i++) {

        while(1){
            printf("제품명을 입력하세요: ");
            scanf("%29[^\n]", Y_STORE[i].ITEM_name);
                if (Check_ITEM_name_UTF8(Y_STORE[i].ITEM_name)==1) {
                    break;
                }
                strcpy(Text_Print, "한글, 영어, 숫자만 가능");
                Text_Print_list(Text_Print);

        }
        while (1) {
            printf("제품 가격을 입력하세요: ");
            scanf("%lu", &Y_STORE[i].ITEM_price);
                if (Y_STORE[i].ITEM_price > 0) {
                    break;
                }
                
        }

        while (1) {
            printf("제품 수량을 입력하세요: ");
            scanf("%u", &Y_STORE[i].ITEM_quantity);
        }

    }
}
//텍스트 출력 저장
void Text_Print_list(const char *Text_list) {
    if (strcmp(*Text_list, "한글, 영어, 숫자만 가능")) {
        printf("===============주의===============\n");
        printf("한글, 영어, 숫자만 입력가능합니다.\n");
        printf("다시 입력해 주세요.\n");
        printf("===============주의===============\n");
    }
    else if{

    }
}

//재고를 출력하는 함수
void Print_Inventory_Management(const struct Inventory_Management Y_STORE[]) {
    for (int i = 0; i < ITEM_SIZE; i++) {
        printf("제품명: %s\n", Y_STORE[i].ITEM_name);
        printf("제품 가격: %lu\n", Y_STORE[i].ITEM_price);
        printf("제품 수량: %u\n\n", Y_STORE[i].ITEM_quantity);
    }
}

// UTF-8 문자열에서 한글, 영어 알파벳, 숫자 여부를 확인하는 함수
int Check_ITEM_name_UTF8(const char* str) {

    // 문자열 처음부터 널문자까지 반복해서 확인한다.
    while (*str != '\0') {
        // 와이드 문자를 저장하기 위한 변수를 선언하는 부분
        wchar_t wchar;
        // mbtowc 함수는 멀티바이트 문자열에서 와이드 문자로 변환하는 함수입니다.
        // 즉 멀티바이트 문자열(str)을 와이드 문자로 (wchar)에 변환하겠다는 의미입니다.
        // 함수 형식 : int mbtowc(wchar_t *pwc, const char *s, size_t n);
        // wchar_t *pwc : 변환된 와이드 문자가 저장될 포인터입니다.
        // const char *s : 변환할 멀티바이트 문자열의 포인터입니다.
        // size_t n : 변환할 최대 바이트 수입니다.
        int result = mbtowc(&wchar, str, MB_CUR_MAX);

        // mbtowc 함수는 다중 바이트 문자열을 와이드 문자로 변환하는데, 이때 변환 중에 문제가 발생하면 반환값으로 -1을 돌려줍니다.
        // 이 코드에서 result == -1은 mbtowc 함수의 변환에 실패했다는 것을 의미합니다.
        // 이는 주로 잘못된 UTF-8 형식의 문자열이 들어왔을 때 발생할 수 있습니다.
        if (result == -1) {
            // 잘못된 UTF-8 형식
            return 0;
        }

        // 한글, 영어 알파벳, 숫자 여부 확인
        if ((wchar >= 0xAC00 && wchar <= 0xD7A3) || // 한글확인
            (wchar >= L'A' && wchar <= L'Z') || (wchar >= L'a' && wchar <= L'z') || // 영어확인
            (wchar >= L'0' && wchar <= L'9')) { // 숫자확인
            return 1; // 한글, 영어 알파벳, 숫자 중 하나라도 있으면 1 반환
        }

        str += result;
    }

    return 0; // 모든 문자가 한글, 영어 알파벳, 숫자가 아닐 경우
}

//프로그램 시작
int main() {
    struct Inventory_Management Y_STORE[ITEM_LIST];

    // Save_Inventory_Management 함수를 호출하여 데이터를 입력합니다.
    Save_Inventory_Management(Y_STORE);

    // 입력한 내용을 출력합니다.
    Print_Inventory_Management(Y_STORE);

    return 0;
}