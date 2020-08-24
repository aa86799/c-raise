#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void allocateSpace(int **temp) {
    int *arr = malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; ++i) {
        arr[i] = i + 1;
    }

    //指针间接赋值
    *temp = arr;
}

void printArray(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
}

#if 0
void freeSpace(void *arr)
{
    if (arr == NULL)
    {
        return;
    }

    free(arr);
    arr = NULL;
}
#else
void freeSpace(void **arr) {
    if (arr == NULL) {
        return;
    }

    if (*arr != NULL) {
        free(*arr);
        *arr = NULL;
        arr = NULL;
    }
}
#endif

void test01() {
    int *pArray = NULL;
    allocateSpace(&pArray);
    printArray(pArray, 10);
#if 0
    freeSpace(pArray); //error
    pArray = NULL;
#endif
    freeSpace((void**) &pArray);

    //直接如下释放，也是对的
//    free(pArray);
//    pArray = NULL;

    if (pArray == NULL) {
        printf("pArray被置空!");
    }

}

int main() {
    test01();

    return EXIT_SUCCESS;
}