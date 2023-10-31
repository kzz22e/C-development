#pragma warning(disable:4996)  // 특정 경고 메시지를 억제
#include <stdio.h>             // 표준 입력 및 출력 함수를 사용하기 위한 헤더
#include <stdlib.h>            // 표준 라이브러리 함수 및 상수 (예: RAND_MAX) 사용
#include <time.h>              // 시간 및 시계 함수를 사용하기 위한 헤더 (사용되지 않음)
#include <math.h>              // 수학 함수를 사용하기 위한 헤더 (사용되지 않음)
#include <string.h>  
#include <ctype.h>

int main() {
	int max;
	int i;
	int a[10] = { 1,3,4,6,5,9,7,8,5,6 };

	max = a[0];
	for (i = 1; i < 10; i++) {
		if (a[i] > max) { 
			// < : 최솟값
			// > : 최댓값
			max = a[i];
		}
	}
	printf("%d\n", max);


	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10 - i - 1; j++) {
			if (a[j] > a[j + 1]) { 
				// < : 큰 수부터 나열
				// > : 작은 수부터 나열
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < 10; i++){
		printf("%d", a[i]);
	}
}
