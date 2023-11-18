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
#define FIRST 1         //1
#define SECOND 2        //2
#define THIRD 3         //3
#define FOURTH 4        //4
#define FIFTH 5         //5

//================================================================================
// 매뉴를 함수로 표현
int Main_Menu();        //메인메뉴
int Inventory_Status(struct Inventory_Management Y_STORE[]);    //1.재고현황 메뉴
int Inventory(struct Inventory_Management Y_STORE[]);            //2.재고 관리 메뉴
int Inventory_Add(struct Inventory_Management Y_STORE[]);

//텍스트를 간단하게 출력하는 함수
void Print_Simple(char Text_list[]);    //간단하게 사용가능한 텍스트
void Print_Errer(char Text_list[]);     //에러 텍스트 모음
void Print_Menu(char Text_list[]);      //메뉴 텍스트 모음
void Print_Inventory_Management(struct Inventory_Management Y_STORE[], int sortType); //모든 재고 출력
void Print_Count_Inventory(struct Inventory_Management* Y_STORE, int repeat); //재고 횟수별 출력

//검사하는 함수
int Check_ITEM_name(char* str);                             //제품이름을 검사하는 함수
int compareStructs(const void* a, const void* b);           //구조체에서 ITEM_name을 비교하는 함수
int compareStructsByPrice(const void* a, const void* b);    //구조체에서 ITEM_price을 비교하는 함수
int Inventory_Search(struct Inventory_Management Y_STORE[]);  //재고를 이름으로 검색하는 함수
int Check_Inventory_LIST(struct Inventory_Management Y_STORE[], char checkITEM_name[], int Value);     //재고 유무 여부 채크 함수

//저장하는 함수
void SAVE_ITEM_priceORquantity(char* question, long* Input_value, char* errorMessage);
void ADD_ITEM_quantity(char* question, struct Inventory_Management* Y_STORE, char* errorMessage, int index); //추가 수량 입력받는 함수
//================================================================================

//새로운 자료형으로 구조체 선언
typedef struct Inventory_Management {
    char ITEM_name[NAME_SIZE];
    long ITEM_price;
    long ITEM_quantity;
}Inventory_Management;

//구조체에서 ITEM_name을 비교하는 함수 [이름순]
int compareStructs_name(const void* a, const void* b) {
    // a와 b를 각각 구조체 포인터로 캐스팅한 후, ITEM_name를 비교하여 반환
    //(struct Inventory_Management*) 구조체 포인터로 형변환
    return strcmp(((struct Inventory_Management*)a)->ITEM_name, ((struct Inventory_Management*)b)->ITEM_name);
}
//구조체에서 ITEM_price을 비교하는 함수 [상품가격순]
int compareStructs_price(const void* a, const void* b) {
    // a와 b를 각각 구조체 포인터로 캐스팅한 후, ITEM_price를 비교하여 반환
    //(struct Inventory_Management*) 구조체 포인터로 형변환
    return ((struct Inventory_Management*)a)->ITEM_price - ((struct Inventory_Management*)b)->ITEM_price;
}
//구조체에서 ITEM_quantity을 비교하는 함수 [상품수량순]
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
        {"mango", 55667, 22}
        //,{"pear", 77889, 17}
    };

    //Save_Inventory_Management(Y_STORE);

    Main_Menu(Y_STORE);

    return 0;
}

//메인메뉴
int Main_Menu(struct Inventory_Management Y_STORE[]) {
    short menu = 0;
    while(1){
        while(1){
            Print_Menu("메인 메뉴");
            scanf("%hd", &menu);
                if ((menu >= FIRST && menu <= FOURTH)) {
                    break;
                }
                Print_Errer("없는 메뉴입니다.");
        }
        //1. 재고 현황
        if (menu == FIRST) {
            while (1) { if (Inventory_Status(Y_STORE) == FOURTH) { break; } }
        }
        //2. 재고 관리
        else if (menu == SECOND) {
            while (1) { if (Inventory(Y_STORE) == FIFTH) { break; } }
        }
        //3. 종료
        else{
            return 0;
        }
    }
}

//1. 재고 현황 메뉴
int Inventory_Status(struct Inventory_Management Y_STORE[]){

    int i = 0;
    short sub_menu = 0;
    
    while (1) {
        Print_Menu("재고 현황");
        scanf("%hd", &sub_menu);

        if (sub_menu >= FIRST && sub_menu <= FOURTH) {
            break;
        }
        else {
            Print_Errer("없는 메뉴입니다.");
        }
    }
    if (sub_menu == FIRST) {
        //qsort함수는 오름차순 정렬기준
        qsort(Y_STORE, ITEM_LIST, sizeof(struct Inventory_Management), compareStructs_name);
        Print_Inventory_Management(Y_STORE,FIRST);
        return FIRST;
    }
    else if (sub_menu == SECOND) {
        //qsort함수는 오름차순 정렬기준
        qsort(Y_STORE, ITEM_LIST, sizeof(struct Inventory_Management), compareStructs_price);
        Print_Inventory_Management(Y_STORE, SECOND);
        return SECOND;
    }
    else if (sub_menu == THIRD) {
        //qsort함수는 오름차순 정렬기준
        qsort(Y_STORE, ITEM_LIST, sizeof(struct Inventory_Management), compareStructs_quantity);
        Print_Inventory_Management(Y_STORE, THIRD);
        return THIRD;
    }
    else if (sub_menu == FOURTH) {
        //메뉴 종료
        return FOURTH;
    }
    else {
        return 0;
    }
}

//2. 재고 관리 메뉴
int Inventory(struct Inventory_Management Y_STORE[]) {

    int i = 0;
    short sub_menu = 0;

    while (1) {
        Print_Menu("재고 관리");
        scanf("%hd", &sub_menu);
        if (sub_menu >= FIRST && sub_menu <= FIFTH) {
            break;
        }
        else {
            Print_Errer("없는 메뉴입니다.");
        }
    }
    //1. 재고 검색
    if (sub_menu == FIRST) {
        while (1) { while (getchar() != '\n'); if (Inventory_Search(Y_STORE) == 1) { break; } };
        return FIRST;
    }
    // 2. 재고 입고
    else if (sub_menu == SECOND) {
        while (1) { while (getchar() != '\n'); if (Inventory_Add(Y_STORE) == 1) { break; } };
        return SECOND;
    }
    // 3. 재고 출고
    else if (sub_menu == THIRD) {
        return THIRD;
    }
    // 4. 재고 삭제
    else if (sub_menu == FOURTH) {
        return FOURTH;
    }
    // 5. 메인 메뉴
    else if (sub_menu == FIFTH) {
        //메뉴 종료
        return FIFTH;
    }
    else {
        return 0;
    }
}

//2-1.재고 검색 메뉴
int Inventory_Search(struct Inventory_Management Y_STORE[]) {
    
    int i;
    int unknown = 0;
    char Search_ITEM_name[NAME_SIZE] = { "\0" };

    if(Check_Inventory_LIST(Y_STORE,"",1) != -1) {
        printf("재고의 이름을 입력해주세요 : ");
        scanf("%29[^\n]s", Search_ITEM_name);

        for(i=0;i<ITEM_LIST;i++){
            if (strcmp(Y_STORE[i].ITEM_name, Search_ITEM_name) == 0) {
                Print_Count_Inventory(Y_STORE, i);
            }
            else {
                unknown++;
            }
        }
        if (unknown == ITEM_LIST) {
            Print_Errer("없는 값입니다");
            return 0; //하나도 같은 문자가 없다면
        }
        else {
            return 1; //하나라도 같은 문자가 있다면
        }
    }
    else {
        Print_Errer("재고가 존재하지 않습니다.");
        return 1;
    }
}

//2-2.재고 입고 메뉴
int Inventory_Add(struct Inventory_Management Y_STORE[]) {

    int empty_list = 0;
    char ITEM_name[ITEM_SIZE] = { "\0" };

    while (1) {
        printf("재고의 이름을 입력해주세요 : ");
        scanf("%29[^\n]s", ITEM_name);
        if (Check_ITEM_name(ITEM_name) == 1) {
            break;
        }
        else {
            Print_Errer("영어, 숫자만 입력 가능합니다.");
        }
    }

    empty_list = Check_Inventory_LIST(Y_STORE, ITEM_name, 0);

    if (empty_list == -1 && Check_Inventory_LIST(Y_STORE, "", 0) != -1) {
        empty_list = Check_Inventory_LIST(Y_STORE, "", 0);
        Print_Simple("안내선");

        // 입력받은 값 저장하기
        strcpy(Y_STORE[empty_list].ITEM_name, ITEM_name);

        // 가격 입력받기
        SAVE_ITEM_priceORquantity("제품 가격을 입력하세요: ", &Y_STORE[empty_list].ITEM_price, "양의 숫자를 입력하세요.");

        // 수량 입력받기
        SAVE_ITEM_priceORquantity("제품 수량을 입력하세요: ", &Y_STORE[empty_list].ITEM_quantity, "양의 숫자를 입력하세요.");
        Print_Count_Inventory(Y_STORE, empty_list);
        Print_Simple("안내선");

        return 1;
    }
    else if (empty_list != -1) {
        Print_Errer("이미 추가된 재고입니다.");

        // 수량 입력받기
        ADD_ITEM_quantity("추가할 수량을 입력하세요: ", Y_STORE, "양의 숫자를 입력하세요.", empty_list);
        Print_Count_Inventory(Y_STORE, empty_list);
        return 1;
    }
    else {
        Print_Errer("더이상 저장할 공간이 없습니다");
        return 1;
    }
}



//메뉴 출력 함수
void Print_Menu(char Text_list[]) {
    
    //메인메뉴
    if (strcmp(Text_list, "메인 메뉴") == 0) {
        printf("____________________________________________\n");
        printf("[메인 메뉴]\n");
        printf("1. 재고 현황\n");
        printf("2. 재고 관리\n");
        printf("3. 종료\n");
        printf("____________________________________________\n");
    }
    //1. 재고 현황 메뉴
    else if (strcmp(Text_list, "재고 현황") == 0) {
        printf("____________________________________________\n");
        printf("[정렬 방식 선택]\n");
        printf("1. 제품 알파벳순 정렬\n");
        printf("2. 제품 가격순 정렬\n");
        printf("3. 제품 수량순 정렬\n");
        printf("4. 메인 메뉴\n");
        printf("____________________________________________\n");
    }
    //2. 재고 관리 메뉴
    else if (strcmp(Text_list, "재고 관리") == 0) {
        printf("____________________________________________\n");
        printf("[재고 관리 선택]\n");
        printf("1. 재고 검색\n");
        printf("2. 재고 입고\n");
        printf("3. 재고 출고\n");
        printf("4. 재고 삭제\n");
        printf("5. 메인 메뉴\n");
        printf("____________________________________________\n");
    }
}
//에러메시지 출력 함수
void Print_Errer(char Text_list[]) {
    printf("\n____________________경고____________________\n");

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
    else if (strcmp(Text_list, "없는 값입니다") == 0) {
        printf("\n\n없는 값입니다. 다시입력해주세요\n");
    }
    else if (strcmp(Text_list, "재고가 존재하지 않습니다.") == 0) {
        printf("\n\n재고가 존재하지 않습니다. 입고를 진행해주세요\n");
    }
    else if (strcmp(Text_list, "이미 추가된 재고입니다.") == 0) {
        printf("\n\n이미 추가된 재고입니다.\n");
    }
    else if (strcmp(Text_list, "더이상 저장할 공간이 없습니다") == 0) {
        printf("\n\n더이상 저장할 공간이 없습니다.\n");
        printf("\n\n재고 삭제 후 진행해주세요.\n");
    }
    printf("\n____________________________________________\n\n");
}
//간단텍스트 출력 함수
void Print_Simple(char Text_list[]) {
    if (strcmp(Text_list, "안내선") == 0) {
        printf("____________________________________________\n\n");
        return;
    }
}

//재고 유무 여부 채크 함수
int Check_Inventory_LIST(struct Inventory_Management Y_STORE[],char checkITEM_name[],int Value){
    int i;
    //checkITEM_name이 있는지 확인하는 값
    if(Value == 0){
        for (i = 0; i < ITEM_LIST; i++) {
            if (strcmp(Y_STORE[i].ITEM_name, checkITEM_name) == 0) {
                return i; //checkITEM_name 하나라도 존재한다면
            }
        }
        return -1; // 그렇지 않으면 -1을 반환합니다.
    }
    //인덱스가 하나라도 존재한다면
    else {
        for (i = 0; i < ITEM_LIST; i++) {
            if (strcmp(Y_STORE[i].ITEM_name, "\0") != 0) {
                return 0; //"\0"이 아닌값이 하나라도 있으면
            }
        }
        return -1; // 그렇지 않으면 -1을 반환합니다.
    }
}
//재고 이름을 입력받은 뒤 영어 알파벳, 숫자 여부를 확인하는 함수
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
//가격과 수량을 입력받아 유효한지 확인까지 수행하는 함수
void SAVE_ITEM_priceORquantity(char* question, long* Input_value, char* errorMessage) {
    while (1) {
        printf("%s", question);
        if (scanf("%ld", Input_value) == 1 && *Input_value > 0) {
            while (getchar() != '\n'); //버퍼 비우기
            break;
        }
        Print_Errer(errorMessage);
        while (getchar() != '\n');  //버퍼 비우기
    }
}

//추가 수량 입력받는 함수
void ADD_ITEM_quantity(char* question, struct Inventory_Management* Y_STORE, char* errorMessage,int index) {
    while (1) {
        long Input_value = 0;
        printf("%s", question);
        if (scanf("%ld", &Input_value) == 1 && Input_value > 0) {
            Y_STORE[index].ITEM_quantity += Input_value;
            while (getchar() != '\n'); //버퍼 비우기
            break;
        }
        Print_Errer(errorMessage);
        while (getchar() != '\n');  //버퍼 비우기
    }
}

//재고 현황을 출력하는 함수
void Print_Inventory_Management(struct Inventory_Management Y_STORE[],int sortType) {
    int i;
    if (sortType == FIRST) {
        printf("\n정렬방식 : 알파벳순 정렬\n\n");
    }
    else if (sortType == SECOND) {
        printf("\n정렬방식 : 가격순 정렬\n\n");
    }
    else if (sortType == THIRD) {
        printf("\n정렬방식 : 수량순 정렬\n\n");
    }
    else {
        printf("\n잘못된 값 입니다.\n\n");
    }
    for (i = 0; i < ITEM_LIST; i++){
        Print_Count_Inventory(Y_STORE,i);
    }
    
}
//count의 재고를 출력하는 함수
void Print_Count_Inventory(struct Inventory_Management *Y_STORE, int count) {
        Print_Simple("안내선");
        printf("[%d번 제품]\n", count);
        printf("제품명: %s\n", Y_STORE[count].ITEM_name);
        printf("제품 가격: %lu\n", Y_STORE[count].ITEM_price);
        printf("제품 수량: %u\n", Y_STORE[count].ITEM_quantity);
        Print_Simple("안내선");
}
