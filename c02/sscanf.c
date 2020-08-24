#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//%*s或%*d	跳过数据
void test01()
{

#if 0
    char *str = "12345abcde";
	char buf[1024] = { 0 };
	sscanf(str,"%*d%s" , buf);
	printf("buf:%s\n", buf); //跳过后无数据

#else

    //忽略字符串到空格或者\t
    char *str = "abcde\t12345";
    char buf[1024] = { 0 }; //初始化首元素为0； = {1,2}  初始化前两个为 1，2
    sscanf(str, "%*s%s", buf); //从字符串读取格式化输入
    printf("buf:%s\n", buf); //out  12345

#endif

}

//%[width]s	读指定宽度的数据
void test02()
{
    char *str = "12345abcde";
    char buf[1024] = { 0 };
    sscanf(str, "%6s", buf); //6个字符组成的字符串
    printf("buf:%s\n", buf);
}
//%[a-z]	匹配a到z中任意字符(尽可能多的匹配)
void test03()
{
    char *str = "12345abcde";
    char buf[1024] = { 0 };
    sscanf(str, "%*d%[a-c]", buf);
    printf("buf:%s\n", buf);
}

//%[aBc]	匹配a、B、c中一员，贪婪性; 字符串头部只要不满足，就返回空串，满足几位就输出几位，之后的部分即使满足也不输出
void test04()
{
    char *str = "aAfABbcdeaAb";
    char buf[1024] = { 0 };
    sscanf(str, "%[aAb]", buf);
    printf("buf:%s\n", buf);
}

//%[^a] 	匹配非a的任意字符，贪婪性
void test05()
{
    char *str = "aABbcde";
    char buf[1024] = { 0 };
    sscanf(str, "%[^c]", buf);
    printf("buf:%s\n", buf);

}
//%[^a-z]	表示读取除a-z以外的所有字符
void test06()
{
    char *str = "aABbcde12345";
    char buf[1024] = { 0 };
    sscanf(str, "%[^0-9]", buf);
    printf("buf:%s\n", buf);
}


void test07()
{
    char *ip = "127.0.0.1";
    int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
    sscanf(ip, "%d.%d.%d.%d", &num1, &num2, &num3, &num4);

    printf("num1:%d\n", num1);
    printf("num2:%d\n", num2);
    printf("num3:%d\n", num3);
    printf("num4:%d\n", num4);
}

void test08()
{

    char *str = "abcde#12uiop@0plju";
    char buf[1024] = { 0 };
    sscanf(str, "%*[^#]#%[^@]" , buf);
    printf("buf:%s\n", buf);
    sscanf(str, "%*[^e]e%[^@]" , buf);
    printf("buf:%s\n", buf);

}


int main(){

//    test01();
//    test02();
//    test03();
//    test04();
//    test05();
//    test06();
//    test07();
    test08();


    return EXIT_SUCCESS;
}