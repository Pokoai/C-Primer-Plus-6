/*
 * @Description: c-primer-plus 第二章课后编程题解答
 * @Author: Adair Hu
 * @Github: https://github.com/adairhu
 * @Date: 2021-06-29 20:44:32
 * @LastEditTime: 2021-06-29 20:56:04
 * @FilePath: \review_c-primer-plusf:\Project\C\C-Primer-Plus-6\源码\chapter_2.c
 * 『戒急戒躁，心有大棋。日日耕耘，精进成长。』
 */

//2.1
#include <stdio.h>
int main(void)
{
    printf("Gustav Mahler\n"); 

    printf("Gustav\nMahle\n");  

    printf("Gustav");
    printf(" Mahler");

    return 0;
}


// 2.2
#include <stdio.h>
int main(void)
{
    printf("My name is Guyuehu.\n");
    printf("I am in Hangzhou.\n");

    return 0;
}


// 2.3
#include <stdio.h>
int main(void)
{
    int age = 24;

    printf("I am %d years old, and I have born %lu days.",
            age, age * 365 );

    return 0;
}


// 2.4
#include <stdio.h>

void jolly(void);
void deny(void);

int main(void)
{
    jolly();
    jolly();
    jolly();

    deny();

    return 0;
}

void jolly(void)
{
    printf("For he's a jolly good fellow!\n");
}

void deny(void)
{
    printf("Which nobody can deny!\n");
}


//2.8
#include <stdio.h>

void one_three(void);
void two(void);

int main(void)
{
    printf("starting now:\n");
    one_three();
    printf("three\ndown!");

    return 0;
}

void one_three(void)
{
    printf("one\n");
    two();
}

void two(void)
{
    printf("two\n");
}