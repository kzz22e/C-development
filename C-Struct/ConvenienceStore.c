#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//상수 선언
#define NAME_SIZE 30
#define ITEM_SIZE 10
#define ITEM_LIST 10

//================================================================================
void Text_Print_list(char Text_list[]);

//검사하는 함수
int Check_ITEM_name(char* str);

//저장하는 함수
void SAVE_ITEM_name(char* question, char* Input_value, int (*function)(char*), char* errorMessage);
void SAVE_ITEM_priceORquantity(char* question, long* Input_value, char* errorMessage);
void Save_Inventory_Management(struct Inventory_Management Y_STORE[]);

//입력받은값 출력확인
void Print_Inventory_Management(const struct Inventory_Management Y_STORE[]);

//================================================================================

//구조체 선언
struct Inventory_Management {
    char ITEM_name[NAME_SIZE];
    long ITEM_price;
    long ITEM_quantity;
};

//프로그램 시작
int main() {
    struct Inventory_Management Y_STORE[ITEM_LIST];

    // Save_Inventory_Management 함수를 호출하여 데이터를 입력합니다.
    Save_Inventory_Management(Y_STORE);

    // 입력한 내용을 출력합니다.
    Print_Inventory_Management(Y_STORE);

    return 0;
}

//텍스트 출력 저장
void Text_Print_list(char Text_list[]) {

    //안내선 출력
    if (strcmp(Text_list, "안내선") == 0) {
        printf("____________________________________________\n\n");
        return;
    }

    //경고 문자 출력
    printf("\n\n\n\n\n____________________경고____________________\n");
    if (strcmp(Text_list, "영어, 숫자만 입력 가능합니다.") == 0) {
        printf("\n\n영어, 숫자만 입력 가능합니다.\n");
        printf("다시 입력해 주세요.\n");
    }
    else if (strcmp(Text_list, "양의 숫자를 입력하세요.") == 0) {
        printf("\n\n양의 숫자를 입력하세요.\n");
    }
    printf("\n____________________________________________\n\n\n\n\n\n");

}

//영어 알파벳, 숫자 여부를 확인하는 함수
int Check_ITEM_name(char* str) {

    // 문자열 처음부터 널문자까지 반복해서 확인한다.
    while (*str != '\0') {

        // 현재 문자가 알파벳 또는 숫자가 아니면서 개행 문자도 아닌 경우
        if (!isalnum(*str) && *str != '\n' && *str != '\r') {
            return 0; // 특수문자가 있으면 0 반환
        }
        str++;
    }
    return 1; // 특수문자가 없으면 1 반환
}

//매개변수에 함수의 포인터를 추가해 보다 함수를 이용해 함수를 사용할 수 있게 했습니다
//값을 입력받은 뒤 함수로 검사한 뒤 저장한다
void SAVE_ITEM_name(char* question, char* Input_value, int (*function)(char*), char* errorMessage) {
    while (1) {

        printf("%s", question);
        scanf("%29[^\n]s", Input_value);
        getchar(); // Enter 키 제거

        if (function(Input_value) == 1) {
            break;
        }

        Text_Print_list(errorMessage);
    }
}

// 입력받고 유효한지 확인까지 수행하는 함수
void SAVE_ITEM_priceORquantity(char* question, long* Input_value, char* errorMessage) {
    while (1) {
        printf("%s", question);
        if (scanf("%ld", Input_value) == 1 && *Input_value > 0) {
            getchar(); // Enter 키 제거
            break;
        }
        Text_Print_list(errorMessage);
        getchar(); // 입력 버퍼 비우기
    }
}

//재고를 저장하는 함수
void Save_Inventory_Management(struct Inventory_Management Y_STORE[]) {
    for (int i = 0; i < ITEM_SIZE; i++) {

        Text_Print_list("안내선");

        // 입력받기 함수 호출
        SAVE_ITEM_name("제품명을 입력하세요: ", Y_STORE[i].ITEM_name, Check_ITEM_name, "영어, 숫자만 입력 가능합니다.");

        // 가격 입력받기
        SAVE_ITEM_priceORquantity("제품 가격을 입력하세요: ", &Y_STORE[i].ITEM_price, "양의 숫자를 입력하세요.");

        // 수량 입력받기
        SAVE_ITEM_priceORquantity("제품 수량을 입력하세요: ", &Y_STORE[i].ITEM_quantity, "양의 숫자를 입력하세요.");

        Text_Print_list("안내선");
    }
}

//재고를 출력하는 함수
void Print_Inventory_Management(struct Inventory_Management Y_STORE[]) {
    int i;
    for (i = 0; i < ITEM_SIZE; i++) {
        printf("제품명: %s\n", Y_STORE[i].ITEM_name);
        printf("제품 가격: %lu\n", Y_STORE[i].ITEM_price);
        printf("제품 수량: %u\n\n", Y_STORE[i].ITEM_quantity);
    }
}

