#include <stdio.h>

void DesSort(int *arr, int len);

int main(void) {
    int arr[7];
    int i;
    printf("7개의 정수를 입력하시오\n");

    for (i = 0; i < 7; i++) {
        printf("입력: ");
        scanf("%d", &arr[i]);
    }
    i--;
    DesSort(arr, i);

    for (i = 0; i < 7; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void DesSort(int *arr, int len) {
    int temp;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < (len - i); j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}