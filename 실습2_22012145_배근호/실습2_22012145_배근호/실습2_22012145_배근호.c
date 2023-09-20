#include <stdio.h>
#include <time.h>
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#pragma warning(disable:4996)

void Perm(char* list, int i, int n) { //������ ����ϴ� ����Լ� list[i] ~ list[n]
    int j, temp;
    if (i == n) { //������ �� �ϳ��� ���
        for (j = 0; j <= n; j++)
            printf("%c", list[j]);
        printf("  ");
    }
    else {
        for (j = i; j <= n; j++) {
            SWAP(list[i], list[j], temp);
            Perm(list, i + 1, n);
            SWAP(list[i], list[j], temp);
        }
    }
}

void Perm_Int(int* list, int i, int n) { //���� ������ ����ϴ� ����Լ� list[i] ~ list[n]
    int j, temp;
    if (i == n) { //������ �� �ϳ��� ���
        for (j = 0; j <= n; j++)
            printf("%d", list[j]);
        printf("  ");
    }
    else {
        for (j = i; j <= n; j++) {
            SWAP(list[i], list[j], temp);
            Perm_Int(list, i + 1, n);
            SWAP(list[i], list[j], temp);
        }
    }
}

void main() {
    //2.1
    char A[][10] = { "GO", "BOY", "GIRL", "GIRLS" };
    char B[10]; //���⿡ A�� �׸� �ϳ��� ����
    for (int i = 0; i < 4; i++) {
        printf("\n���� ���ڿ�: ");
        for (int j = 0; j <= i + 1; j++) {
            B[j] = A[i][j];
            printf("%c", B[j]);
        }
        printf("\n");
        Perm(B, 0, i + 1);
    }

    //2.2
    int num; //�迭 ��
    int N_list[10]; //���� �迭
    clock_t start; //�ð����
    double time;
    for (int i = 0; i < 10; i++) //0~9���� ����
        N_list[i] = i;
    while (1) {
        printf("\n1~10������ ���������Է�(����: -1): ");
        scanf("%d", &num);
        if (num == -1) {
            printf("�����մϴ�.");
            break;
        }
        if (num > 10 || num < 1) {
            printf("�߸��� ����\n");
            continue;
        }
        printf("�Է�: %d\n����:\n", num);
        start = clock();
        Perm_Int(N_list, 0, num - 1);
        time = (clock() - start) / CLOCKS_PER_SEC;
        printf("\n����ð�: %f��\n", time);
    }

    //2.3
    float runtime[10];
    for (int i = 0; i < 10; i++) {
        start = clock();
        Perm_Int(N_list, 0, i);
        time = (clock() - start) / CLOCKS_PER_SEC;
        runtime[i] = time;
        printf("\n");
    }
    printf("���Ұ���  ����ð�\n");
    for (int i = 0; i < 10; i++)
        printf("%d        %f\n", i + 1, runtime[i]);
    printf("����۾��� ����Ǿ����ϴ�.");
}