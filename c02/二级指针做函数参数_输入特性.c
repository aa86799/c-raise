#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void printArray(int **arr, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", *arr[i]);
    }
}

//二级指针，指针操作每个元素
void test01() {
    //堆上分配指针数组，以二级指针表示
    int **pArray = malloc(sizeof(int *) * 6);

    //栈上分配数据空间
    int a1 = 100;
    int a2 = 200;
    int a3 = 300;
    int a4 = 400;
    int a5 = 500;
    int a6 = 600;
#if 0
    pArray[0] = &a1;
    pArray[1] = &a2;
    pArray[2] = &a3;
    pArray[3] = &a4;
    pArray[4] = &a5;
    pArray[5] = &a6;
#endif

    *(pArray + 0) = &a1;//指针 = 地址
    *(pArray + 1) = &a2;
    *(pArray + 2) = &a3;
    *(pArray + 3) = &a4;
    *(pArray + 4) = &a5;
    *(pArray + 5) = &a6;

    printArray(pArray, 6);

    //释放数组内存
    if (pArray != NULL) {
        free(pArray); //直接释放二级指针
        pArray = NULL;
    }

}


void printArray2(long **arr, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%ld ", *arr[i]);
    }
}
//指针数组，数组操作每个元素
void test02() {
    long *pArray[5];//指针数组，存放指针元素
    for (int i = 0; i < 5; ++i) {
        pArray[i] = malloc(sizeof(long*));
        *(pArray[i]) = 10000000000L + i;
    }

    printArray2(pArray, 5); //传入指针数组，用二级指针接收。

//    free(pArray); //error   数组不能调 free()

    //释放堆内存
    for (int i = 0; i < 5; ++i) {
        if (pArray[i] != NULL) {
            free(pArray[i]); //逐个释放数组中的指针
            pArray[i] = NULL;
        }
    }
}

int main() {

    test01();
    printf("-----\n");
    test02();

    return EXIT_SUCCESS;
}