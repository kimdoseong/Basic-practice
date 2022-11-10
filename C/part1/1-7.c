#include <stdio.h>

int main()
{
    int n, k;
    int num = 1;
    printf("숫자 n을 입력하시오 : ");
    scanf("%d", &n);

    for (k = 0; num < n; k++)
    {
        num = num * 2;
        if (num > n)
            k--;
    }

    printf("%d", k);
}