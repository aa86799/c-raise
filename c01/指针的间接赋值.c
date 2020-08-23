#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//指针引用传递
void changeValue(int *p)
{
	*p = 100;
}

void test01()
{
	int a = 10;
	changeValue(&a);
	printf("%d\n", a);
}


void changePointer(int **val)
{
	*val = (int *) 0x008;
}

void test02()
{
	int* p = NULL;
	changePointer(&p); //指针变量的地址  用指针的指针接收

	printf("指针 p = %x\n", p);  //%x 输出指定参数的16进制形式
}

int main(){
	test01();
	test02();

	return EXIT_SUCCESS;
}