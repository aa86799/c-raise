#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Person {
    char *name;
    int age;
};

//分配内存
struct Person** allocateSpace() {
    struct Person **temp = malloc(sizeof(struct Person *) * 3);

    for (int i = 0; i < 3; ++i) {
        temp[i] = malloc(sizeof(struct Person));

        temp[i]->name = malloc(sizeof(char) * 64);

        sprintf(temp[i]->name, "Name_%d", i + 1);

        temp[i]->age = 100 + i;
    }

    return temp;
}

//打印
void printPerson(struct Person **person) {
    if (NULL == person) {
        return;
    }

    for (int i = 0; i < 3; ++i) {
        printf("Name:%s Age:%d\n", person[i]->name, person[i]->age);
    }
}

//释放内存, 先释放字符串指针，再释放结构体元素指针，再释放结构体 数组指针(二级指针)
void freeSpace(struct Person **person) {
    if (NULL == person) {
        return;
    }

    for (int i = 0; i < 3; ++i) {
        if (person[i] == NULL) {
            continue;
        }

        if (person[i]->name != NULL) {
            printf("Name:%s的内存被释放!\n", person[i]->name);
            free(person[i]->name);
            person[i]->name = NULL;
        }

        free(person[i]);
        person[i] = NULL;
    }

    free(person);
    person = NULL;
}

void test() {
    struct Person **person = NULL;
    person = allocateSpace();
    printPerson(person);
    freeSpace(person);
    person = NULL;
}

int main() {
    test();
    return EXIT_SUCCESS;
}