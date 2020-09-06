#define _CRT_SECURE_NO_WARNINGS
#pragma once //编译一次

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Teacher
{
    char *name;
    char **students;
};

int allocateSpace(struct Teacher ***temp)
{
    if (NULL == temp)
    {
        //错误码 不同错误码表示不同错误
        return -1;
    }

    struct Teacher **ts = malloc(sizeof(struct Teacher *) * 3);
    for (int i = 0; i < 3; ++i)
    {

        //给老师结构体指针分配空间
        ts[i] = malloc(sizeof(struct Teacher));

        //给老师名字分配空间
        ts[i]->name = malloc(sizeof(char) * 64);
        sprintf(ts[i]->name, "Teacher_%d", i + 1);

        //给学生指针分配内存
        ts[i]->students = malloc(sizeof(char *)* 4);
        for (int j = 0; j < 4; ++j)
        {
            ts[i]->students[j] = malloc(sizeof(char) * 64);
            sprintf(ts[i]->students[j],"%s_Stu_%d",ts[i]->name,j + 1);

        }


    }

    *temp = ts;

    return 0;
}

void printTeachers(struct Teacher **teachers)
{
    if (NULL == teachers)
    {
        return;
    }

    for (int i = 0; i < 3; ++i)
    {
        printf("%s\n", teachers[i]->name);
        for (int j = 0; j < 4; ++j)
        {
            printf("   %s\n",teachers[i]->students[j]);
        }
    }
}


void freeSpace(struct Teacher **teachers)
{
    if (NULL == teachers)
    {
        return;
    }

    for (int i = 0; i < 3; ++i)
    {

        if (teachers[i] == NULL)
        {
            continue;
        }

        if (teachers[i]->name != NULL)
        {
            free(teachers[i]->name);
            teachers[i]->name = NULL;
        }

        for (int j = 0; j < 4; ++j)
        {
            if (teachers[i]->students[j] != NULL)
            {
                free(teachers[i]->students[j]);
                teachers[i]->students[j] = NULL;
            }
        }

        free(teachers[i]->students);
        teachers[i]->students = NULL;


        free(teachers[i]);
        teachers[i] = NULL;
    }

    free(teachers);
    teachers = NULL;
}

void test()
{

    struct Teacher **teachers = NULL;

    int ret = 0;
    ret = allocateSpace(&teachers);
    if (ret < 0)
    {
        printf("allocateSpace 函数调用出错!\n");
        return;
    }

    //打印老师及其学生信息
    printTeachers(teachers);

    //释放内存
    freeSpace(teachers);
    teachers = NULL;

}


int main(){
    test();

    return EXIT_SUCCESS;
}