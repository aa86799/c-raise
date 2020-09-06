#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int arr[10];

//决定的函数的类型应该是：函数的返回值  函数的参数列表

void func() {
    printf("hello world!");
}

//func函数名其实是代表函数的入口地址

//如何去定义一个指向函数的指针
int myfunc(int a, char b) {
    printf("int myfunc(int a,char b) !\n");
    return 0;
}

void test01() {

    //1.定义函数类型，通过类型来定义函数指针
    typedef int(FUN_TYPE)(int, char);
    FUN_TYPE *pFunc = myfunc;

    pFunc(10, 'a');
    (*pFunc)(20, 'b');
    myfunc(30, 'c');

    //2. 直接定义函数指针类型
    typedef int(*FUNC_P)(int, char);
    FUNC_P pFunc2 = myfunc;
    pFunc2(20, 'd');

    //函数指针指向同类型
    //pFunc2 = func;

    //3. 直接定义函数指针变量


    //(int(*)(int, int)) 0x001;

    //把指针 转换为 函数指针类型写法
    int (*pFunc3)(int, char) = NULL;
    //pFunc3(11,'1');


    pFunc3 = myfunc;
    pFunc3(50, 'p');

    printf("pFunc3 size:%d\n", sizeof(pFunc3));
}

int con1(int a, int b) {
    return a + b;
}

int con2(int a, int b) {
    return a + b + 10;
}

int con3(int a, int b) {
    return a + b - 10;
}

int con4(int a, int b) {
    return a * b - 10;
}

int con5(int a, int b) {
    return a + b - 3 + 100 * 2;
}

//1. 函数就可以做另外一个函数的参数
void doLogic(int(*pFunc)(int, int)) {
    int a = 10;
    int b = 20;
    int ret = pFunc(a, b);
    printf("ret = %d\n", ret);
}


//2. 函数指针数组
void func1() {
    printf("func1\n");
}

void func2() {
    printf("func2\n");
}

void func3() {
    printf("func3\n");
}

void test03() {
    //函数指针的 数组
    void (*func_array[3])();
    func_array[0] = func1;
    func_array[1] = func2;
    func_array[2] = func3;

    for (int i = 0; i < 3; ++i) {
        func_array[i]();
    }
}

void test02() {

    doLogic(con5);
}

typedef void(*print_type)(void *);
//函数指针做函数参数（回调函数）
void printAllArray(void *arr, int eleSize, int len, print_type print) {
//    char *start = (char *) arr;
//    for (int i = 0; i < len; ++i) {
//        //printf("%d\n", start + i*eleSize);
//        char *eleAddr = start + i * eleSize; //i * eleSize；char* start, char 占一个字节， +i 也就只移一位，需要 * eleSize; 保证移了原类型 int 个字节。
//
//        //int *p = (int *)eleAddr;
//        //printf("%d ",*p);
//        print(eleAddr);
//    }

    int *ary = (int*) arr;
    for (int i = 0; i < len; ++i) {
        int *p = ary + i; //arr原本就是int[]，可以正常转成int*； 普通的指针位移 +step 即可； +1，即位移一个 int 所占字节；
        print(p);
    }
    printf("\n");
}

void MyPrint(void *data) {
    int *p = (int *) data;
    printf("%d ", *p);
}

struct Person {
    char name[64];
    int age;
};

void MyPrintPerson(void *data) {
    struct Person *person = (struct Person *) data;
    printf("Name:%s Age:%d\n", person->name, person->age);
}
void test04() {
    int arr[] = {2008899008, 4, 6, 8, 10};
    printAllArray(arr, sizeof(int), 5, MyPrint);

#if 1

    struct Person persons[] = {
            {"aaa", 10},
            {"bbb", 20},
            {"ccc", 30},
            {"ddd", 40},
            {"eee", 50},
    };

    printAllArray(persons, sizeof(struct Person), 5, MyPrintPerson);
#endif

}

int main() {
//    test01();
    //test02();
    //test03();
    test04();
    return EXIT_SUCCESS;
}