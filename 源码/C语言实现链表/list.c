/*
 * @Description: C语言实现链表结构-源文件，2.实现接口
 * @Author: Adair Hu
 * @Github: https://github.com/adairhu
 * @Date: 2021-09-07 11:23:44
 * @LastEditTime: 2021-09-07 14:32:42
 * @FilePath: \review_c-primer-plus\list.c
 * 『戒急戒躁，心装大棋。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include <stdlib.h> //提供 malloc()
#include "list.h"

static void CopyToNode(Item item, Node * pnode);

/**
 * @description: 初始化链表为空
 * @param {List *} plist
 * @return {*}
 */
void InitializeList(List * plist) 
{
    *plist = NULL;
}

/**
 * @description: 确定链表是否为空
 * @param {List *} plist
 * @return {*}
 */
bool ListIsEmpty(const List * plist)
{
    if(*plist == NULL)
        return true;
    else 
        return false;
}

/**
 * @description: 确定链表是否已满
 * @param {List *} plist
 * @return {*}
 */
bool ListIsFull(const List * plist)
{
    Node * pnode;

    pnode = (Node *)malloc(sizeof(Node));
    if(pnode == NULL)
        return true;
    else 
        return false;
    free(pnode);
}

/**
 * @description: 确定链表中的项数
 * @param {List *} plist
 * @return {*}
 */
unsigned int ListItemCount(const List * plist)
{
    unsigned int count = 0;

    Node * pnode = *plist;

    while(pnode != NULL) {
        ++count;
        pnode = pnode -> next;
    }

    return count;
}

/**
 * @description: 向链表的末尾添加项
 * @param {Item} item
 * @param {List *} plist
 * @return {*}
 */
bool AddItem(Item item, List * plist)
{
    Node * pnew;
    Node * scan = *plist;

    pnew = (Node *)malloc(sizeof(Node));
    if(pnew == NULL) {
        //fprintf(stderr, "Error!Bey.\n");
        return false;
    }
    CopyToNode(item, pnew);
    pnew -> next = NULL;
    // 头指针为空，则直接把 pnew 赋值给头指针
    if(scan == NULL)
        *plist = pnew;
    // 头指针非空，则找到链表的尾指针，把 pnew 赋值给尾指针
    else {
        while(scan -> next != NULL) // 容易出错
            scan = scan -> next;
        scan -> next = pnew;
    }         
        
    return true;
}

/**
 * @description: 遍历链表，对其中的每一项执行 pfun 函数操作
 * @param {List *} plist
 * @param {Item} item
 * @return {*}
 */
void Traverse(const List * plist, void (*pfun)(Item item))
{
    Node * pnode = *plist;

    while(pnode != NULL) {
        (*pfun)(pnode -> item);
        pnode = pnode -> next;
    }
}

/**
 * @description: 释放内存空间
 * @param {List *} plist
 * @return {*}
 */
void EmptyList(List * plist)
{
    Node * psave;

    while(*plist != NULL) {
        psave = (*plist) -> next;
        free(*plist);
        *plist = psave;
    }
}


/**
 * @description: 把一个项拷贝到节点中。局部函数，仅在 list.c 文件中有效
 * @param {Item} item
 * @param {Node *} pnode
 * @return {*}
 */
static void CopyToNode(Item item, Node * pnode)
{
    pnode -> item = item;
}

