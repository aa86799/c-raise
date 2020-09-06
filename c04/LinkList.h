//
// Created by austin stone on 2020/9/6.
//

#ifndef C_RAISE_LINKLIST_H
#define C_RAISE_LINKLIST_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//定义节点数据类型
struct LinkNode {
    int data;
    struct LinkNode *next;
};

//初始化链表
struct LinkNode *Init_LinkList();

//在值为oldval的位置插入新的数据newval
void InsertByValue_LinkList(struct LinkNode *header, int oldval, int newval);

//删除值为val的结点
void RemoveByValue_LinkList(struct LinkNode *header, int delValue);

//遍历
void Foreach_LinkList(struct LinkNode *header);

//销毁
void Destroy_LinkList(struct LinkNode *header);

//清空
void Clear_LinkList(struct LinkNode *header);

#endif //C_RAISE_LINKLIST_H
