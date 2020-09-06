//
// Created by austin stone on 2020/9/6.
//

#include "LinkList.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    //输入 1,2,3,4
    struct LinkNode *head = Init_LinkList();
    Foreach_LinkList(head);

    //输入 3, 10
    InsertByValue_LinkList(head, 3, 10);
    Foreach_LinkList(head);

    RemoveByValue_LinkList(head, 10);
    Foreach_LinkList(head);

    Clear_LinkList(head);
    Foreach_LinkList(head);

    Destroy_LinkList(head);
    printf("%d", head == NULL); //虽然已free，但还是非null
//    free(head); //error.  已 free， 再次free，error。
//    Foreach_LinkList(head); //可以输出
    head = NULL;//需要 置空；在某个函数内部置空不行
    return EXIT_SUCCESS;
}

