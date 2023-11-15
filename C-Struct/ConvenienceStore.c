#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NAME_SIZE 30
#define ITEM_SIZE 10
#define ITEM_LIST 10

struct Inventory_Management {
    char ITEM_name[NAME_SIZE];
    unsigned long ITEM_price;
    unsigned int ITEM_quantity;
};
//재고를 저장하는 함수
void Save_Inventory_Management(struct Inventory_Management Y_STORE[]) {
    for (int i = 0; i < ITEM_SIZE; i++) {
        printf("제품명을 입력하세요: ");
        scanf("%29[^\n]", Y_STORE[i].ITEM_name);
        
        printf("제품 가격을 입력하세요: ");
        scanf("%lu", &Y_STORE[i].ITEM_price);

        printf("제품 수량을 입력하세요: ");
        scanf("%u", &Y_STORE[i].ITEM_quantity);
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
//입력받은 값이 한글인지 확인
int Check_ITEM_name(){
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

// 한글 여부를 확인하는 함수 
int isKorean(unsigned int codepoint) {
    //유니코드 한글 코드표 참조
    //https://namu.wiki/w/현대%20한글의%20모든%20글자/유니코드
    return (codepoint >= 0xAC00 && codepoint <= 0xD7A3);
}

#include <stdio.h>
#include <string.h>

// 한글 여부를 확인하는 함수
int isKorean(const char* str) {
    unsigned char firstByte = (unsigned char)str[0];

    // 한글은 UTF-8에서 3바이트로 인코딩되므로 첫 번째 바이트의 패턴을 확인
    if ((firstByte & 0xE0) == 0xE0) {
        // 두 번째 바이트의 패턴도 확인
        if ((str[1] & 0xC0) == 0x80 && (str[2] & 0xC0) == 0x80) {
            return 1;  // UTF-8로 인코딩된 한글
        }
    }

    return 0;  // 한글이 아닌 경우
}

// 문자열에 포함된 모든 문자가 한글인지 확인하는 함수
int allCharactersKorean(const char* str) {
    while (*str) {
        if (!isKorean(str)) {
            return 0;  // 한 글자라도 한글이 아니면 0을 반환
        }

        // 다음 문자로 이동
        str += ((*str & 0xE0) == 0xE0) ? 3 : 1;
    }

    return 1;  // 문자열의 모든 문자가 한글이면 1을 반환
}