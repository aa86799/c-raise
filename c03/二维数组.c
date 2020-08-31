#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef int(ARR_TYPE)[3];  //typedef int[3] arr;

//二维数组名，和一级数组名是一样的，都是 首元素的地址指针； 只是该地址上放的是一维数组
void printBiArrayA(int(*parr)[4], int len1, int len2) {
    for (int i = 0; i < len1; ++i) {
        for (int j = 0; j < len2; ++j) {
            //printf("%d ", *(*(parr + i) + j) );
            printf("%d ", parr[i][j]);
        }
    }
}

void printBiArrayD(int **parr, int len1, int len2) {
    for (int i = 0; i < len1; ++i) {
        for (int j = 0; j < len2; ++j) {
            printf("%d ", *(*(parr + i) + j) );
//            printf("%d ", ((*parr)[i]) [j];
        }
    }
}

void printBiArrayB(int parr[3][4], int len1, int len2) {
    for (int i = 0; i < len1; ++i) {
        for (int j = 0; j < len2; ++j) {
            //printf("%d ", *(*(parr + i) + j) );
            printf("%d ", parr[i][j]);
        }
    }
}

void printBiArrayC(int parr[][4], int len1, int len2) {
    for (int i = 0; i < len1; ++i) {
        for (int j = 0; j < len2; ++j) {
            //printf("%d ", *(*(parr + i) + j) );
            printf("%d ", parr[i][j]);
        }
    }
}


void test01() {
    int arr[3][4] = {
            {1, 2, 3, 4},
            {4, 5, 6, 7},
            {7, 8, 9, 10}
    };

    printBiArrayA(arr, 3, 4);
    printf("\n---\n");
    printBiArrayB(arr, 3, 4);
    printf("\n---\n");
    printBiArrayC(arr, 3, 4);
    printf("\n---\n");

    //二级指针能与指针数组相互转换；   指针数组，[] 具有高优先级； 若  (*ary)[]，则是数组指针
    int *ary[3];
    for (int i = 0; i < 3; ++i) {
        ary[i] = arr[i];
    }
    printBiArrayD(ary, 3, 4);

#if 0
    //int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    //int arr[][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    //对于二维数组同一维数组一样，除了sizeof 对数组名取地址之外，那么数组名就是指向数组首元素的指针
    //printf("%s\n", typeid(arr).name());
    //int(*pArray)[3] = arr;

    printf("arr[1][2]%d\n",arr[1][2]);
    printf("*(*(arr + 2) + 1) : %d\n", *(*(arr + 2) + 1));
#endif

}

int main() {
    test01();

    return EXIT_SUCCESS;
}