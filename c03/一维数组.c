#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//可读性 要比 效率更重要
void printArray(int arr[], int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
        printf("%d ", *(arr + i));
    }
}

void test01() {
    int arr[] = {1, 2, 3, 4};

    //1. sizeof  2.对数组名取地址&arr
    //以上两种情况下，数组名不是指向首元素的指针
    //以上两种请款下，数组名是数组类型
    //！除了以上两点之外，数据名在其他任何情况下都是指向首元素的指针
    //sizeof 可以不加括号，它是c语言关键字
    printf("sizeof arr:%lu\n", sizeof arr);
    printf("&arr addr : %d\n", &arr);
    printf("&arr + 1 addr : %d\n", &arr + 1);
    int *p = arr;

    //数组名是一个常量指针
    //arr = NULL;

    //数组下标能否是负数?
    //可以是负数
    p += 3; //ary[3]
    printf("p[-1]:%d\n", p[-1]); //ary[3-1]       这句比较特别！！！！！！！！！！！！！！！！！！
    //他们等价
    printf("p[-1]:%d\n", *(p - 1));
    //数组指针类型和数组首元素指针类型

}


//如何定义一个可以指向数组的指针
void test02() {
    int arr[5] = {1, 3, 5, 7, 9};

    //我们先定义数组类型，再定义数组指针类型
    typedef int ARRAY_TYPE[5];  //typedef unsigned int u32          数组别名
//    typedef int(ARRAY_TYPE)[5];  //typedef unsigned int u32         数组别名
    ARRAY_TYPE myarray; // int myarray[5];
    //
    for (int i = 0; i < 5; ++i) {
        myarray[i] = 100 + i;
    }

    for (int i = 0; i < 5; ++i) {
        printf("%d ", myarray[i]);
    }
    printf("\n");

    //对数组名取地址代表指向整个数组的指针
    ARRAY_TYPE *pArray = &myarray;//数组地址给到 *pArray，
    for (int i = 0; i < 5; ++i) {
        printf("%d ", *(*pArray + i)); //*pArray    表示拿到pArray指针指向的整个数组
    }
    printf("\n");

    pArray = &arr;
    //*pArray类型就是数组名，指向首元素类型的指针
    printf("\n*(*pArray + 1) : %d\n", *(*pArray + 1)); //out 3

    //直接定义数组指针类型
    typedef int(*ARRAY_POINTER)[5];
    ARRAY_POINTER pArr = &arr;
    for (int i = 0; i < 5; ++i) {
        printf("%d ", *(*pArr + i));
    }

    //直接定义数组指针变量
    int(*pArrParam)[5] = &arr;

    int *p = arr;
    for (int j = 0; j < 5; ++j) {
        printf("_ %x", p[j]);
    }
}

int main() {

    test01();
    printf("\n------\n");
    test02();

    return EXIT_SUCCESS;
}