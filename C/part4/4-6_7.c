#include<stdio.h>
#include<string.h>

#define MAX_PERSON_NUM    100
#define NAME_SIZE 100
#define TEL_SIZE 20

typedef struct {
    char Name[NAME_SIZE];
    char Tel[TEL_SIZE];
} Person;

int ShowMenu(int *ptr);

void Insert(Person *per, int *PN); //이름 전화번호 입력
void Delete(Person *per, int *PN); //해당 이름 정보 삭제
void Search(Person *per, int *PN); //해당 이름 정보 출력
void AllData(Person *per, int *PN);//모든 정보 출력
int LoadData(Person *per, int *PN);//Data 불러오기
int StoreData(Person *per, int *PN);//Data 저장


int main(void) {
    Person Per[MAX_PERSON_NUM];
    int Pernum = 0, num = 0;

    LoadData(Per, &Pernum);

    while (1) {
        ShowMenu(&num);
        switch (num) {
            case 1:
                Insert(Per, &Pernum);
                break;
            case 2:
                Delete(Per, &Pernum);
                break;
            case 3:
                Search(Per, &Pernum);
                break;
            case 4:
                AllData(Per, &Pernum);
                break;
            default :
                StoreData(Per, &Pernum);
                return 0;
        }
    }
}

int ShowMenu(int *ptr) {
    *ptr = 0;
    printf("*****MENU*****\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Print All\n");
    printf("5. Exit\n");
    printf("Choose the item : ");
    scanf("%d", ptr);
    printf("------------------------\n\n");
    return *ptr;
}

void Insert(Person *per, int *PN) {
    printf("[INSERT]\n");
    printf("Input Name : ");
    scanf("%s", per[*PN].Name);

    printf("Input Tel Number : ");
    scanf("%s", per[*PN].Tel);
    printf("Result: NAME[\"%s\"], TEL[\"%s\"]\n", per[*PN].Name, per[*PN].Tel);
    fputs("        Data Inserted\n\n", stdout);
    (*PN)++;
}

void Delete(Person *per, int *PN) {
    int i = 0;
    printf("[DELETE]\n");
    printf("Delete Name : ");
    scanf("%s", per[*PN].Name);

    for (i = 0; i < *PN; i++) {
        if (!strcmp(per[i].Name, per[(*PN)].Name)) {
            strncpy(per[i].Name, per[(*PN) - 1].Name, sizeof(per[i].Name));
            strncpy(per[i].Tel, per[(*PN) - 1].Tel, sizeof(per[i].Tel));
            (*PN)--;
            printf("		Delete Completed.\n\n");
            i++;
        } else if (i == (*PN) - 1)
            printf("		No matching.\n\n");
    }
}

void Search(Person *per, int *PN) {
    int i = 0;
    printf("[Search]\n");
    printf("Search Name : ");
    scanf("%s", per[*PN].Name);

    for (i = 0; i < *PN; i++) {
        if (!strcmp(per[i].Name, per[(*PN)].Name)) {
            printf("Name : %s	Tel : %s\n\n", per[i].Name, per[i].Tel);
            i++;
        } else if (i == (*PN) - 1)
            printf("		No matching.\n\n");
    }
}

void AllData(Person *per, int *PN) {
    int i = 0;
    printf("[All Data]\n");

    for (i = 0; i < *PN; i++) {
        printf("Name : %s		Tel : %s\n", per[i].Name, per[i].Tel);
    }

    printf("\n\n");
}

int LoadData(Person *per, int *PN) {
    int ret;
    FILE *fp = fopen("a.txt", "rt");

    if (fp != NULL)
        fputs("File Read Success\n\n", stdout);
    else {
        fputs("File Read Fail\n\n", stdout);
        return -1;
    }

    while (1) {
        ret = fscanf(fp, "%s %s", per[(*PN)].Name, per[(*PN)].Tel);
        if (ret == EOF) {
            printf("Load Completed\n\n");
            break;
        }
        (*PN)++;
    }

    fclose(fp);

    return 0;
}

int StoreData(Person *per, int *PN) {
    int i = 0;
    FILE *fp = fopen("a.txt", "wt");

    if (fp != NULL)
        fputs("File Open Success\n\n", stdout);
    else {
        fputs("File Open Fail\n\n", stdout);
        return -1;
    }
    for (i = 0; i < (*PN); i++)
        fprintf(fp, "%s %s\n", per[i].Name, per[i].Tel);


    if (i == (*PN))
        printf("		Stored\n");

    fclose(fp);

    return 0;
}