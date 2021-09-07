/*
 * @Description: C语言实现链表结构-3.使用接口
 * @Author: Adair Hu
 * @Github: https://github.com/adairhu
 * @Date: 2021-09-07 13:07:12
 * @LastEditTime: 2021-09-07 14:40:06
 * @FilePath: \review_c-primer-plus\film.c
 * 『戒急戒躁，心装大棋。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include <stdlib.h> //提供 exit()
#include <string.h> //提供 strch()
#include "list.h"

void showmovies(Item item);
char * s_gets(char * st, int n);
void eatline();


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