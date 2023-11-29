#include <stdio.h>

void SaveInventoryToFile(Inventory_Management* Y_STORE) {
    FILE* file = fopen("재고데이터.txt", "w"); // 텍스트 모드로 쓰기 위해 파일 열기

    if (file != NULL) {
        // 헤더 쓰기
        fprintf(file, "\t상품이름\t|\t제품가격\t|\t제품수량\t|\n");
        
        for (int i = 0; i < ITEM_LIST; i++) {
            fprintf(file, "%s\t|\t%ld\t|\t%ld\n", Y_STORE[i].ITEM_name, Y_STORE[i].ITEM_price, Y_STORE[i].ITEM_quantity);
        }

        fclose(file);
    } else {
        printf("파일을 쓰기 위해 열 수 없습니다.\n");
    }
}
void LoadInventoryFromFile(Inventory_Management* Y_STORE) {
    FILE* file = fopen("재고데이터.txt", "r"); // 텍스트 모드로 읽기 위해 파일 열기

    if (file != NULL) {
        // 헤더 읽기
        char header[256];
        fscanf(file, "%[^\n]\n", header);
        printf("%s\n", header); // 헤더 출력

        for (int i = 0; i < ITEM_LIST; i++) {
            if (fscanf(file, "%s\t|\t%ld\t|\t%ld\n", Y_STORE[i].ITEM_name, &Y_STORE[i].ITEM_price, &Y_STORE[i].ITEM_quantity) != 3) {
                printf("파일에서 데이터를 읽는 중 오류가 발생했습니다.\n");
                break;
            }
        }

        fclose(file);
    } else {
        printf("파일을 읽기 위해 열 수 없습니다.\n");
    }
}