#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

//상수 선언
#define NAME_SIZE 30
#define ITEM_SIZE 10
#define ITEM_LIST 10    

//새로운 자료형으로 구조체 선언
typedef struct Inventory_Management {
    char ITEM_name[NAME_SIZE];
    long ITEM_price;
    long ITEM_quantity;
}Inventory_Management;

//열거형으로 메뉴 번호 설정
enum Menu_Options {
    FIRST = 1,
    SECOND,
    THIRD,
    FOURTH,
    FIFTH
};

//================================================================================

// 매뉴를 함수로 표현
int Menu_Main();                                                                //메인메뉴
int Menu_Inventory_Status(Inventory_Management* Y_STORE);                       //1.재고현황 메뉴
int Menu_Inventory(Inventory_Management* Y_STORE);                              //2.재고 관리 메뉴
int Menu_Inventory_Search(Inventory_Management* Y_STORE);                       //2-1.재고 검색 메뉴
int Menu_Inventory_Add(Inventory_Management* Y_STORE);                          //2-2.재고 입고 메뉴
int Menu_Inventory_Take(Inventory_Management* Y_STORE);                         //2-3.재고 출고 메뉴
int Menu_Inventory_Delete(Inventory_Management* Y_STORE);                       //2-4.재고 삭제 메뉴    

//텍스트를 간단하게 출력하는 함수
void Print_Menu(char Text_list[]);                                                      //메뉴 출력문 모음
void Print_Errer(char Text_list[]);                                                     //에러 출력문 모음
void Print_Simple(char Text_list[]);                                                    //자주 사용하는 출력문
void Print_Inventory_Management(Inventory_Management* Y_STORE, int sortType);           //모든 재고 출력
void Print_Count_Inventory(Inventory_Management* Y_STORE, int repeat);                  //특정 재고 출력

//검사하는 함수
int Check_ITEM_name(char* str);                                                                     //재고 이름 허용성 검사
int Check_Inventory_LIST(Inventory_Management* Y_STORE, char checkITEM_name[], int Value);         //재고 유무 여부 체크 함수
int compareStructs_name(const void* a, const void* b);                                              //[상품이름순]
int compareStructs_price(const void* a, const void* b);                                             //[상품가격순]
int compareStructs_quantity(const void* a, const void* b);                                          //[상품수량순]

//저장하는 함수
int GetValid_ITEM_Name(char itemname[]);                                                                        //재고의 이름을 입력받아 저장하는 함수
void SAVE_ITEM_priceORquantity(char* question, long* Input_value, char* errorMessage);                          //가격과,수량 받아 검사하는 함수
void ADD_ITEM_quantity(char* question, Inventory_Management* Y_STORE, char* errorMessage, int index);           //입고 수량 입력받는 함수
void TAKE_ITEM_quantity(char* question, Inventory_Management* Y_STORE, char* errorMessage, int index);          //출고 수량 입력받는 함수
int DELETE_Inventory(Inventory_Management* Y_STORE, char* errorMessage, char ITEM_name[]);                      //재고를 삭제하는 함수
void SaveInventory_File(Inventory_Management* Y_STORE);                                                         //파일을 생성하고 배열값을 파일에 저장
void LoadInventory_File(Inventory_Management* Y_STORE);                                                         //파일을 불러와서 배열에 저장 

//================================================================================


//프로그램 시작 함수
int main() {
    Inventory_Management Y_STORE[ITEM_LIST] = {
        {"", 0, 0}
    };
    LoadInventory_File(Y_STORE);
   
    Menu_Main(Y_STORE);

    SaveInventory_File(Y_STORE);

    return 0;
}


//메뉴 관련 함수------------------------------------------------------------------------------------------------------


// 메인 메뉴 함수
int Menu_Main(Inventory_Management* Y_STORE) {
    // 메뉴 옵션 변수 선언 및 초기화
    enum Menu_Options menu = 0;

    // 사용자가 종료를 선택할 때까지 메인 메뉴를 반복적으로 표시하는 루프
    while (1) {
        // 사용자로부터 유효한 메뉴 옵션을 얻기 위한 루프
        while (1) {
            // 메인 메뉴를 표시
            Print_Menu("메인 메뉴");
            scanf("%d", &menu);

            // 입력된 메뉴 옵션이 유효한지 확인
            if ((menu >= FIRST && menu <= FOURTH)) {
                break;
            }

            // 유효하지 않은 메뉴 옵션에 대한 오류 메시지 표시
            Print_Errer("없는 메뉴입니다.");
        }

        // 선택된 메뉴 옵션에 따라 동작 수행
        // 1. 사용자가 "재고 현황"을 선택한 경우
        if (menu == FIRST) {
            while (1) {
                // 재고 현황 메뉴 함수를 호출하고 사용자가 종료를 선택했는지 확인
                if (Menu_Inventory_Status(Y_STORE) == FOURTH) {
                    break;
                }
            }
        }
        // 2. 사용자가 "재고 관리"를 선택한 경우
        else if (menu == SECOND) {
            while (1) {
                // 재고 관리 메뉴 함수를 호출하고 사용자가 종료를 선택했는지 확인
                if (Menu_Inventory(Y_STORE) == FIFTH) {
                    break;
                }
            }
        }
        // 3. 사용자가 "종료"를 선택한 경우
        else {
            // 프로그램 종료
            return 0;
        }
    }

    // 함수를 종료하기 전에 콘솔 화면을 지웁니다.
    system("cls");
}

// 1. 재고 현황 메뉴 함수
int Menu_Inventory_Status(Inventory_Management* Y_STORE) {

    // 서브 메뉴 옵션 변수 선언 및 초기화
    enum Menu_Options sub_menu = 0;

    // 루프 제어 변수
    int i = 0;

    // 사용자가 유효한 서브 메뉴 옵션을 선택할 때까지 반복
    while (1) {
        // 재고 현황 메뉴를 표시
        Print_Menu("재고 현황");
        scanf("%d", &sub_menu);

        // 선택된 서브 메뉴 옵션이 유효한지 확인
        if (sub_menu >= FIRST && sub_menu <= FOURTH) {
            break;
        }
        else {
            // 유효하지 않은 메뉴 옵션에 대한 오류 메시지 표시
            Print_Errer("없는 메뉴입니다.");
        }
    }

    // 콘솔 화면 지우기
    system("cls");

    // 서브 메뉴 옵션에 따라 동작 수행
    if (sub_menu == FIRST) {
        // qsort 함수를 사용하여 재고를 오름차순으로 정렬 ([이름순] 기준)
        qsort(Y_STORE, ITEM_LIST, sizeof(struct Inventory_Management), compareStructs_name);
        // 정렬된 재고를 출력
        Print_Inventory_Management(Y_STORE, FIRST);
        return FIRST;
    }
    else if (sub_menu == SECOND) {
        // qsort 함수를 사용하여 재고를 오름차순으로 정렬 ([가격순] 기준)
        qsort(Y_STORE, ITEM_LIST, sizeof(struct Inventory_Management), compareStructs_price);
        // 정렬된 재고를 출력
        Print_Inventory_Management(Y_STORE, SECOND);
        return SECOND;
    }
    else if (sub_menu == THIRD) {
        // qsort 함수를 사용하여 재고를 오름차순으로 정렬 ([수량순] 기준)
        qsort(Y_STORE, ITEM_LIST, sizeof(struct Inventory_Management), compareStructs_quantity);
        // 정렬된 재고를 출력
        Print_Inventory_Management(Y_STORE, THIRD);
        return THIRD;
    }
    else if (sub_menu == FOURTH) {
        // 메뉴 종료
        return FOURTH;
    }
    else {
        // 기타 예외 상황 처리
        return 0;
    }
}

// 2. 재고 관리 메뉴 함수
int Menu_Inventory(Inventory_Management* Y_STORE) {

    // 서브 메뉴 옵션 변수 선언 및 초기화
    enum Menu_Options sub_menu = 0;

    // 루프 제어 변수
    int i = 0;

    // 사용자가 유효한 서브 메뉴 옵션을 선택할 때까지 반복
    while (1) {
        // 재고 관리 메뉴를 표시
        Print_Menu("재고 관리");
        scanf("%d", &sub_menu);

        // 선택된 서브 메뉴 옵션이 유효한지 확인
        if (sub_menu >= FIRST && sub_menu <= FIFTH) {
            break;
        }
        else {
            // 유효하지 않은 메뉴 옵션에 대한 오류 메시지 표시
            Print_Errer("없는 메뉴입니다.");
        }
    }

    // 콘솔 화면 지우기
    system("cls");

    // 서브 메뉴 옵션에 따라 동작 수행
    // 1. 재고 검색
    if (sub_menu == FIRST) {
        // 사용자로부터 엔터 입력을 받고, 검색 메뉴 함수 호출
        while (1) { while (getchar() != '\n'); if (Menu_Inventory_Search(Y_STORE) == 1) { break; } };
        return FIRST;
    }
    // 2. 재고 입고
    else if (sub_menu == SECOND) {
        // 사용자로부터 엔터 입력을 받고, 입고 메뉴 함수 호출
        while (1) { while (getchar() != '\n'); if (Menu_Inventory_Add(Y_STORE) == 1) { break; } };
        return SECOND;
    }
    // 3. 재고 출고
    else if (sub_menu == THIRD) {
        // 사용자로부터 엔터 입력을 받고, 출고 메뉴 함수 호출
        while (1) { while (getchar() != '\n'); if (Menu_Inventory_Take(Y_STORE) == 1) { break; } };
        return THIRD;
    }
    // 4. 재고 삭제
    else if (sub_menu == FOURTH) {
        // 사용자로부터 엔터 입력을 받고, 삭제 메뉴 함수 호출
        while (1) { while (getchar() != '\n'); if (Menu_Inventory_Delete(Y_STORE) == 1) { break; } };
        return FOURTH;
    }
    // 5. 메인 메뉴
    else if (sub_menu == FIFTH) {
        // 메뉴 종료
        return FIFTH;
    }
    else {
        // 기타 예외 상황 처리
        return 0;
    }
}

// 2-1. 재고 검색 메뉴 함수
int Menu_Inventory_Search(Inventory_Management* Y_STORE) {
    int i;
    int unknown = 0;  // 검색 결과가 없는 경우를 확인하기 위한 변수
    char Search_ITEM_name[NAME_SIZE] = { "\0" };  // 검색할 아이템 이름을 저장할 변수

    // 재고 목록이 존재하는지 확인
    if (Check_Inventory_LIST(Y_STORE, "", 1) != -1) {
        // 사용자로부터 유효한 아이템 이름을 입력 받음
        GetValid_ITEM_Name(Search_ITEM_name);

        // 입력받은 아이템 이름과 일치하는 항목을 찾아 출력
        for (i = 0; i < ITEM_LIST; i++) {
            if (strcmp(Y_STORE[i].ITEM_name, Search_ITEM_name) == 0) {
                Print_Count_Inventory(Y_STORE, i);
            }
            else {
                unknown++;  // 일치하는 아이템이 없는 경우 카운트 증가
            }
        }

        // 모든 아이템이 검색 결과에 포함되지 않았을 경우
        if (unknown == ITEM_LIST) {
            Print_Errer("없는 값입니다.");
            return 0;  // 일치하는 아이템이 하나도 없음
        }
        else {
            return 1;  // 일치하는 아이템이 하나라도 있음
        }
    }
    else {
        // 재고가 존재하지 않는 경우 오류 메시지 출력
        Print_Errer("재고가 존재하지 않습니다.");
        return 1;
    }
}

// 2-2. 재고 입고 메뉴 함수
int Menu_Inventory_Add(Inventory_Management* Y_STORE) {
    int empty_list = 0;  // 빈 재고 목록의 인덱스를 저장할 변수
    char ITEM_name[ITEM_SIZE] = { "\0" };  // 입력받을 아이템 이름을 저장할 변수

    // 빈 재고 목록이 있는지 확인
    if (Check_Inventory_LIST(Y_STORE, "", 0) != -1) {
        // 유효한 아이템 이름을 입력받음
        GetValid_ITEM_Name(ITEM_name);

        // 입력받은 아이템 이름으로 빈 재고 목록 확인
        empty_list = Check_Inventory_LIST(Y_STORE, ITEM_name, 0);

        // 빈 재고 목록이 없고 전체 재고 목록이 존재하는 경우
        if (empty_list == -1 && Check_Inventory_LIST(Y_STORE, "", 0) != -1) {
            // 가이드 출력
            empty_list = Check_Inventory_LIST(Y_STORE, "", 0);
            Print_Simple("안내선");

            // 입력받은 값 저장
            strcpy(Y_STORE[empty_list].ITEM_name, ITEM_name);

            // 가격 입력받기
            SAVE_ITEM_priceORquantity("제품 가격을 입력하세요: ", &Y_STORE[empty_list].ITEM_price, "양의 숫자를 입력하세요.");

            // 수량 입력받기
            SAVE_ITEM_priceORquantity("제품 수량을 입력하세요: ", &Y_STORE[empty_list].ITEM_quantity, "양의 숫자를 입력하세요.");

            // 변경된 재고 목록 출력
            Print_Count_Inventory(Y_STORE, empty_list);
            Print_Simple("안내선");

            return 1;  // 정상적으로 재고 추가 완료
        }
        // 이미 존재하는 재고 목록인 경우
        else if (empty_list != -1) {
            Print_Errer("이미 추가된 재고입니다.");

            Print_Simple("안내선");
            Print_Simple("변경 전");
            Print_Count_Inventory(Y_STORE, empty_list);

            // 수량 입력받기
            ADD_ITEM_quantity("추가할 수량을 입력하세요: ", Y_STORE, "양의 숫자를 입력하세요.", empty_list);

            Print_Simple("안내선");
            Print_Simple("변경 후");

            // 변경된 재고 목록 출력
            Print_Count_Inventory(Y_STORE, empty_list);
            return 1;  // 정상적으로 재고 추가 및 수량 변경 완료
        }
        // 저장할 공간이 없는 경우
        else {
            Print_Errer("더이상 저장할 공간이 없습니다");
            return 1;  // 저장할 공간 없음 오류
        }
    }
    // 저장할 공간이 없는 경우
    else {
        Print_Errer("더이상 저장할 공간이 없습니다");
        return 1;  // 저장할 공간 없음 오류
    }
}

// 2-3. 재고 출고 메뉴 함수
int Menu_Inventory_Take(Inventory_Management* Y_STORE) {
    int empty_list = 0;  // 빈 재고 목록의 인덱스를 저장할 변수
    char ITEM_name[ITEM_SIZE] = { "\0" };  // 입력받을 아이템 이름을 저장할 변수

    // 재고 목록이 존재하는지 확인
    if (Check_Inventory_LIST(Y_STORE, "", 1) != -1) {
        // 유효한 아이템 이름을 입력받음
        GetValid_ITEM_Name(ITEM_name);

        // 입력받은 아이템 이름으로 재고 목록 확인
        empty_list = Check_Inventory_LIST(Y_STORE, ITEM_name, 0);

        // 재고 목록에 해당 아이템이 없는 경우
        if (empty_list == -1) {
            Print_Errer("없는 값입니다.");
            return 0;  // 재고 목록에 해당 아이템이 없음 오류
        }
        // 재고 목록에 이미 존재하는 경우
        else {
            Print_Errer("이미 추가된 재고입니다.");

            Print_Simple("안내선");
            Print_Simple("변경 전");
            Print_Count_Inventory(Y_STORE, empty_list);

            // 출고할 수량 입력받기
            TAKE_ITEM_quantity("출고할 수량을 입력하세요: ", Y_STORE, "보유한 수량보다 많을 수 없습니다.", empty_list);

            Print_Simple("안내선");
            Print_Simple("변경 후");

            // 변경된 재고 목록 출력
            Print_Count_Inventory(Y_STORE, empty_list);
            return 1;  // 정상적으로 재고 출고 및 수량 변경 완료
        }
    }
    // 재고가 존재하지 않는 경우
    else {
        Print_Errer("재고가 존재하지 않습니다.");
        return 1;  // 재고 목록이 비어있음 오류
    }
}

// 2-4. 재고 삭제 메뉴 함수
int Menu_Inventory_Delete(Inventory_Management* Y_STORE) {
    int delete_list = 0;  // 삭제할 아이템의 인덱스를 저장할 변수
    char ITEM_name[ITEM_SIZE] = { "\0" };  // 입력받을 아이템 이름을 저장할 변수

    // 재고 목록이 존재하는지 확인
    if (Check_Inventory_LIST(Y_STORE, "", 1) != -1) {
        // 유효한 아이템 이름을 입력받음
        GetValid_ITEM_Name(ITEM_name);

        // 입력받은 아이템 이름으로 재고 목록 확인
        delete_list = Check_Inventory_LIST(Y_STORE, ITEM_name, 0);

        // 삭제할 아이템이 존재하는 경우
        if (delete_list != -1) {
            Print_Simple("안내선");
            Print_Simple("삭제 전");
            Print_Count_Inventory(Y_STORE, delete_list);

            Print_Simple("안내선");
            Print_Simple("삭제 후");
        }

        // 재고 삭제 함수 호출
        if (DELETE_Inventory(Y_STORE, "없는 값입니다.", ITEM_name) == 1) {
            // 삭제된 재고 목록 출력
            Print_Count_Inventory(Y_STORE, delete_list);
            return 1;  // 정상적으로 재고 삭제 완료
        }
        else {
            return 0;  // 재고 삭제 중 오류 발생
        }
    }
    // 재고가 존재하지 않는 경우
    else {
        Print_Errer("재고가 존재하지 않습니다.");
        return 1;  // 재고 목록이 비어있음 오류
    }
}


//텍스트 출력 관련 함수------------------------------------------------------------------------------------------------------


//메뉴 출력문 모음
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
    else {
        printf("저장된 값 없음\n");
    }
}

//에러 출력문 모음
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
    else if (strcmp(Text_list, "없는 값입니다.") == 0) {
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
    else if (strcmp(Text_list, "보유한 수량보다 많을 수 없습니다.") == 0) {
        printf("\n\n보유한 수량보다 많을 수 없습니다.\n");
        printf("\n\n다시 입력해주세요.\n");
    }
    else {
        printf("저장된 값 없음\n");
    }
    printf("\n____________________________________________\n\n");
}

//자주 사용하는 출력문 모음
void Print_Simple(char Text_list[]) {
    if (strcmp(Text_list, "안내선") == 0) {
        printf("____________________________________________\n\n");
        return;
    }
    else if (strcmp(Text_list, "변경 전") == 0) {
        printf("[변경 전]\n");
    }
    else if (strcmp(Text_list, "변경 후") == 0) {
        printf("[변경 후]\n");
    }
    else if (strcmp(Text_list, "삭제 전") == 0) {
        printf("[삭제 전]\n");
    }
    else if (strcmp(Text_list, "삭제 후") == 0) {
        printf("[삭제 후]\n");
    }
    else {
        printf("저장된 값 없음\n");
    }
}



//재고 관련 함수------------------------------------------------------------------------------------------------------


//재고 유무 여부 채크 함수
int Check_Inventory_LIST(Inventory_Management* Y_STORE, char checkITEM_name[], int Value) {
    int i, count = 0;
    //checkITEM_name이 있는지 확인하는 값
    if (Value == 0) {
        for (i = 0; i < ITEM_LIST; i++) {
            if (strcmp(Y_STORE[i].ITEM_name, checkITEM_name) == 0) {
                return i; //checkITEM_name 하나라도 존재한다면
            }
        }
        return -1; // 그렇지 않으면 -1을 반환합니다.
    }
    //인덱스가 하나라도 존재한다면
    else if (Value == 1) {
        for (i = 0; i < ITEM_LIST; i++) {
            if (strcmp(Y_STORE[i].ITEM_name, "\0") != 0) {
                return 0; //"\0"이 아닌값이 하나라도 있으면
            }
        }
        return -1; // 그렇지 않으면 -1을 반환합니다.
    }
    else {
        for (i = 0; i < ITEM_LIST; i++) {
            if (strcmp(Y_STORE[i].ITEM_name, "\0") != 0) {
                count++; //"\0"이 아닌값이 하나라도 있으면
            }
        }
        return count;
    }
}

//특정 재고 출력
void Print_Count_Inventory(Inventory_Management* Y_STORE, int count) {
    Print_Simple("안내선");
    printf("[%d번 제품]\n", count);
    printf("제품명: %s\n", Y_STORE[count].ITEM_name);
    printf("제품 가격: %ld원\n", Y_STORE[count].ITEM_price);
    printf("제품 수량: %ld개\n", Y_STORE[count].ITEM_quantity);
    printf("제품 총가격: %ld원\n", Y_STORE[count].ITEM_quantity * Y_STORE[count].ITEM_price);
    Print_Simple("안내선");
}

//모든 재고 출력
void Print_Inventory_Management(Inventory_Management* Y_STORE, int sortType) {
    int i;
    int count_list = Check_Inventory_LIST(Y_STORE, "", 3);
    int left_list = ITEM_LIST - count_list;
    if (sortType == FIRST) {
        printf("\n정렬방식 : 알파벳순 정렬 | 총 %d개(빈공긴 : %d개)\n\n", count_list, left_list);
    }
    else if (sortType == SECOND) {
        printf("\n정렬방식 : 가격순 정렬 | 총 %d개(빈공긴 : %d개)\n\n", count_list, left_list);
    }
    else if (sortType == THIRD) {
        printf("\n정렬방식 : 수량순 정렬 |  총 %d개(빈공긴 : %d개)\n\n", count_list, left_list);
    }
    else {
        printf("\n잘못된 값 입니다.\n\n");
    }
    for (i = 0; i < ITEM_LIST; i++) {
        if (strlen(Y_STORE[i].ITEM_name) != 0) {
            Print_Count_Inventory(Y_STORE, i);
        }
    }

}

//재고의 이름을 입력받아 저장하는 함수
int GetValid_ITEM_Name(char itemName[]) {
    while (1) {
        printf("재고의 이름을 입력해주세요 : ");
        scanf("%29[^\n]", itemName);

        if (Check_ITEM_name(itemName) == 1) {
            return 1;
        }
        else {
            Print_Errer("영어, 숫자만 입력 가능합니다.");
        }
    }
}

//재고 이름 허용성 검사
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

//가격과,수량 받아 검사하는 함수
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

//입고 수량 입력받는 함수
void ADD_ITEM_quantity(char* question, Inventory_Management* Y_STORE, char* errorMessage, int index) {
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

//출고 수량 입력받는 함수
void TAKE_ITEM_quantity(char* question, Inventory_Management* Y_STORE, char* errorMessage, int index) {
    while (1) {
        long Input_value = 0;
        printf("%s", question);
        if (scanf("%ld", &Input_value) == 1 && Input_value > 0) {
            if (Y_STORE[index].ITEM_quantity >= Input_value) {
                Y_STORE[index].ITEM_quantity -= Input_value;
                break;
            }
            else {
                Print_Errer(errorMessage);
            }
            while (getchar() != '\n');      //버퍼 비우기
        }
    }
}

//재고를 삭제하는 함수
int DELETE_Inventory(Inventory_Management* Y_STORE, char* errorMessage, char ITEM_name[]) {
    while (1) {
        int delete_list = Check_Inventory_LIST(Y_STORE, ITEM_name, 0);

        if (delete_list != -1) {
            Y_STORE[delete_list].ITEM_name[0] = '\0';
            Y_STORE[delete_list].ITEM_price = 0;
            Y_STORE[delete_list].ITEM_quantity = 0;
            return 1;
        }
        else {
            Print_Errer(errorMessage);
            return 0;
        }
        while (getchar() != '\n');      //버퍼 비우기
    }
}


//정렬 관련 함수------------------------------------------------------------------------------------------------------


//구조체에서 ITEM_name을 비교하는 함수 [이름순] - 오름차순
int compareStructs_name(const void* a, const void* b) {
    // a와 b를 각각 구조체 포인터로 캐스팅한 후, ITEM_name을 가져오기
    const char* nameA = ((Inventory_Management*)a)->ITEM_name;
    const char* nameB = ((Inventory_Management*)b)->ITEM_name;

    // ITEM_name이 없는 경우 해당 항목을 가장 뒤로 보내기
    if (strlen(nameA) == 0 && strlen(nameB) == 0) {
        return 0; // 두 항목이 모두 ITEM_name이 없거나 비어있으면 순서를 유지
    }
    else if (strlen(nameA) == 0) {
        return 1; // a에만 ITEM_name이 없거나 비어있으면 a를 뒤로 보냄
    }
    else if (strlen(nameB) == 0) {
        return -1; // b에만 ITEM_name이 없거나 비어있으면 b를 뒤로 보냄
    }

    // ITEM_name이 모두 존재하고 비어있지 않은 경우 문자열 비교
    return strcmp(nameA, nameB);
}
//구조체에서 ITEM_price을 비교하는 함수 [상품가격순] - 오름차순
int compareStructs_price(const void* a, const void* b) {
    const char* nameA = ((Inventory_Management*)a)->ITEM_name;
    const char* nameB = ((Inventory_Management*)b)->ITEM_name;

    // ITEM_name이 없는 경우 해당 항목을 가장 뒤로 보내기
    if (strlen(nameA) == 0 && strlen(nameB) == 0) {
        return 0; // 두 항목이 모두 ITEM_name이 없거나 비어있으면 순서를 유지
    }
    else if (strlen(nameA) == 0) {
        return 1; // a에만 ITEM_name이 없거나 비어있으면 a를 뒤로 보냄
    }
    else if (strlen(nameB) == 0) {
        return -1; // b에만 ITEM_name이 없거나 비어있으면 b를 뒤로 보냄
    }
    // a와 b를 각각 구조체 포인터로 캐스팅한 후, ITEM_price를 비교하여 반환
    //(struct Inventory_Management*) 구조체 포인터로 형변환
    return ((Inventory_Management*)a)->ITEM_price - ((Inventory_Management*)b)->ITEM_price;
}
//구조체에서 ITEM_quantity을 비교하는 함수 [상품수량순] - 오름차순
int compareStructs_quantity(const void* a, const void* b) {
    const char* nameA = ((Inventory_Management*)a)->ITEM_name;
    const char* nameB = ((Inventory_Management*)b)->ITEM_name;

    // ITEM_name이 없는 경우 해당 항목을 가장 뒤로 보내기
    if (strlen(nameA) == 0 && strlen(nameB) == 0) {
        return 0; // 두 항목이 모두 ITEM_name이 없거나 비어있으면 순서를 유지
    }
    else if (strlen(nameA) == 0) {
        return 1; // a에만 ITEM_name이 없거나 비어있으면 a를 뒤로 보냄
    }
    else if (strlen(nameB) == 0) {
        return -1; // b에만 ITEM_name이 없거나 비어있으면 b를 뒤로 보냄
    }
    // a와 b를 각각 구조체 포인터로 캐스팅한 후, ITEM_quantity를 비교하여 반환
    //(struct Inventory_Management*) 구조체 포인터로 형변환
    return ((Inventory_Management*)a)->ITEM_quantity - ((Inventory_Management*)b)->ITEM_quantity;

}


//-------------------------------------------------------------------------------------------------------------------


void SaveInventory_File(Inventory_Management* Y_STORE) {
    FILE* file = fopen("product.txt", "w"); // 텍스트 모드로 쓰기 위해 파일 열기

    if (file != NULL) {
        // 헤더 쓰기
        fprintf(file, "재고의 정보가 저장된 파일입니다\n");

        // 배열에 저장된 값을 파일에 저장
        for (int i = 0; i < ITEM_LIST; i++) {
            fprintf(file, "____________________________________________\n");
            fprintf(file, "[%d번 제품]\n", i);
            fprintf(file, "제품명: %s\n", Y_STORE[i].ITEM_name);
            fprintf(file, "제품 가격: %ld원\n", Y_STORE[i].ITEM_price);
            fprintf(file, "제품 수량: %ld개\n", Y_STORE[i].ITEM_quantity);
            fprintf(file, "제품 총가격: %ld원\n", Y_STORE[i].ITEM_quantity * Y_STORE[i].ITEM_price);
            
        }

        fclose(file);
    }
    else {
        printf("파일을 쓰기 위해 열 수 없습니다.\n");
    }
}
void LoadInventory_File(Inventory_Management* Y_STORE) {
    FILE* file = fopen("product.txt", "r"); // 텍스트 모드로 읽기 위해 파일 열기

    if (file != NULL) {
        //첫줄 생략
        fscanf(file, "%*[^\n]\n");

        for (int i = 0; i < ITEM_LIST; i++) {
            while (fgetc(file) != '\n'){}
            fscanf(file, "____________________________________________\n");
            fscanf(file, "[%*d번 제품]\n");
            if (fscanf(file, "제품명: %s\n", Y_STORE[i].ITEM_name) != 1) {
                printf("오류: 제품명을 읽을 수 없습니다.\n");
            }
            if (fscanf(file, "제품 가격: %ld원\n", &Y_STORE[i].ITEM_price) != 1) {
                printf("오류: 제품 가격을 읽을 수 없습니다.\n");
            }
            if (fscanf(file, "제품 수량: %ld개\n", &Y_STORE[i].ITEM_quantity) != 1) {
                printf("오류: 제품 수량을 읽을 수 없습니다.\n");
            }
            fscanf(file, "제품 총가격: %*ld원\n");
            while (fgetc(file) != '\n') {}
        }


        fclose(file);
        printf("저장된 파일에서 값을 불러왔습니다.\n");
    }
    else {
        printf("저장된 파일이 없습니다.\n");
        printf("종료시 새로운 파일이 생성되어 저장됩니다.\n");
    }
}
