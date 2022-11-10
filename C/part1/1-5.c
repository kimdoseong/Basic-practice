#include <stdio.h>
int num = 2;

int getsosu(void)
{
    for (int j = 2; j <= num; j++)
    {
        if (num == j)
        {
            return num;
        }

        else if (num % j == 0)
        {
            j = 2;
            num = num + 1;
        }
        else
            continue;
    }
    return 0;
}

int main(void)
{
    printf("소수 열개 출력\n");
    for (int i = 1; i <= 10; i++)
    {
        printf("%d = %d\n", i, getsosu());
        num++;
    }
    return 0;
}