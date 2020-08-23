#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
    char str1[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
    printf("%s\n", str1);
}

void copyString01(char *dst, const char *source)
{
    int len = strlen(source);

    for (int i = 0; i < len; ++i)
    {
        dst[i] = source[i];
    }

    dst[len] = '\0';
}


void copyString02(char *dst, const char *source)
{
    while (*source != '\0')
    {
        *dst = *source;
        ++dst;
        ++source;
    }

    *dst = '\0';
}

void copyString03(char *dst, const char *source)
{
    if (NULL == dst)
    {
        return;
    }

    if (NULL == source)
    {
        return;
    }

    while ((*dst++ = *source++));
}

//1. 字符串拷贝
void test02()
{
    char *source = "hello world!";
    char buf[1024] = {0};
    //copyString01(buf, source);
    //copyString02(buf, source);
    copyString03(buf, source);
    printf("%s\n",buf);

}

void reverseString(char *str)
{
    if (NULL == str)
    {
        return;
    }

    size_t len = strlen(str);


#if 0 //用数组形式
//#if 1
    int start = 0;
	size_t end = len - 1;
	while (start < end)
	{
//		char temp = str[start];
//		str[start] = str[end];
//		str[end] = temp;

    //使用 异或特性交换两个值， char 可以参与数值计算
        str[start] = str[start] ^ str[end];
        str[end] = str[start] ^ str[end];
        str[start] = str[start] ^ str[end];

		++start;
		--end;
	}
#else  //用指针形式
    char *pStart = str;
    char *pEnd = str + len - 1;

    while (pStart < pEnd)
    {
        char temp = *pStart;
        *pStart = *pEnd;
        *pEnd = temp;

        ++pStart;
        --pEnd;
    }
#endif


}

//2. 字符串反转
void test03()
{
    char p[] = "abc";
    reverseString(p);
    printf("p = %s\n", p);
}

int main(){
    test01();
    printf("-----\n");

    test02();
    printf("-----\n");

    test03();

    return EXIT_SUCCESS;
}