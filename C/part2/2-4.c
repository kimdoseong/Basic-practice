#include <stdio.h>

void pandan(char* str, int strlen);

int main(void)
{
    char str[50];
    int strlen = 0, i = 0;
    printf("문자열 입력 : ");
    scanf("%s", str);

    while (str[i] != '\0')
        i++;
    i--;

    pandan(str, i);
}

void pandan(char* str, int strlen)
{
    int j = 0;

    while (1)
    {
        if (str[strlen] == str[j])
        {
            strlen--;
            j++;
        }

        else if ((strlen < j))
        {
            printf("회문 입니다.");
            break;

        }

        else
        {
            printf("회문이 아닙니다.");
            break;
        }
    }

}
