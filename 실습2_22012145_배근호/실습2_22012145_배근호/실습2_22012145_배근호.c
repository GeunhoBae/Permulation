#include <stdio.h>
#include <time.h>
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#pragma warning(disable:4996)

void Perm(char* list, int i, int n) { //순열을 출력하는 재귀함수 list[i] ~ list[n]
    int j, temp;
    if (i == n) { //순열이 단 하나인 경우
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

void Perm_Int(int* list, int i, int n) { //정수 순열을 출력하는 재귀함수 list[i] ~ list[n]
    int j, temp;
    if (i == n) { //순열이 단 하나인 경우
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
    char B[10]; //여기에 A의 항목 하나씩 저장
    for (int i = 0; i < 4; i++) {
        printf("\n제시 문자열: ");
        for (int j = 0; j <= i + 1; j++) {
            B[j] = A[i][j];
            printf("%c", B[j]);
        }
        printf("\n");
        Perm(B, 0, i + 1);
    }

    //2.2
    int num; //배열 수
    int N_list[10]; //정수 배열
    clock_t start; //시간기록
    double time;
    for (int i = 0; i < 10; i++) //0~9까지 저장
        N_list[i] = i;
    while (1) {
        printf("\n1~10까지의 정수개수입력(종료: -1): ");
        scanf("%d", &num);
        if (num == -1) {
            printf("종료합니다.");
            break;
        }
        if (num > 10 || num < 1) {
            printf("잘못된 범위\n");
            continue;
        }
        printf("입력: %d\n순열:\n", num);
        start = clock();
        Perm_Int(N_list, 0, num - 1);
        time = (clock() - start) / CLOCKS_PER_SEC;
        printf("\n실행시간: %f초\n", time);
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
    printf("원소개수  실행시간\n");
    for (int i = 0; i < 10; i++)
        printf("%d        %f\n", i + 1, runtime[i]);
    printf("모든작업이 종료되었습니다.");
}