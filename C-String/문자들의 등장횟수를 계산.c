#define _CRT_SECURE_NO_WARNINGS // Microsoft Visual Studio�� ���õ� ��� ����
#pragma warning(disable:4996)   // Ư�� ��� �޽����� ����
#include <stdio.h>              // ǥ�� �Է� �� ��� �Լ��� ����ϱ� ���� ���
#include <stdlib.h>              // ǥ�� ���̺귯�� �Լ� �� ���
#include <string.h>  

int main(void) {

    //�Է¹��� ���ڿ��� �����ϴ� �ڵ�
    char saveText[SIZE] = { 0 };

    //�ƽ�Ű �ڵ��� ������ŭ �������� 0~127
    int freq[ASCII] = { 0 };


    printf("�ؽ�Ʈ�� �Է��Ͻÿ�: ");
    //"%[^n]s"�� �̿��� �ٹٲ��� �ϱ� ������ ��� ���ڸ� �Է¹ވf��
    scanf("%[^\n]s", saveText);

    //�Է¹��� ���ڿ��� ũ�⸸ŭ �ݺ� : strlen(saveText) �Լ��� �ش� ���ڿ��� ���̸� ��ȯ�մϴ�.
    //freq[saveText[i]]++; : �Էµ� ���ڿ����� ���� 'saveText[i]'�� �󵵼��� ������ŵ�ϴ�.��, 
    //�ش� ���ڰ� ��Ÿ�� ������ freq �迭���� �ش� ������ ASCII �ڵ� ��ġ�� �ִ� ��Ҹ� 1�� ������ŵ�ϴ�.
    for (int i = 0; i < strlen(saveText); i++) {
        //��:saveText[i] = 'k' ��� �����ϸ� freq[K]++; -> freq[107]++ 
        freq[saveText[i]]++;
    }
    //if (freq[j] != 0): ���ڿ��� �ش� ���ڰ� �ϳ� �̻� ��Ÿ���ٸ� �Ʒ��� �ڵ带 ����
    for (int j = 'a'; j <= 'z'; j++) {
        if (freq[j] != 0)
            printf("%c ���ڰ� %d�� �����Ͽ���!\n", j, freq[j]);
    }
    //if (freq[k] != 0): ���ڿ��� �ش� ���ڰ� �ϳ� �̻� ��Ÿ���ٸ� �Ʒ��� �ڵ带 ����
    for (int k = 'A'; k <= 'Z'; k++) {
        if (freq[k] != 0)
            printf("%c ���ڰ� %d�� �����Ͽ���!\n", k, freq[k]);
    }

    return 0;
}