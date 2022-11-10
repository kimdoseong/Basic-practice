#include <stdio.h>

int main(void)
{
    int input;
    int h = 0;
    int	m = 0;


    printf("초(second)입력 : ");
    scanf("%d", &input);
    int s = input;

    if (s < 60)
    {
        printf("h:%d, m:%d, s:%d\n", h, m, s);
    }
    else
    {
        do
        {
            s = s % 60;
        } while (s >= 60);

        if (input - s >= 60)
        {
            m = (input - s) / 60;
            if (m >= 60)
            {
                h = m / 60;
                m = m % 60;
                printf("h:%d, m:%d, s:%d\n", h, m, s);
            }
            else
                printf("h:%d, m:%d, s:%d\n", h, m, s);
        }

    }

}