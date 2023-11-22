#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 10

typedef struct store {
    char name[max];
    int price;
    int quantity;
} product;

// 상품 검색
void search(product *products, int numpro, char *name) {
    for (int i = 0; i < numpro; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("%s : 가격 - %d , 재고 수 - %d개\n", products[i].name, products[i].price, products[i].quantity);
        }
    }
}

// 현재 재고 출력
void remain(product *products, int numpro) {
    printf("현재 재고 :\n");
    for (int i = 0; i < numpro; i++) {
        printf("%s : %d개", products[i].name, products[i].quantity);
    }
}

// 상품 추가 또는 입고
void add(product *products, int *numpro, char *name, int price, int quantity) {
    for (int i = 0; i < *numpro; i++) {
        if (strcmp(products[i].name, name) == 0) {
            products[i].quantity += quantity;
            printf("%s를 %d개 추가했습니다.\n", name, quantity);
            return;
        }
    }

    if (*numpro < max) {
        strcpy(products[*numpro].name, name);
        products[*numpro].price = price;
        products[*numpro].quantity = quantity;
        (*numpro)++;
        printf("%s를 %d개 등록했습니다.\n", name, quantity);
    } else {
        printf("더 이상 상품을 등록할 수 없습니다. 최대 개수에 도달했습니다.\n");
    }
}

// 상품 판매
void sell(product *products, int numpro, char *name, int quantity) {
    for (int i = 0; i < numpro; i++) {
        if (strcmp(products[i].name, name) == 0) {
            if (products[i].quantity >= quantity) {
                products[i].quantity -= quantity;
                printf("%d개의 %s를 판매했습니다.\n", quantity, name);
            } else {
                printf("재고가 부족합니다. 재고를 추가합니다.\n");
                add(products, &numpro, name, 0, quantity);
            }
            return;
        }
    }
    printf("해당 상품이 존재하지 않습니다.\n");
}

int main() {
    char name[max];
    int price, quantity;
    product products[max];
    int numpro = 0;

    for (int i = 0; i < 2; i++) {
        printf("상품 이름을 입력하세요 : ");
        scanf("%s", name);
        printf("상품 가격을 입력하세요 : ");
        scanf("%d", &price);

        printf("상품 개수를 입력하세요 : ");
        scanf("%d", &quantity);
        add(products, &numpro, name, price, quantity);
    }

    int choice;
    char checkname[max];
    int checkquantity;

    do {
        printf("\n1. 상품 판매\n");
        printf("2. 상품 입고\n");
        printf("3. 현재 재고 출력\n");
        printf("4. 상품 검색\n");
        printf("0. 종료\n");

        printf("원하는 작업을 선택하세요: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("판매할 상품 이름: ");
            scanf("%s", checkname);
            printf("판매할 수량: ");
            scanf("%d", &checkquantity);
            sell(products, numpro, checkname, checkquantity);
            break;
        case 2:
            printf("입고할 상품 이름: ");
            scanf("%s", checkname);
            printf("입고할 수량: ");
            scanf("%d", &checkquantity);
            add(products, &numpro, checkname, 0, checkquantity);
            break;
        case 3:
            remain(products, numpro);
            break;
        case 4:
            printf("검색할 상품 이름: ");
            scanf("%s", checkname);
            search(products, numpro, checkname);
            break;
        case 0:
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            printf("잘못된 선택입니다. 다시 선택해주세요.\n");
        }

    } while (choice != 0);

    return 0;
}