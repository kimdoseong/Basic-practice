#include<stdio.h>

void hol(int* ptr1);
void zzack(int* ptr1);

int main(void)
{
    int arr[10];
    int i = 0;
    printf("10개의 정수를 입력하시오\n");

    for (i = 0; i < 10; i++)
    {
        printf("입력 : ");
        scanf("%d", &arr[i]);
    }

    printf("홀수 출력 : ");
    hol(arr);
    printf("\n");

    printf("짝수 출력 : ");
    zzack(arr);
    printf("\n");


    return 0;
}

void hol(int* ptr1)
{
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        if (ptr1[i] % 2 != 0)
        {
            printf("%d ", ptr1[i]);
        }
    }
}

void zzack(int* ptr1)
{
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        if (ptr1[i] % 2 == 0)
        {
            printf("%d ", ptr1[i]);
        }
    }
}