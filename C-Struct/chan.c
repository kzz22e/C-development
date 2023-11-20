#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10
// 제품의정보를 표현 구조체
typedef struct store {  
	char name[max]; // 제품의 이름을 입력받을 함수
	int price;      // 제품의 가격을 입력받을 함수
	int quantity;   // 제품의 양을 입력받을 함수
}product;
	
//편의점정보를 표현 구조체
typedef struct { 
	product products[max];
	int numpro; //등록된 상품의 수
}constore;
// 상품을 검색하는 기능의 함수
void search(constore *store, char *name) { 
	for (int i = 0; i < store->numpro; i++) {
		if (strcmp(store->products[i].name, name) == 0) { //포인터를 사용하여 검색한 제품이 편의점 구조체 배열에 존재할경우 
			printf("%s : 가격 - %d , 재고 수 - %d개\n", store->products[i].name, store->products[i].price, store->products[i].quantity);
		}   // 검색된 제품을 포인터를 사용해서 출력한다
	}
}
// 제품의 재고를 알려주는 기능을 하는 함수
void remain(constore *store) { 
	printf("현재 재고 :\n");
    for (int i = 0; i < store->numpro; i++) { // 처음엔 max까지 반복하게 진행하였더니 글자가 깨지는 오류가 발생하여 포인터를 사용하여 제품의 수만큼 반복하게 고침
        printf("%s : %d개", store->products[i].name, store->products[i].quantity); //포인터를 사용해서 찾고있는 제품의 이름과 양을 받음
    }
    return;
        
}
// 재고가 부족할시 추가시켜주는 함수
void add(constore* store, char* name, int price, int quantity) {
    for (int i = 0; i < store->numpro; i++) {
        if (strcmp(store->products[i].name, name) == 0) { //제품목록에 존재하는 상품인지 아닌지를 확인하는 if문
            store->products[i].quantity += quantity;  // 기존 수량을 초기값으로 설정
            printf("%s를 %d개추가했습니다.\n", name, quantity);
            return;
        }
    }
    //재고를 등록시켜줌
     if (store->numpro < max) { //최대로 등록 가능한 수보다 적게 등록되어있는 상태라면 
        strcpy(store->products[store->numpro].name, name); 
        store->products[store->numpro].price = price;
        store->products[store->numpro].quantity = quantity;
        store->numpro++; 
        printf("%s를 %d개 등록했습니다.\n", name, quantity);
    } else {
        printf("더 이상 상품을 등록할 수 없습니다. 최대 개수에 도달했습니다.\n");
        return;
    }
}
// 상품을 판매할때 원하는 개수만큼 빼주는 함수
void sell(constore *store, char *name, int quantity) {
    for (int i = 0; i < store->numpro; i++) {
        if (strcmp(store->products[i].name, name) == 0) { // 제품목록에 존재하는 상품인지 아닌지를 확인하는 if문
            if (store->products[i].quantity >= quantity) { // 현재 제품의 양이 입력받은 양보다 많이 남아있는지 확인하는 2중 if문 
                store->products[i].quantity -= quantity;  // 제품목록에 존재하고 입력받은 양보다 남은 양이 많을시 뺀다
                printf("%d개의 %s를 판매했습니다.\n", quantity, name); //본래의 양에서 뺀것을 출력함
            }
            else {
                printf("재고가 부족합니다. 재고를 추가합니다.\n"); //재고 목록에는 존재하지만 양이 부족시 재고가 부족하다고 알림
                add(store, name,0,quantity); //재고 부족 시 추가 함수 호출
            }
            return; 
        }
    }
    printf("해당 상품이 존재하지 않습니다.\n"); // 제품목록에도 존재하지 않을시 상품이 존재하지않는다고 알림
}
// 시작
int main() {
    // 상품의 정보들을 입력받을 변수
    char name[max]; 
    int price, quantity;
	constore store;
	store.numpro = 0;
    
    // 10개의 상품들의 정보를 입력받는다.
    for (int i = 0; i < 2; i++) {
        printf("상품 이름을 입력하세요 : ");
        scanf("%s", name);
        printf("상품 가격을 입력하세요 : ");
        scanf("%d", &price);
        
        printf("상품 개수를 입력하세요 : ");
        scanf("%d", &quantity);
        add(&store, name, price, quantity);
    }
    int choice;
    // 위에서 입력받은 함수와 같은지 확인 및 작업을 위한변수 
    char checkname[max];
    int checkquantity;
    do {
        // 메뉴얼
        printf("\n1. 상품 판매\n");
        printf("2. 상품 입고\n");
        printf("3. 현재 재고 출력\n");
        printf("4. 상품 검색\n");
        printf("0. 종료\n");
        // 원하는 작업을 입력받는다
        printf("원하는 작업을 선택하세요: ");
        scanf("%d",&choice);
        switch (choice) { //switch문을 사용해서 메뉴얼에 번호에 맞게 실행
        case 1:
            // 상품 판매
            printf("판매할 상품 이름: ");
            scanf("%s",checkname);
            printf("판매할 수량: ");
            scanf("%d",&checkquantity);
            sell(&store, checkname, checkquantity);
            break;
        case 2:
            // 상품 입고
            printf("입고할 상품 이름: ");
            scanf("%s",checkname);
            printf("입고할 수량: ");
            scanf("%d",&checkquantity);
            add(&store, checkname,0,checkquantity); //입고 함수,입고시 가격은 필요하지 않기에 price는 0으로 넘긴다
            break;
        case 3:
            // 현재 재고 출력
            remain(&store); //현재 재고 확인 함수
            break;
        case 4:
            // 상품 검색
            printf("검색할 상품 이름: ");
            scanf("%s", checkname);
            search(&store, checkname); //상품 검색 함수
            break;
        case 0:
            // 종료
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            // 잘못된 선택
            printf("잘못된 선택입니다. 다시 선택해주세요.\n"); //잘못된 선택을 할시 출력하고 다시 반복
        }
        // 0 이 입력될시 반복을 종료한다
    } while (choice != 0);
}