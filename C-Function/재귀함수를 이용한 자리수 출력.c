#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>		// RAND_MAX
#include <conio.h>
#include <Windows.h>	//srand(GetTickCount());
#include <time.h>		//srand(time(NULL));
#include <math.h>


int main() {
	int integer;

	printf("������ �Է��Ͻÿ�: ");
	scanf("%d", &integer);

	//���� 0�̸� 0���� ��ȯ�ϰ� ����
	if (integer == 0) {
		printf("0");
		return 0;
	}
	//���� ������� -ǥ�ø� ���� ����ѵ� ������ ����� ���� �� �Լ� ����
	else if (integer < 0) {
		//�������� ��������� ��ȯ 
		integer = -integer;
		printf("- ");
		show_digit(integer);
	}
	else {
		show_digit(integer);
	}
	return 0;
}

void show_digit(int x) {
	//���̻� ���� ���� 0���� ������ �����Ѵ�
	if (x < 1) return;

	//���������� ��� ��) 234 -> 2 3 4 
	//�Ʒ� printf()�ڵ带 show_digit()�տ� �ۼ��ϸ� �ݴ�� ���
	show_digit(x / 10);
	printf("%d ", x % 10);
}

/* ��°���
4.	show_digit(326);
3.		show_digit(32);
2.			show_digit(3);
1.				show_digit(0);
1.				return;
2.			printf("%d ", x % 10);
3.		printf("%d ", x % 10);
4.	printf("%d ", x % 10);
*/

//���: 3 2 6
