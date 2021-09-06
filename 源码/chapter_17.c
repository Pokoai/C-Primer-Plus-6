/*
 * @Description: c-primer-plus 第十七章课本重要程序
 * @Author: Adair Hu
 * @Github: https://github.com/adairhu
 * @Date: 2021-09-06 21:02:26
 * @LastEditTime: 2021-09-07 07:14:03
 * @FilePath: \review_c-primer-pluse:\Project\C\C-Primer-Plus-6\源码\chapter_17.c
 * 『戒急戒躁，心装大棋。日日耕耘，精进成长。』
 */


// 书中程序 17.2 film2.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 40

struct film {
    char title[SIZE];
    int rating;
    struct file * next;
};

char * s_gets(char * st, int n);
void eatline();

int main(void)
{
    struct film * head = NULL;
    struct film * current, * prev;
    char input[SIZE];

    puts("Enter movie title.");
    // 向链表存储
    while(s_gets(input, SIZE) != NULL && input[0] != '\0') {
        current = (struct film *)malloc(sizeof(struct film));
        if(head == NULL)
            head = current;
        else 
            prev -> next = current;
        current -> next = NULL;
        strcpy(current -> title, input);
        puts("Enter rating.");
        scanf("%d", &(current -> rating));
        eatline();

        prev = current;
        puts("Enter next movie title.");
    }
    // 显示链表
    if(head == NULL) 
        puts("No data entered.");
    else 
        puts("Here is movie list:");
    current = head;
    while(current != NULL) {
        printf("%s: %d\n", current -> title, current -> rating);
        current = current -> next;
    } 
    // 释放内存
    current = head;
    while(current != NULL) {
        prev = current;
        current = current -> next;
        free(prev);
    }
    puts("Bey.");

    return 0;
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