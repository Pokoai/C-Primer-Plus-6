// 11.1
#include<stdio.h>
#include<string.h>
#define LEN 10
char * get_string(int n);

int main(void)
{
    char *pt; 

    printf("Enter %d characters:\n", LEN);
    pt = get_string(LEN);
    puts(pt);

    return 0;
    
}

char * get_string(int n)
{
    char * str;
    int i = 0;

    while(i < n && (str[i] = getchar()) != EOF)
        i++;

    return str;
}


// 11.1 法2
#include<stdio.h>
#include<string.h>
#define SIZE 10
char * get_string(char * st, int n);

int main(void)
{
    char test[SIZE];

    puts("Enter a string:");
    get_string(test, SIZE);
    puts(test);

    return 0;
}

char * get_string(char * st, int n)
{
    int i = 0;

    while(i < n && (st[i] = getchar()) != EOF)
        i++;

    return st;
}


// 11.2
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 10
char * get_string(char * st, int n);

int main(void)
{
    char test[SIZE];

    puts("Enter a string:");
    get_string(test, SIZE);
    puts(test);

    return 0;
}

char * get_string(char * st, int n)
{
    int i = 0;
    char ch;

    while(i < n && (ch = getchar()) != EOF && !isspace(ch) ){
        st[i] = ch;
        i++;
    }

    return st;
}



// 11.3
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 20
void get_word(char word[]);

int main(void)
{
    char test[SIZE];

    puts("Enter a string:");
    get_word(test);
    puts(test);

    return 0;
}

void get_word(char word[])
{
    char ch;

    //跳过空字符
    while(isspace(ch = getchar()))
        continue;
        
        *word++ = ch;
    while(!isspace((ch = getchar())))
        *word++ = ch;
}



// 11.3
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 20
char * get_word(char word[]);

int main(void)
{
    char test[SIZE];

    puts("Enter a string:");
    get_word(test);
    puts(test);

    return 0;
}

char * get_word(char word[])
{
    char ch;

    //跳过空白字符
    while(isspace(ch = getchar()))
        continue;

    *word++ = ch;  //存储单词第一个字符

    //存储单词，直到空白字符停止
    while(!isspace((ch = getchar())))
        *word++ = ch;

    //*word = '\0';  //若要求输出到字符串，就需要加这一句

    //舍弃剩余字符
    while(getchar() != '\n')
        continue;

    return word;
}



// 11.4
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 20
char * get_word(char word[]);

int main(void)
{
    char test[SIZE];

    puts("Enter a string:");
    get_word(test);
    puts(test);

    return 0;
}

char * get_word(char word[]， int n)
{
    char ch;
    int ct = 0;

    //跳过空白字符
    while(isspace(ch = getchar()))
        continue;

    *word++ = ch;  //存储单词第一个字符

    //存储单词，直到空白字符停止
    while(ct < n && !isspace((ch = getchar()))){
        ct++;
        *word++ = ch;
    }

    //舍弃剩余字符
    while(getchar() != '\n')
        continue;

    return word;
}



// 11.5
#include<stdio.h>
#include<string.h>
#define SIZE 80
#define STOP "quit\n"  //因为fgets()会自动在输入字符后加换行符
char * str_chr(char * str, char ch);

int main(void)
{
    char test[SIZE];
    char ch;
    char * pt;

    puts("Input a string (type quit to quit):");
    while(fgets(test, SIZE, stdin) != NULL && test[0] != '\n' && strcmp(test, STOP) != 0){
        puts("Input a character:");
        ch = getchar();

        // 消除缓冲区里的换行符，为下一轮循环做好准备
        while(getchar() != '\n')
            continue;

        pt = str_chr(test, ch);
        if(pt)
            printf("Find! The string start with the %c:\n"
            "%p\n\n", ch, pt);
        else
            printf("Can't find!\n\n");
        puts("Input a string again (type quit to quit):");
        
    } 
    printf("Bey."); 

    return 0;
}

char * str_chr(char * str, char ch)
{
    char * pt;

    while(*str++){
        if(*str == ch){
            pt = str;
            break;
        }
        else 
            pt = NULL;
    }
    return pt;
}