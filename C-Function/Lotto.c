#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i;
    int lotto[6];

    //시드 값 설정을 통해 무작위 숫자 생성을 초기화합니다.
    srand(time(NULL));

    // 로또 번호 생성
    for (i = 0; i < 6; i++) {
        lotto[i] = (rand() % 45) + 1; // 1부터 45까지의 난수 생성
    }

    // 중복 제거 (선택적)
    for (i = 0; i < 6; i++) {
        for (int j = 0; j < i; j++) {
            if (lotto[i] == lotto[j]) {
                i--;
                break;
            }
        }
    }

    // 로또 번호 출력
    printf("로또 번호: ");
    for (i = 0; i < 6; i++) {
        printf("%d ", lotto[i]);
    }
    printf("\n");

    return 0;
}