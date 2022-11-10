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

    printf("배열 요소의 출력 : ");
    hol(arr);
    zzack(arr);

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
    int i = 0, j = 0;
    int arr[50];

    for (i = 0; i < 10; i++)
    {
        if (ptr1[i] % 2 == 0)
        {
            arr[j] = ptr1[i];
            j++;
        }
    }

    j--;

    while (j >= 0)
    {
        printf("%d ", arr[j]);
        j--;
    }
}