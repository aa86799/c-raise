#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h> //calloc ralloc realloc

//1. calloc  分配连续的固定大小的空间，通常用于数组
void test01() {
    int *p = calloc(10, sizeof(int));
    for (int i = 0; i < 10; ++i) {
        p[i] = i + 1;
    }

    for (int i = 0; i < 10; ++i) {
        printf("%d ", p[i]);
    }


    if (p != NULL) {
        free(p);
        p = NULL;
    }
}

//malloc 分配空间； realloc 重新分配
void test02() {
    int *p = malloc(sizeof(int) * 10); //也可用于数组
    for (int i = 0; i < 10; ++i) {
        p[i] = i + 1;
    }

    for (int i = 0; i < 10; ++i) {
        printf("%d ", p[i]);
    }

    printf("%d\n", p);
    p = realloc(p, sizeof(int) * 200);
    printf("%d\n", p);

    //重新分配，增加空间之后
    for (int i = 0; i < 15; ++i) {
        printf("%d ", p[i]);
    }

}

void test03() {
    int *p = malloc(sizeof(int) * 2);
    *p = 10;
    printf("%d\n", *p); //out 10

    p[0] = 1;
    p[1] = 11;
    for (int i = 0; i < 10; ++i) {
        printf("%d ", p[i]); //out :  [0]=1, [1]=11, 其它是 0
    }
    printf("%d\n", *p); //out 1
    printf("%d\n", *++p); //out 11
}


int main() {
    test01();
    printf("\n------\n");
    test02();

    test03();

    return EXIT_SUCCESS;
}