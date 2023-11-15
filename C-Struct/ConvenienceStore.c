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