#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void SelectSort(char **arr, int len) {
    for (int i = 0; i < len; ++i) {
        int min = i;

        for (int j = i + 1; j < len; ++j) {
            if (strcmp(arr[j], arr[min]) < 0) {//compare
                min = j;
            }
        }// 找出最小索引

        //交换
        if (min != i) {
            char *temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

void PrintArray(char **arr, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%s\n", arr[i]);
    }
}

void test() {

    char *pArr[] = {"ddd", "ccc", "fff", "hhh", "ppp", "rrr"};
    //pArr是什么类型的？ char **类型的
    int len = sizeof(pArr) / sizeof(char *);

    PrintArray(pArr, len);
    //选择排序
    SelectSort(pArr, len);
    printf("-------------------\n");
    PrintArray(pArr, len);

}

int main() {
    test();
    return EXIT_SUCCESS;
}