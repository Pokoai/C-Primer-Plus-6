/*
 * @Description: C语言实现链表结构，单文件结构
 * @Author: Adair Hu
 * @Github: https://github.com/adairhu
 * @Date: 2021-09-07 11:23:55
 * @LastEditTime: 2021-09-07 15:17:37
 * @FilePath: \review_c-primer-pluse:\Project\C\C-Primer-Plus-6\源码\C语言实现链表\list_all.c
 * 『戒急戒躁，心装大棋。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> //提供 malloc()
#include <string.h> //提供 strch()

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
typedef Node * List; // List 为指向节点的指针

void showmovies(Item item);
char * s_gets(char * st, int n);
void eatline();



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



int main(void)
{
    List movies;
    Item temp;

    // 初始化链表
    InitializeList(&movies);
    // 确定链表是否已满
    if(ListIsFull(&movies)) {
        fprintf(stderr, "Memory Full\n");
        exit(1);
    }
    // 向链表中存储信息
    puts("Enter first movie title:");
    // 获取输入信息
    while(s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0') {
        puts("Enter your rating <0-10>:");
        scanf("%d", &temp.rating);
        eatline();
        // 将信息存储到链表中
        if(!AddItem(temp, &movies)) {
            fprintf(stderr, "Problem allocating memory\n");
            break;
        }
        // 检查链表是否已满，如果满了就无法继续存储信息，那么就终止输入
        if(ListIsFull(&movies)) {
            fprintf(stderr, "The list is now full.\n");
            break;
        }
        puts("Enter next movie title(empty line to quit):");
    }
    // 显示链表内容
    if(ListIsEmpty(&movies))
        puts("No data entered.");
    else {
        puts("Here is the movie list:");
        Traverse(&movies, showmovies);
    }
    printf("You entered %d movies.\n", ListItemCount(&movies));
    // 释放空间
    EmptyList(&movies);
    puts("Bey.");

    return 0;
    
}

void showmovies(Item item)
{
    printf("Movie: %s  rating: %d\n", item.title, item.rating);
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if(ret_val) {
        // 输入字符数小于 n,则读取了完整的字符串,那么最后有个换行符，需要替换为 \0
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        // 输入字符数大于 n,则还有字符在缓存区未读入，需要丢弃剩余字符
        else {
            while(getchar() != '\n')
                continue;
        }

        return ret_val;
        
    }
}

void eatline()
{
    while(getchar() != '\n')
        continue;
}




