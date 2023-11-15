#pragma warning(disable:4996)  // 특정 경고 메시지를 억제
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//기호상수 선언
#define NAME_SIZE 30
#define ITEM_SIZE 10
#define QUANTITY 3000

//구조체 재고관리 선언
struct Inventory_Management {
    char ITEM_name[NAME_SIZE];
    unsigned long ITEM_price;
    unsigned int ITEM_QUANTITY;
};
