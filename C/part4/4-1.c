#include<stdio.h>

typedef struct {
    char title[30];
    char name[10];
    int page;
} Book;

void ShowBook(Book *sptr) {
    printf("저자 : %s", (*sptr).name);
    printf("제목 : %s", (*sptr).title);
    printf("페이지 수 : %d\n", (*sptr).page);
}

void Clear() {
    while (getchar() != '\n');
}

int main(void) {
    int i;
    Book arr[3];

    fputs("도서 정보 입력\n\n", stdout);

    for (i = 0; i < 3; i++) {
        printf("저자 : ");
        fgets(arr[i].name, sizeof(arr), stdin);
        printf("제목 : ");
        fgets(arr[i].title, sizeof(arr), stdin);
        printf("페이지 수 : ");
        scanf("%d", &arr[i].page);
        Clear();

    }


    for (i = 0; i < 3; i++) {
        printf("book %d", i + 1);
        ShowBook(&arr[i]);
        puts("--------------------------");
    }
    return 0;
}

