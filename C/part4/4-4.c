#include<stdio.h>

int main(void) {
    char word[30];
    int numA = 0, numP = 0;
    FILE *fp = fopen("a.txt", "rt");


    if (fp != NULL) {
        puts("파일 오픈 성공");
    } else {
        puts("파일 오픈 실패");
        return -1;
    }

    while (!feof(fp)) {
        fscanf(fp, "%s", word);

        if (word[0] == 'A' || word[0] == 'a')
            numA++;

        if (word[0] == 'P' || word[0] == 'p')
            numP++;
    }


    printf("A(a) 시작 단어 수 : %d \n", numA);
    printf("P(p) 시작 단어 수 : %d \n", numP);

    fclose(fp);
    return 0;
}