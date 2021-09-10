/*
 * @Description: C语言实现链表结构-源文件，2.实现接口
 * @Author: Adair Hu
 * @Github: https://github.com/adairhu
 * @Date: 2021-09-07 11:23:44
 * @LastEditTime: 2021-09-10 11:07:00
 * @FilePath: \review_c-primer-pluse:\Project\C\C-Primer-Plus-6\源码\C语言实现链表\list.c
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
// 初始化就是要改变链表头指针，使其指向 NULL
// 而要改变实参的值，就要向函数传递实参的地址，即传递指向实参的指针
// 这里函数的参数必须是指向头指针的指针，即 List * plist;
void InitializeList(List * plist) 
{
    *plist = NULL; // plist是指向链表头指针的指针
}

/**
 * @description: 确定链表是否为空
 * @param {List *} plist
 * @return {*}
 */
bool ListIsEmpty(const List * plist) // 加 const 修饰符，表明不修改头指针的内容 *plist
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
    //首先为新节点分配内存空间
    pnew = (Node *)malloc(sizeof(Node));
    if(pnew == NULL) {  
        //fprintf(stderr, "Error!Bey.\n");
        return false;
    }
    CopyToNode(item, pnew); // 创建一个新节点，将新值item存储进新的节点
    pnew -> next = NULL; // 节点内有两项，第一项已经存储了item，完毕；第二项存储 NULL;即完成新节点的初始赋值
    // 头指针为空，则直接把 pnew 赋值给头指针
    if(*plist == NULL)
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
        psave = (*plist) -> next; // -> 优先级 高于 *
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

