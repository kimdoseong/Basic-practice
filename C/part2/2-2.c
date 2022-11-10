#include <stdio.h>
void ezin(int Num, int* Namuzi);

int main(void)
{
    int num = 0;
    int namuzi[50];

    printf("10진수 정수 입력 하시오 : ");
    scanf("%d", &num);

    printf("%d의 2진수 ", num);

    ezin(num, namuzi);

}

void ezin(int Num, int* Namuzi)
{
    int i = 0;

    while (Num != 0)
    {
        Namuzi[i] = Num % 2;
        Num = Num / 2;
        i++;
    }

    i -= 1;

    while (i >= 0)
    {
        printf("%d", Namuzi[i]);
        i--;
    }
}