#include <stdio.h>

int coke(int r, int b, int s)
{
    for(int c=1; (c*400) <= r; c++)
    {
        if (r - (c * 400) == 0)
        {
            printf("크림빵 %d개, 새우깡 %d개, 콜라 %d개\n", b, s, c);
        }
        else
            continue;
    }
    return 0;
}

int main(void)
{
    int money;
    int b, s, r = 1;
    printf("현재 당신이 소유하고 있는 금액입력하시오 : ");
    scanf("%d", &money);

    int current = money - 500;

    for (b = 1; (b * 500) <= current; b++)
    {
        int r1 = money - (b * 500);
        for (s = 1; (s * 700) < r1; s++)
        {
            r = r1 - (s * 700);
            coke(r,b,s);
        }
    }

    printf("어떻게 구입하시겠습니까?\n");
    return 0;
}

