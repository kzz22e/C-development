#pragma warning(disable:4996)  // 특정 경고 메시지를 억제
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//기호상수 선언
#define NAME_SIZE 30
#define ITEM_SIZE 10
#define ITEM_LIST 10

//구조체 Inventory_Management 선언
struct Inventory_Management {
    char ITEM_name[NAME_SIZE];
    unsigned long ITEM_price;
    unsigned int ITEM_quantity;
};

int main(){
    
    //Y_STORE이라는 구조체 배열 선언
    struct Inventory_Management Y_STORE[ITEM_LIST];
    struct Inventory_Management* p = &Y_STORE;
    
    Save_Inventory_Management(&Y_STORE);
    
    
}

void Save_Inventory_Management(struct Inventory_Management* Y_STORE[]){
    
    for(int i = 0;i<ITEM_SIZE;I++){
        printf("상품명을 입력하세요 :");
        scanf("%s[^\n]s", *Y_STORE[i].ITEM_name);
    
        printf("");
        scanf("%s[^\n]ld", *Y_STORE[i].ITEM_price);
    
        printf("");
        scanf("%s[^\n]d", *Y_STORE[i].ITEM_quantity);
    }
}






