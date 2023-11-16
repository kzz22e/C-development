#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//상수 선언
#define NAME_SIZE 30
#define ITEM_SIZE 10
#define ITEM_LIST 10

//메뉴 번호 상수선언
#define FIRST 49        //1
#define SECOND 50       //2
#define THIRD 51        //3
#define FOURTH 52       //4

//================================================================================
// 매뉴를 함수로 표현
void Main_Menu();        //메인메뉴
int Inventory_Status(struct Inventory_Management Y_STORE[]); //1.재고현황 메뉴

//텍스트를 간단하게 출력하는 함수
void Print_Simple(char Text_list[]);    //간단하게 사용가능한 텍스트
void Print_Errer(char Text_list[]);     //에러 텍스트 모음
void Print_Menu(char Text_list[]);      // 메뉴 텍스트 모음
void Print_Inventory_Management(struct Inventory_Management Y_STORE[]); //재고 출력

//검사하는 함수
int Check_ITEM_name(char* str);                             //제품이름을 검사하는 함수
int compareStructs(const void* a, const void* b);           //구조체에서 ITEM_name을 비교하는 함수
int compareStructsByPrice(const void* a, const void* b);    //구조체에서 ITEM_price을 비교하는 함수

//저장하는 함수
void SAVE_ITEM_name(char* question, char* Input_value, int (*function)(char*), char* errorMessage);
void SAVE_ITEM_priceORquantity(char* question, long* Input_value, char* errorMessage);
void Save_Inventory_Management(struct Inventory_Management Y_STORE[]);
//================================================================================

//구조체 선언
typedef struct Inventory_Management {
    char ITEM_name[NAME_SIZE];
    long ITEM_price;
    long ITEM_quantity;
}Inventory_Management;

//구조체에서 ITEM_name을 비교하는 함수
int compareStructs_name(const void* a, const void* b) {
    // a와 b를 각각 구조체 포인터로 캐스팅한 후, ITEM_name를 비교하여 반환
    //(struct Inventory_Management*) 구조체 포인터로 형변환
    return strcmp(((struct Inventory_Management*)a)->ITEM_name, ((struct Inventory_Management*)b)->ITEM_name);
}
//구조체에서 ITEM_price을 비교하는 함수
int compareStructs_price(const void* a, const void* b) {
    // a와 b를 각각 구조체 포인터로 캐스팅한 후, ITEM_price를 비교하여 반환
    //(struct Inventory_Management*) 구조체 포인터로 형변환
    return ((struct Inventory_Management*)a)->ITEM_price - ((struct Inventory_Management*)b)->ITEM_price;
}
//구조체에서 ITEM_quantity을 비교하는 함수
int compareStructs_quantity(const void* a, const void* b) {
    // a와 b를 각각 구조체 포인터로 캐스팅한 후, ITEM_quantity를 비교하여 반환
    //(struct Inventory_Management*) 구조체 포인터로 형변환
    return ((struct Inventory_Management*)a)->ITEM_quantity - ((struct Inventory_Management*)b)->ITEM_quantity;
}


//프로그램 시작
int main() {
    Inventory_Management Y_STORE[ITEM_LIST] = {
        {"apple", 12345, 13},
        {"orange", 67890, 8},
        {"banana", 54321, 20},
        {"grape", 98765, 15},
        {"watermelon", 24680, 5},
        {"strawberry", 13579, 25},
        {"kiwi", 11223, 18},
        {"pineapple", 33445, 10},
        {"mango", 55667, 22},
        {"pear", 77889, 17}
    };

    //Save_Inventory_Management(Y_STORE);

    Main_Menu(Y_STORE);

    return 0;
}

//메인메뉴
void Main_Menu(struct Inventory_Management Y_STORE[]) {
    short menu = 0,sub_menu = 0;
    while(1){
        while(1){
            Print_Menu("메인 메뉴");
            menu = _getch();
                if ((menu >= FIRST && menu <= FOURTH)) {
                    break;
                }
                Print_Errer("없는 메뉴입니다.");
        }
        //1. 재고 현황
        while(1){
            if (menu == FIRST) {
                if (Inventory_Status(Y_STORE) == 4) { break; }
            }
        }
    }
}

//재고 현황 메뉴
int Inventory_Status(struct Inventory_Management Y_STORE[]){

    int i = 0;
    short sub_menu = 0;
    
    while (1) {
        Print_Menu("재고 현황");
        sub_menu = _getch();
        if ((sub_menu < FIRST || sub_menu > FOURTH)) {
            Print_Errer("없는 메뉴입니다.");
            break;
        }
    }
    printf("\n%d", sub_menu);
    if (sub_menu == FIRST) {
        //qsort함수는 오름차순 정렬기준
        qsort(Y_STORE, ITEM_LIST, sizeof(struct Inventory_Management), compareStructs_name);
        Print_Inventory_Management(Y_STORE);
        return 1;
    }
    else if (sub_menu == SECOND) {
        //qsort함수는 오름차순 정렬기준
        qsort(Y_STORE, ITEM_LIST, sizeof(struct Inventory_Management), compareStructs_price);
        Print_Inventory_Management(Y_STORE);
        return 2;
    }
    else if (sub_menu == THIRD) {
        qsort(Y_STORE, ITEM_LIST, sizeof(struct Inventory_Management), compareStructs_quantity);
        Print_Inventory_Management(Y_STORE);
        return 3;
    }
    else if (sub_menu == FOURTH) {
        return 4;
    }
    else {
        Print_Errer("없는 메뉴입니다.");
    }
}


//메뉴 출력 함수
void Print_Menu(char Text_list[]) {
    
    //메인메뉴
    if (strcmp(Text_list, "메인 메뉴") == 0) {
        printf("____________________________________________\n");
        printf("[메인 메뉴]\n");
        printf("1. 재고 현황\n");
        printf("2. 재고 검색\n");
        printf("3. 재고 관리\n");
        printf("4. 종료\n");
        printf("____________________________________________\n");
        return;
    }
    //1. 재고 현황 메뉴
    else if (strcmp(Text_list, "재고 현황") == 0) {
        printf("____________________________________________\n");
        printf("[정렬방식 선택]\n");
        printf("1. 제품 알파벳순 정렬\n");
        printf("2. 제품 가격순 정렬\n");
        printf("3. 제품 수량순 정렬\n");
        printf("4. 메인 메뉴\n");
        printf("____________________________________________\n");
        return;
    }
}
//에러메시지 출력 함수
void Print_Errer(char Text_list[]) {
    printf("\n\n\n\n\n____________________경고____________________\n");

    if (strcmp(Text_list, "영어, 숫자만 입력 가능합니다.") == 0) {
        printf("\n\n영어, 숫자만 입력 가능합니다.\n");
        printf("다시 입력해 주세요.\n");
    }
    else if (strcmp(Text_list, "양의 숫자를 입력하세요.") == 0) {
        printf("\n\n양의 숫자를 입력하세요.\n");
    }
    else if (strcmp(Text_list, "없는 메뉴입니다.") == 0) {
        printf("\n\n없는 메뉴입니다. 다시입력해주세요\n");
    }
    printf("\n____________________________________________\n\n\n\n\n\n");
}
//간단텍스트 출력 함수
void Print_Simple(char Text_list[]) {
    if (strcmp(Text_list, "안내선") == 0) {
        printf("____________________________________________\n\n");
        return;
    }
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

        Print_Errer(errorMessage);
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
        Print_Errer(errorMessage);
        getchar(); // 입력 버퍼 비우기
    }
}

//재고를 저장하는 함수
void Save_Inventory_Management(struct Inventory_Management Y_STORE[]) {
    for (int i = 0; i < ITEM_SIZE; i++) {

        Print_Simple("안내선");

        // 입력받기 함수 호출
        SAVE_ITEM_name("제품명을 입력하세요: ", Y_STORE[i].ITEM_name, Check_ITEM_name, "영어, 숫자만 입력 가능합니다.");

        // 가격 입력받기
        SAVE_ITEM_priceORquantity("제품 가격을 입력하세요: ", &Y_STORE[i].ITEM_price, "양의 숫자를 입력하세요.");

        // 수량 입력받기
        SAVE_ITEM_priceORquantity("제품 수량을 입력하세요: ", &Y_STORE[i].ITEM_quantity, "양의 숫자를 입력하세요.");

        Print_Simple("안내선");
    }
}

//재고를 출력하는 함수
void Print_Inventory_Management(struct Inventory_Management Y_STORE[]) {
    int i;
    for (i = 0; i < ITEM_SIZE; i++) {
        printf("[%d번 제품]\n", i);
        printf("제품명: %s\n", Y_STORE[i].ITEM_name);
        printf("제품 가격: %lu\n", Y_STORE[i].ITEM_price);
        printf("제품 수량: %u\n\n", Y_STORE[i].ITEM_quantity);
    }
}
