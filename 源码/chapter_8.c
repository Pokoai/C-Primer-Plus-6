// 按照横列打印字符
#include <stdio.h>
void display(int ch, int row, int column);

int main(void)
{
    int ch;
    int row, column;

    printf("Enter a character and two integers: ");
    while((ch = getchar()) != '\n') {
        // 跳过空字符，取得首个非空字符
        while((ch = getchar()) && isspace(ch))
            continue;
        scanf("%d %d", &row, &column);
        //去掉 \n
        while(getchar() != '\n')
            continue;
        display(ch, row, column);
        printf("Enter another character and two integers: ");
    }
    printf("Bey.\n");

    return 0;
}

void display(int ch, int row, int column)
{
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            putchar(ch);
        }
        putchar('\n');

    }
}

// 菜单例程
char getChoice(void)
{
    int ch;

    printf("Enter the letter of your choice:\n");
    printf("a. advice       b. bell\n");
    printf("c. count        q. quit\n");

    ch = getFirst();
    while(ch != 'a' && ch != 'b' && ch != 'c' && ch != 'q') {
        printf("Please respond with a, b, c, or q.\n");
        ch = getFirst();
    }
    return ch;
}

// 获取非空首字符
char getFirst(void)
{
    int ch;
    // 跳过空字符，针对混合字符和数字输入的情况
    while((ch = getchar()) == '\n')
        continue;
    // 跳过剩余字符
    while((getchar()) != '\n')
        continue;

    return ch;
}

// 复习题 8.3
#include <stdio.h>

int main(void)
{
    double count = 0;
    int ch;

    while((ch = getchar()) != EOF)
        count++;
    printf("The number of characters: %g", count);

    return 0;  
}

命令行：F:\Project\C\c primer plus 6>demo<input.txt>output.txt



// 8.1
#include <stdio.h>

int main(void)
{
    double count = 0;
    int ch;

    while((ch = getchar()) != EOF)
        count++;
    printf("The number of characters: %g", count);

    return 0;  
}



// 8.2 -- 法一
#include <stdio.h>

int main(void)
{
    int ch;
    int count = 0;

    while((ch = getchar()) != EOF){
        count++;
        // if(count % 10 == 0)  //放在这第一行只有9个
        // printf("\n"); 
        if(ch == '\n'){
            count = 0;
            printf("\\n: %-5d", ch);
        }         
        else if(ch == '\t')
            printf("\\t: %-5d", ch);
        else if(ch < 9)
            printf("\^%c: %-5d", 64 + ch, ch);
        else
            printf("%c: %-5d", ch, ch); 
        if(count % 10 == 0)
             printf("\n");      
    }
    return 0;
}



// 8.2 -- 法二
#include <stdio.h>
#define CTRL 64
#define COL 10
#define BEFORE_T 9

int main(void)
{
    int ch;
    int count = 0;

    while((ch = getchar()) != EOF){
        count++;
        if(ch == '\n' || ch == '\t')
            printf("%s", ch == '\n' ? "\\n" : "\\t");        
        else if(ch < BEFORE_T)
            printf("\^%c", ch + CTRL);
        else
            printf("%c", ch); 
        printf(":%-5d", ch); //统一打印ASC码
        if(ch == '\n')
            count = 0;
        if(count % COL == 0)
             printf("\n");      
    }

    return 0;
}


// 8.3 -- 法一
#include <stdio.h>

int main(void)
{
    int ch;
    int n_lower = 0, n_upper = 0;

    printf("Enter some texts:\n");
    while((ch = getchar()) != EOF){
        if(ch >= 'a' && ch <= 'z')
            n_lower++;
        if(ch >= 'A' && ch <= 'Z')
            n_upper++;
    }
    printf("Lower letters: %d, Upper letters: %d\n",
                n_lower, n_upper);

    return 0;
}


// 8.3 -- 法二
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch;
    int n_lower = 0, n_upper = 0;

    printf("Enter some texts:\n");
    while((ch = getchar()) != EOF){
        if(islower(ch))
            n_lower++;
        if(isupper(ch))
            n_upper++;
    }
    printf("Lowercase letters: %d, Uppercase letters: %d\n",
                n_lower, n_upper);

    return 0;
}



// 8.4
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
    int ch;
    int n_letters = 0;
    int n_words = 0;
    bool inword = false;

    printf("Enter some words:\n");
    while((ch = getchar()) != EOF){
        if(!isspace(ch) && !ispunct(ch))
            n_letters++;
        //单词开头
        if(!isspace(ch) && !ispunct(ch) && !inword){
            inword = true;
            n_words++;
        }
        if(isspace(ch) || ispunct(ch) && inword)
            inword = false;
    }
    printf("There %d words and %d letters.\n", n_words, n_letters);
    printf("Average number of letters per word: %g\n",
            (double)n_letters / (double)n_words);

    return 0;
}



// 8.5 -- 法一
#include <stdio.h>

int main(void)
{
    char ch;
    int start = 0;
    int end = 100;
    int guess;

    printf("Pick an intrger from 1 to 100. I will try to guess it.\n");
    printf("Repond with a y if my guess is right and with");
    printf("\nan L if it is lower and with U it is upper.\n");
    guess = (start + end) / 2;
    printf("Uh...is your nunber %d?\n", guess);
    while((ch = getchar()) != 'y'){
        while(getchar() != '\n')
            continue;
        if(ch == 'U'){
            end = guess;
            guess = (start + end) / 2;
            printf("Well, then, is it %d?\n", guess);
        }          
        else if(ch == 'L'){
            start = guess;
            guess = (start + end) / 2;
            printf("Well, then, is it %d?\n", guess);
        }
        else
            printf("Sorry, I understand only y, L or U.\n");         
    }
    printf("I knew I could do it!");

    return 0;
}



// 8.5 -- 法二
#include <stdio.h>
#include <stdbool.h>
#define HIGH 100
#define LOW 0

int main(void)
{
    char ch;
    int start = LOW;
    int end = HIGH;
    int guess;
    bool input_right = true;

    guess = (start + end) / 2;
    printf("Pick an intrger from 1 to 100. I will try to guess it.\n");
    printf("Repond with a y if my guess is right and with");
    printf("\nan L if it is lower and with U it is upper.\n");
    printf("Uh...is your nunber %d?\n", guess);
    while((ch = getchar()) != 'y'){
        input_right = true;
        while(getchar() != '\n')
            continue;
        if(ch == 'U')
            end = guess;
        else if(ch == 'L')
            start = guess;
        else{
            printf("Sorry, I understand only y, L or U.\n");
            input_right = false;
        }
        if(input_right){
            guess = (start + end) / 2;
            printf("Well, then, is it %d?\n", guess); 
        }          
    }
    printf("I knew I could do it!");

    return 0;
}



// 8.6 -- 法一
#include <stdio.h>
#include <ctype.h>
char get_first(void);

int main(void)
{
    
    putchar(get_first());

    return 0;
}

char get_first(void)
{
    char ch;
    while(isspace(ch = getchar()))
        continue;
    while(getchar() != '\n')
        continue;

    return ch;
}



// 8.6 -- 法二
#include <stdio.h>
char get_first(void);

int main(void)
{
    
    putchar(get_first());

    return 0;
}

char get_first(void)
{
    char ch;
    
    do{
        ch = getchar();
    }while(ch == ' ' || ch == '\n' || ch == '\t');
    
    return ch;
}



// 8.7 -- 7.8型2 (法4)：循环计算正确输入后的各值
#include <stdio.h>
#include <stdbool.h>
void print(void);
char get_choice(void);
char get_first(void);
#define PAY_RATE1 8.75
#define PAY_RATE2 9.33
#define PAY_RATE3 10.00
#define PAY_RATE4 11.20
#define TIME_BASE 40
#define OVERTIME 1.5
#define BREAK1 300
#define BREAK2 450
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25

int main(void)
{
    int choice;
    double pay_rate;
    double hours;
    double gross, tax, net;

    while((choice = get_choice()) != 'q'){
        switch(choice){
            case 'a': pay_rate = PAY_RATE1;
                      break;
            case 'b': pay_rate = PAY_RATE2;
                      break;
            case 'c': pay_rate = PAY_RATE3; 
                      break;
            case 'd': pay_rate = PAY_RATE4; 
                      break;
            default:  printf("Program error!\n");
                      break;
        }
        printf("Enter your work hours in a week: ");
        scanf("%lf", &hours);
        if(hours > TIME_BASE)
            hours = TIME_BASE + (hours - TIME_BASE) * OVERTIME;
        gross = hours * pay_rate;
        if(gross < BREAK1)
            tax = gross * RATE1;
        else if(gross < BREAK2)
            tax = BREAK1 * RATE1 + (gross - BREAK1) * RATE2;
        else
            tax = BREAK1 * RATE1 + (BREAK2 - BREAK1) * RATE2\
                + (gross - BREAK2) * RATE3;
        net = gross - tax;
        printf("Gross: %.2lf, tax: %.2lf, net: %.2lf\n", gross, tax, net);      
    }
 
    return 0;
}

void print(void)
{
    printf("\n*****************************************************************\n");
    printf("Enter the letter corresponding to the desired pay rate or action:\n");
    printf("a) $8.75/hr         b) $9.33/hr\n");
    printf("c) $10.00/hr        d) $11.20/hr\n");
    printf("q) quit\n");
    printf("******************************************************************\n");
}

char get_choice(void)
{
    int ch;
    
    print();
    ch = get_first();
    while((ch < 'a' || ch > 'd') && ch != 'q'){
        printf("Please respond with a, b, c, d or q.\n");
        ch = get_first();
    }
    return ch;
}

char get_first(void)
{
    int ch;
    
    // ch = getchar();
    // whilech == ' ' || ch == '\n' || ch == '\t')
    //     ch = getchar();

    //跳过非空字符
    do{
        ch = getchar();
    }while(ch == ' ' || ch == '\n' || ch == '\t');
    //舍弃剩余字符
    while(getchar() != '\n')
        continue;
    
    return ch;
}



// 8.8
#include <stdio.h>
#include <stdbool.h>
void show_menu(void);
char menu_choice(void);
char get_first(void);
float input_number(void);

int main(void)
{
    char choice;
    float num1, num2;

    while((choice = menu_choice()) != 'q'){
        //输入两个浮点数
        printf("Enter first number: ");
        num1 = input_number();
        printf("Enter second number: ");
        num2 = input_number();

        //加减乘除
        switch(choice){
            case 'a': printf("%g + %g = %g\n", num1, num2, num1 + num2);
                      break;
            case 's': printf("%g - %g = %g\n", num1, num2, num1 - num2);
                      break;
            case 'm': printf("%g * %g = %g\n", num1, num2, num1 * num2);
                      break;
            case 'd': 
                    if(!num2){
                        printf("Enter a number other than 0: ");
                        num2 = input_number();
                    }
                    printf("%g / %g = %g\n", num1, num2, num1 / num2);
                        break;
            default:  printf("Program error!\n");
                      break;    
        }
    }
    printf("Bey.");
    
    return 0;
}

void show_menu(void)
{
    printf("Enter the operation of your choice:\n");
    printf("a. add          s. subtract\n");
    printf("m. multiply     d. divider\n");
    printf("q. quit\n");
}

char menu_choice(void)
{
    int ch;
    
    show_menu();
    ch = get_first();
    while(ch != 'a' && ch != 's' && ch != 'm' && ch != 'd' && ch != 'q'){
        printf("Please respond with a, s, m, d or q.\n");
        ch = get_first();   //这里需要再一次使用get_first()获得输入值
    }
    return ch;
}

char get_first(void)
{
    int ch;

    //跳过非空字符
    do{
        ch = getchar();
    }while(ch == ' ' || ch == '\n' || ch == '\t');
    //舍弃剩余字符
    while(getchar() != '\n')
        continue;
    
    return ch;
}

float input_number(void)
{
    float num;
    char ch;

    while(scanf("%f", &num) != 1){
        while((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not an number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
        //scanf("%f", &num);  这里不能再使用scanf()获取输入值了，因为while()里已经包含了
    }
    while(getchar() != '\n')
        continue;

    return num;
}

// 8.8 修改版
#include <stdio.h>
#include <ctype.h>

char get_choice();
char get_first();
float get_float();


int main(void)
{
    float num1, num2;
    float result;
    char choice;
    char cal;

    while((choice = get_choice()) != 'q'){
        printf("Enter first number: ");
        num1 = get_float();
        printf("Enter second number: ");
        num2 = get_float();

        switch(choice) {
            case 'a': result = num1 + num2; cal = '+'; break;
            case 's': result = num1 - num2; cal = '-'; break;
            case 'm': result = num1 * num2; cal = '*'; break;
            case 'd': 
                if(num2 == 0) {
                    printf("Enter a number other than 0: ");
                    num2 = get_float();
                }
                result = num1 / num2;
                cal = '/';
                break;
        }
        printf("%g %c %g = %g\n", num1, cal, num2, result);
    
    }
    printf("Bey.\n");

    return 0;    

}

char get_choice()
{
    int ch;

    printf("Enter the operation of your choice:\n");
    printf("a. add          s. subtract\n");
    printf("m. multiply     d. divide\n");
    printf("q. quit\n");

    ch = get_first();
    while(ch != 'a' && ch != 's' && ch != 'm' && ch != 'd' && ch != 'q') {
        printf("Error! Please enter again: ");
        ch = get_first();
    }
    return ch;
}

char get_first()
{
    int ch;
    // 跳过空字符，取得首个非空字符
    while((ch = getchar()) && isspace(ch))
        continue;
    while(getchar() != '\n')
        continue;

    return ch;
}

float get_float()
{
    float num;
    char ch;

    while(scanf("%f", &num) != 1) {
        while((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not a number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
    }
    // while(getchar() != '\n')
    //     continue;
        
    return num;
}