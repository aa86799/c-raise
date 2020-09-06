#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//链表结点类型定义
struct LinkNode {
    int data;
    struct LinkNode *next;
};

void test() {
    struct LinkNode node1 = {10, NULL};
    struct LinkNode node2 = {20, NULL};
    struct LinkNode node3 = {30, NULL};
    struct LinkNode node4 = {40, NULL};
    struct LinkNode node5 = {50, NULL};
    struct LinkNode node6 = {60, NULL};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;

    //如何遍历链表？
    //先定义一个辅助指针变量
    struct LinkNode *pCurrent = &node1;
    while (pCurrent != NULL) {
        printf("%d ", pCurrent->data);

        //指针移动到下一个元素的首地址
        pCurrent = pCurrent->next;
    }
}

int main() {
    test();
    return EXIT_SUCCESS;
}
