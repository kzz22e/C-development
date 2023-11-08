#include <stdio.h>
#define SIZE 10

// 배열의 요소를 출력하는 함수
void print_array(int* A, int size) {
	printf("print_array()\n");

	// 배열의 요소를 반복하며 출력
	for (int i = 0; i < size; i++){
		printf("%d ", A[i]);
    }
}

// 배열의 요소 합을 계산하는 함수
int get_array_sum(int* A, int size) {
	int sum = 0;

	// 배열의 요소를 반복하며 합을 계산
	for (int i = 0; i < size; i++){
		sum += *(A + i);
        }

	return sum;
}

int main(void) {
	int data[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int* a = data; // 포인터 a를 배열 data의 시작 주소로 초기화

	print_array(a, 10); // 배열의 요소를 출력하는 함수 호출

	printf("\n배열 요소의 합=%d\n", get_array_sum(a, 10)); // 배열 요소의 합을 계산하고 출력

	return 0;
}