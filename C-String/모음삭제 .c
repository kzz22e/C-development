#define _CRT_SECURE_NO_WARNINGS		// Microsoft Visual Studio�� ���õ� ��� ����
#pragma warning(disable:4996)		// Ư�� ��� �޽����� ����
#include <stdio.h>					// ǥ�� �Է� �� ��� �Լ��� ����ϱ� ���� ���
#include <stdlib.h>					// ǥ�� ���̺귯�� �Լ� �� ��� (��: RAND_MAX) ���
#include <conio.h>					// �ܼ� ����� �Լ��� ����ϱ� ���� ��� (������ ����)
#include <Windows.h>				// �������� API �Լ��� ����ϱ� ���� ��� (������ ����)
#include <time.h>					// �ð� �� �ð� �Լ��� ����ϱ� ���� ��� (������ ����)
#include <math.h>					// ���� �Լ��� ����ϱ� ���� ��� (������ ����)
#include <string.h>  
#include <ctype.h>						  
#define SIZE 100

int main(void) {
	char s[SIZE] = { 0 };
	char result[SIZE] = { 0 };
	int i = 0, j = 0;

	printf("�ؽ�Ʈ�� �Է��Ͻÿ�: ");
	gets_s(s, SIZE - 1);

	//�� ���� ���ö� ���� �ݺ�
	while (s[i] != '\0') {
		//���� ������ �ƴ϶�� ���� �����ؼ� �����Ѵ�
		if (s[i] != 'a' &&	//a�� �ƴϰų�
			s[i] != 'i' &&	//i�� �ƴϰų�
			s[i] != 'e' &&	//e�� �ƴϰų�
			s[i] != 'o' &&	//o�� �ƴϰų�
			s[i] != 'u'){	//u�� �ƴϸ�
			result[j] = s[i];
			j++;			//������ j���� ������ �������̱� ������ �ΰ��� �־�����Ѵ�
		}
		//�����̶�� �װ��� �ǳʶڴ�.
		i++;
	}

	result[j] = '\0';

	printf("���� �ؽ�Ʈ: %s\n", result);

	return 0;
}