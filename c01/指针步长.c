//
// Created by austin stone on 2020/8/23.
//

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stddef.h>


//指针步长：指针变量+1 要向后跳多少字节

//指针的类型，不单单决定指针的步长，还决定解引用的时候从给定地址开始取类型大小的字节数
void test01() {
    char *p = NULL;
    printf("%d\n", p);
    printf("%d\n", p + 1); //发现步长为1

    printf("----------------\n");
    int *p2 = NULL;
    printf("%d\n", p2);
    printf("%d\n", p2 + 1);//发现步长为4

    printf("----------------\n");


    char buf[1024] = {0};
    int a = 100;
    memcpy(buf + 1, &a, sizeof(int));  //从第二个参数复制n个字节到第一个参数，内存区域不可重叠
    printf("buf[1]=%c\n", buf[1]); //ascII中，a 从97开始；100就是 d

    char *p3 = buf;
    printf("*(int *)(p3 + 1) = %d\n", *(int *) (p3 + 1));
    printf("----------------\n");
}


struct Person {
    int a;
    char b;
    char buf[64];
    int d;
};

void test02() {
    struct Person p = {10, 'a', "hello world! 中国", 888888888};
    char b;
    printf("a off:%d\n", offsetof(struct Person, buf)); //成员变量 buf，在结构体类型中的地址是从首地址偏移了多少

    printf("%d\n", (char*) &p); //转成char*类型的地址变量
    printf("%d\n", ((char*) &p + offsetof(struct Person, d))); //加上偏移量
    printf("%d\n", (int *) ((char*) &p + offsetof(struct Person, d))); //转成类型 d, 地址对应的 int*
    printf("d = %d\n", *(int *) ((char*) &p + offsetof(struct Person, d))); //再 指针运算

    printf("b = %d\n", *(char *) ((char*) &p + offsetof(struct Person, b))); //b 变量

    //buf 变量，因其是 字符串，也就 相当于 字符数组，buf首地址只对应一个 字符而已
//    printf("buf = %c\n", *(char *) ((char*) &p + offsetof(struct Person, buf)));
    char *buf = (char*) &p + offsetof(struct Person, buf);
    char ary[offsetof(struct Person, d) - offsetof(struct Person, buf)]; //在的首地址，减去 buf的首地址，即 buf的字节长度
    int i = 0;
    while (buf < (char*) &p + offsetof(struct Person, d)) {
        printf("%c ", *buf); //汉字用单个 字符，输出不了
        ary[i] = *buf; ++i; //所有字符 逐个放到 ary
        ++buf;
        if (!*buf) {
            break;
        }
    }
    printf("\n");

    printf("%s\n", ary);

}


int main() {

    test01();
    test02();

    return EXIT_SUCCESS;
}