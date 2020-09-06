//
// Created by austin stone on 2020/9/6.
//

#include "LinkList.h"

//初始化链表
struct LinkNode *Init_LinkList() {
    struct LinkNode *head = malloc(sizeof(struct LinkNode));
    head->data = -100;
    head->next = NULL; //虚拟头节点

    struct LinkNode *p = head;

    int input = -1;
    while (1) {
        printf("输入要插入的数据\n");
        scanf("%d", &input);
        if (input == -1) {
            break;
        }
        struct LinkNode *newNode = malloc(sizeof(struct LinkNode));
        newNode->data = input;
        newNode->next = NULL;
        p->next = newNode;
        p = newNode;
    }
    return head;
}

//在值为oldval的位置插入新的数据newval
void InsertByValue_LinkList(struct LinkNode *header, int oldval, int newval) {
    if (header == NULL) return;
    struct LinkNode *p = header;
    struct LinkNode *cur = p->next;
    while (cur != NULL) {
        if (cur->data == oldval) {
            struct LinkNode *newNode = malloc(sizeof(struct LinkNode));
            newNode->data = newval;
            newNode->next = cur;
            p->next = newNode;
            break;
        } else {
            p = cur;
            cur = cur->next;
        }
    }
}

//删除值为val的结点
void RemoveByValue_LinkList(struct LinkNode *header, int delValue) {
    if (header == NULL) return;
    struct LinkNode *p = header;
    struct LinkNode *cur = p->next;
    while (cur != NULL) {
        if (cur->data == delValue) {
            p->next = cur->next;
            free(cur);
            cur = NULL;
            break;
        } else {
            p = cur;
            cur = cur->next;
        }
    }
}

//遍历
void Foreach_LinkList(struct LinkNode *header) {
    while (header != NULL) {
        printf("%d ", header->data);
        header = header->next;
    }
    printf("\n");
}

//销毁
void Destroy_LinkList(struct LinkNode *header) {
    if (NULL == header) {
        return;
    }
    struct LinkNode *cur = header;
    while (cur != NULL) {
        struct LinkNode *p = cur->next;
        free(cur);
        cur = p;
    }
}

//清空
void Clear_LinkList(struct LinkNode *header) {
    if (NULL == header) {
        return;
    }
    Destroy_LinkList(header->next); //销毁了 header 后面所有的节点；  header本身还是一个虚拟的头结点
    header->next = NULL;
}
