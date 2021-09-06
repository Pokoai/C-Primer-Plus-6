/*
 * @Description: c-primer-plus 第十四章课本重要程序
 * @Author: Adair Hu
 * @Github: https://github.com/adairhu
 * @Date: 2021-09-03 10:17:50
 * @LastEditTime: 2021-09-07 07:12:35
 * @FilePath: \review_c-primer-pluse:\Project\C\C-Primer-Plus-6\源码\chapter_14.c
 * 『戒急戒躁，心装大棋。日日耕耘，精进成长。』
 */

// 书中程序 14.1 book.c
#include<stdio.h>
#include <string.h>
#define MAXTITL 41
#define MAXAUTH 31

char * s_gets(char * st, int n);

struct book {
    char title[MAXTITL];
    char author[MAXAUTH];
    float value;
};


int main(void)
{
    struct book library;

    printf("Please enter the book title.\n");
    s_gets(library.title, MAXTITL);
    printf("Now enter the author.\n");
    s_gets(library.author, MAXAUTH);
    printf("Now enter the value.\n");
    scanf("%f", &library.value);
    printf("%s by %s: $%.2f\n", library.title, library.author, library.value);

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

// 书中程序 14.2 manybook.c
#include<stdio.h>
#include <string.h>
#define MAXTITL 41
#define MAXAUTH 31
#define SIZE 2

char * s_gets(char * st, int n);

struct book {
    char title[MAXTITL];
    char author[MAXAUTH];
    double value;
};

int main(void)
{
    struct book library[SIZE];
    int count = 0;

    puts("Please enter the book title: ");
    while(count < SIZE && s_gets(library[count].title, MAXTITL) && library[count].title[0] != '\0') {
        puts("Please enter the book author: ");
        s_gets(library[count].author, MAXAUTH);
        puts("Please enter the book value: ");
        scanf("%lf", &library[count++].value);
        while(getchar() != '\n')
            continue;
        if(count < SIZE)
            puts("Please enter next book title: ");
    }
    if(count > 0) {
        for(int i = 0; i < count; i++) {
            printf("%d: %s by %s: $%.2f\n\n", i, library[i].title, library[i].author, library[i].value);
        }   
    }
    else 
        puts("No books? Too bad");

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

// 书中程序 14.14 booksave.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXTITL 41
#define MAXAUTH 41
#define SIZE 5

char * s_gets(char * st, int n);

struct book {
    char title[MAXTITL];
    char author[MAXAUTH];
    double value;
};

int main(void)
{
    struct book library[SIZE];
    int count = 0;
    int filecount;
    FILE * pbooks;
    int size = sizeof(struct book);

    if((pbooks = fopen("book.dat", "a+b")) == NULL) {
        fputs("Can`t open book.dat file\n", stderr);
        exit(1);
    }
    rewind(pbooks);
    // 读取文件内容
    while(count < SIZE && fread(&library[count], size, 1, pbooks) == 1) {
        if(count == 0)
            puts("Current contens of book.dat:");
        printf("%d: %s by %s: $%.2lf\n",count+1, library[count].title, library[count].author, library[count].value);
        count++;
    }
    filecount = count;
    if(count == SIZE) {
        puts("The book.dat file is full.");
        exit(2);
    }
    // 开始写入文件
    puts("Please enter the book title: ");
    while(count < SIZE && s_gets(library[count].title, MAXTITL) && library[count].title[0] != '\0') {
        puts("Please enter the book author: ");
        s_gets(library[count].author, MAXAUTH);
        puts("Please enter the book value: ");
        scanf("%lf", &library[count++].value);
        while(getchar() != '\n')
            continue;
        if(count < SIZE)
            puts("Please enter next book title: ");
    }
    if(count > 0) {
        puts("Here is the list of book:");
        for(int i = 0; i < count; i++) {
            printf("%d: %s by %s: $%.2f\n", i+1, library[i].title, library[i].author, library[i].value);
        }
        fwrite(&library[filecount], size, count - filecount, pbooks);   
    }
    else 
        puts("No books? Too bad");

    puts("Bey.\n");
    fclose(pbooks);
    
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