#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1. 主调函数分配内存，被调函数使用内存  指针的输入特性
void printString(const char *str) {
    printf("打印内容:%s\n", str);
    printf("打印内容:%s\n", str + 2);
    //strlen();
}

void printStringArray(char **arr, int len) {
    //arr[0]是char*类型的
    for (int i = 0; i < len; ++i) {
        printf("%s\n", arr[i]);
    }
}

void test01() {
    //堆上分配内存
    char *s = malloc(sizeof(char) * 100);
    memset(s, 0, 100);
    strcpy(s, "I am Polly!");
    printString(s);

    //数组名左函数参数就会退化为指向数组首元素的指针
    double arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    //栈上分配  指针数组是多个指针变量，以数组形式存在内存当中，占有多个指针的存储空间。     char (*s)[], 数组指针，本质是指针，指向数组。
    const char *strs[] = {
            "aaaaa",
            "bbbbb",
            "ccccc",
            "ddddd",
            "eeeee",
    };

    int len = sizeof(strs) / sizeof(strs[0]);

    printStringArray((char **) strs, len);
    printf("\n");

}

//2. 输出特性 被调函数分配内存，主调函数使用内存

void allocateSpace(char **temp) {
    char *p = malloc(100);
    memset(p, 0, 100);
    strcpy(p, "hello world!");

    //指针的间接赋值
    *temp = p;
}

void test02() {
    char *p = NULL;
    allocateSpace(&p);
    printf("p = %s\n", p);

    if (p != NULL) {
        free(p);
        p = NULL;
    }
}


int main() {
    test01();
    test02();

    return EXIT_SUCCESS;
}