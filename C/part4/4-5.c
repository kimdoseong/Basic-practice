#include<stdio.h>

int main(void) {
    char word1[50];
    char word2[50];
    FILE *fp1 = fopen("a.txt", "rt");
    FILE *fp2 = fopen("b.txt", "rt");

    if (fp1 != NULL || fp2 != NULL) {
        puts("파일 오픈 성공");
    } else {
        puts("파일 오픈 실패");
        return -1;
    }


    while (!feof(fp1) && !feof(fp2)) {
        fscanf(fp1, "%s", word1);
        fscanf(fp2, "%s", word2);

        if (word1[0] == word2[0])
            continue;

        else {
            puts("두 파일이 다릅니다.");
            fclose(fp1);
            fclose(fp2);
            return -1;
        }
    }

    printf("두 개의 파일은 완전히 일치 합니다.\n");
    fclose(fp1);
    fclose(fp2);
    return 0;
}