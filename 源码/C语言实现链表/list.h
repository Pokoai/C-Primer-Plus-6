/*
 * @Description: C语言实现链表结构-头文件，1.建立接口
 * @Author: Adair Hu
 * @Github: https://github.com/adairhu
 * @Date: 2021-09-07 11:23:55
 * @LastEditTime: 2021-09-07 17:05:41
 * @FilePath: \review_c-primer-pluse:\Project\C\C-Primer-Plus-6\源码\C语言实现链表\list.h
 * 『戒急戒躁，心装大棋。日日耕耘，精进成长。』
 */

#ifndef LIST_H_
#define LIST_H_

#include <stdbool.h>

#define TSIZE 45

// 数据存储结构
struct film {
    char title[TSIZE];
    int rating;
};

typedef struct film Item; // Item 为新定义的一种数据类型，类似于 int

// 创建一个节点模板
typedef struct node {
    Item item;
    struct node * next;
} Node;

// 继续抽象
typedef Node * List; // List 为指向链表头节点的指针

/**
 * @description: 初始化链表为空
 * @param {List *} plist
 * @return {*}
 */
void InitializeList(List * plist);

/**
 * @description: 确定链表是否为空
 * @param {List *} plist
 * @return {*}
 */
bool ListIsEmpty(const List * plist);

/**
 * @description: 确定链表是否已满
 * @param {List *} plist
 * @return {*}
 */
bool ListIsFull(const List * plist);

/**
 * @description: 确定链表中的项数
 * @param {List *} plist
 * @return {*}
 */
unsigned int ListItemCount(const List * plist);

/**
 * @description: 向链表的末尾添加项
 * @param {Item} item
 * @param {List *} plist
 * @return {*}
 */
bool AddItem(Item item, List * plist);

/**
 * @description: 遍历链表，对其中的每一项执行 pfun 函数操作
 * @param {List *} plist
 * @param {Item} item
 * @return {*}
 */
void Traverse(const List * plist, void (*pfun)(Item item));

/**
 * @description: 释放内存空间
 * @param {List *} plist
 * @return {*}
 */
void EmptyList(List * plist);

#endif




