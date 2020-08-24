#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//查找子串第一次出现的位置
char *myStrStr(const char *str, const char *substr) {
    //临时指针变量， 不改原来的串内容
    const char *p = str;
    printf("p=%s\n", p);
    const char *q = substr;
    while (*p != '\0') {
        if (*p != *q) {
            ++p;//从表示的首地址递增
            printf("while p=%s\n", p);
            continue;
        }
        return (char*) p;
    }
    return NULL;

}

void test() {
//    char *str = "abcd周e天fg"; //在UTF-8编码中:一个中文等于三个字节; 上面的指针单步移动就有问题了。
//    char *sub = "天";
    char *str = "abcdefg";
    char *sub = "e";
    char *pos = myStrStr(str, sub);
    printf("pos = %s\n", pos);

}

int main() {
    test();

    return EXIT_SUCCESS;
}