#pragma warning(disable:4996)  // Ư�� ��� �޽����� ����
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define START_FROM_ONE 96 //�빮��
#define UPPER 1 //�빮��
#define LOWER 0 //�ҹ���
#define SIZE 30

int Check_Capital_Word(char word[]) {
    for (int i = 0; i < strlen(word); i++) {
        if (isupper(word[i])) {
            return 1;
        }
    }
    return 0;
}

int SUM_Word(char word[]) {
    int sum = 0;
    for (int i = 0; i < strlen(word); i++) {
        sum += ((int)word[i] - START_FROM_ONE);
        printf("[Index]%d : %c | %d\n", i, word[i], sum);
    }
    return sum;
}

int main(void) {
    char word[SIZE] = { 0 };


    while (1) {
        printf("���ڿ��� �Է��Ͻÿ� :");
        scanf("%[^\n]s", word);
        //���ڰ� ���μҹ��ڰ� �ƴ϶�� �ٽ� �ݺ�
        if (Check_Capital_Word(word) == LOWER) {
            break;
        }
        printf("! �ҹ��ڷ� �Է����ּ��� !\n");
    }
    printf("���ڿ� �Ҵ�� ������ ��:%d", SUM_Word(word));
    return 0;
}