#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>		// RAND_MAX
#include <conio.h>
#include <Windows.h>	//srand(GetTickCount());
#include <time.h>		//srand(time(NULL));
#include <math.h>

//����
long long Save_integer();
long long exponential(long long);

//���� ����
long long int integer = 0;
int savePM = 0; //1�� ��� 0�� ����

//����
int main(void) {
	long long base = 0;
	while (1) {
		base = exponential(Save_integer());
		if (savePM == 0) {
			base = -base; //�ٽ� ������ ��ȯ
			printf("%lld\n", base);
		}
		else if (savePM == 1) {
			printf("%lld\n", base);
		}
	}

	return 0;
}

//������ �Է¹޴� �Լ�
long long Save_integer() {

	printf("������ �Է��Ͻÿ� : ");
	scanf("%lld", &integer);

	//������� �ϴ� savePM ������� �����ϰ� ����� �ٲ��ش�
	if (integer < 0) {
		savePM = 0;			//������� ����
		return -integer;	//����� ��ȯ�� ��ȯ
	}
	//������ �ϴ� savePM ������ ����
	savePM = 1;			//������ ����
	return integer;		//����� ��ȯ
}

//�Է¹��� ������ �������ؼ� ������������ ���ϴ� ��� �Լ�
long long exponential(long long integer) {
	if (integer == 1) {
		return 1;
	}
	return pow(integer, 3) + exponential(integer - 1);
}

