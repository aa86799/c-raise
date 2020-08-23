#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
int sprintf(char *str, const char *format, ...);
功能：
	根据参数format字符串来转换并格式化数据，然后将结果输出到 str 指定的空间中，直到    出现字符串结束符 '\0'  为止。
	参数：
str：字符串首地址
	format：字符串格式，用法和printf()一样
返回值：
	成功：实际格式化的字符个数
	失败： - 1

*/

void test()
{

    //1. 格式化字符串
    char buf[1024] = { 0 };
    sprintf(buf, "Hello %s!", "Obama");
    printf("buf:%s\n",buf);

    //2. 拼接字符串
    char *s1 = "hello";
    char *s2 = "world";
    memset(buf, 0, 1024);
    sprintf(buf, "%s %s", s1, s2);
    printf("buf:%s\n", buf);

    //3. 数字转成字符串格式
    int number = 666;
    memset(buf, 0, 1024);
    sprintf(buf, "%d", number);
    printf("buf:%s\n", buf);

    //4. 格式化数字八进制 十六进制
    memset(buf, 0, 1024);
    sprintf(buf, "%o", number);
    printf("八进制:%s\n", buf);
    memset(buf, 0, 1024);
    sprintf(buf, "%x", number);
    printf("十六进制:%s\n", buf);


    char **p = malloc(sizeof(char *)* 5);
    for (int i = 0; i < 5; ++i)
    {
        p[i] = malloc(64);
        memset(p[i], 0, 64);
        sprintf(p[i], "Name_%d", i + 1);
    }

    //打印字符串
    for (int i = 0; i < 5;++i)
    {
        printf("%s\n",p[i]);
    }

    //释放内存
    for (int i = 0; i < 5; ++i)
    {
        if (p[i] != NULL)
        {
            free(p[i]);
            p[i] = NULL;
        }
    }

    if (p != NULL)
    {
        free(p);
        p = NULL;
    }

}

int main(){

    test();

    system("pause");
    return EXIT_SUCCESS;
}