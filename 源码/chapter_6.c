// 6.1
#include <stdio.h>
#define SIZE 26

int main(void)
{
    char alpha[SIZE];
//    char ch;
    int i;

    // for(ch = 'a', i = 0; ch <= 'z'; ch++,  i++)
    //     alpha[i] = ch;
    for (i = 0; i < SIZE; i++)
        alpha[i] = 'a' + i;
    for(i = 0; i < SIZE; i++)
        printf("%3c", alpha[i]);

    return 0;
}

// 6.1-2
 #include <stdio.h>

 int main(void)
 {
     char zimu[26];

     for(int i = 0; i < 26; i++) {
         zimu[i] = 'a' + i;
     }

     printf("%s\n", zimu);
     
     for(int j = 0; j < 26; j++) {
         printf("%c", zimu[j]);
     }
     
     return 0;
}


// 6.2
#include <stdio.h>
#define ROW 5

int main(void)
{
    int row, column;

    for(row = 0; row < ROW; row++){
        for(column = 0; column <= row; column++)
            printf("$");
        printf("\n");
    }

    return 0;
}


// 6.3
#include <stdio.h>
#define ROW 6

int main(void)
{
    int row, column;
    for(row = 0; row < ROW; row++){
        for(column = 0; column <= row; column++)
            printf("%c", 'F' - column);
        printf("\n");
    }

    return 0;
}


// 6.4
#include <stdio.h>
#define ROW 6

int main(void)
{
    int row, column;
    char alpha = 'A';

    for(row = 0; row < ROW; row++){
        for(column = 0; column <= row; column++){
            printf("%c", alpha);
            alpha++;
        }
        printf("\n");
    }

    return 0;
}


// 6.5
#include <stdio.h>
#define ROW 5

int main(void)
{
    int row, column;
    char alpha;
    int count;

    printf("Enter a alphabet: ");
    scanf("%c", &alpha); 
    count = alpha - 'A';
    for(row = 0; row < ROW; row++){
        for(column = 0; column <= count - row; column++)
            printf(" ");        //打印空格
        for(column=0; column <= row; column++)
            printf("%c", 'A' + column); //打印字母升序
        for(column = row; column > 0; column--)
            printf("%c", 'A' + column - 1); //打印字母降序
        printf("\n");
    }

    return 0;
}


// 6.7
#include <stdio.h>
#include <string.h>
#define SIZE 20

int main(void)
{
    char word[SIZE];

    printf("Enter a word: ");
    scanf("%s", word);
    for(int i = strlen(word); i >= 0; i--)
        printf("%c", word[i]);

    return 0;
}


// 6.8
#include <stdio.h>

int main(void)
{
    float n1, n2, result;

    printf("Enter two numbers: ");
    while(scanf("%f %f", &n1, &n2) == 2){
        result = (n1 - n2) / (n1 * n2);
        printf("The result is: %.3f\n", result);
        printf("Enter next two numbers('q' to quit): ");
    }
    printf("bey");

    return 0;
}

// 6.9
#include <stdio.h>

float solve(float n1, float n2);

int main(void)
{
    float n1, n2, result;

    printf("Enter two float numbers: ");
    while(2 == scanf("%f %f", &n1, &n2)) {
        printf("the result is %2.f\n", solve(n1, n2));
    }

    return 0;

}

float solve(float n1, float n2)
{
    return (n1 - n2) / (n1 * n2);
}


// 6.10
#include <stdio.h>

int main(void)
{
    int min, max;
    int sum = 0;

    printf("Enter lower and upper integer limits: ");
    scanf("%d %d", &min, &max);
    while(min < max){
        for(int i = min; i <= max; i++)
            sum += i * i;
        printf("The sums of the squares from %d to %d is %d\n",
                min * min, max * max, sum);
        printf("Enter next set of limits: ");
        scanf("%d %d", &min, &max);
    }
    printf("Done");
    
    return 0;
}


// 6.12
#include <stdio.h>

int main(void)
{
    int count;
    int sign = -1;
    float sum1 = 0;
    float sum2 = 0;

    printf("Enter the times: ");
    scanf("%d", &count);
    while(count > 0){
        for(int i = 1; i <= count; i++){
            sign *= (-1);
            sum1 += 1.0 / i;
            sum2 += sign * 1.0 / i;
        }
        printf("Sum1 = %.4f, Sum2 = %.4f\n", sum1, sum2);
        printf("Enter the times: ");
        scanf("%d", &count);
    }

    printf("Done");
    
    return 0;
}


// 6.12 测试程序
#include <stdio.h>
#define count 1000

int main(void)
{
    float sum = 0;

    for(int i = 1; i <= count; i++){ 
        sum += 1.0 / i;
        if(i < count)
            printf("1.0/%.1f + ", (float)i);    
        else
            printf("1.0/%.1f", (float)i);
    }
    printf("\n");
    printf("= %.5f", sum);
}


// 6.13
#include <stdio.h>
#define SIZE 8

int main(void)
{
    int num[SIZE];
    //int p = 1;
    int index = 0;

    for(int i = 0, p = 1; i < SIZE; i++){
        p *= 2;
        num[i] = p;
    }

    do{
        printf("%5d", num[index]);
        index++;
    }while(index < SIZE);
    
    return 0;
}


// 6.14
#include <stdio.h>
#define SIZE 8

int main(void)
{
    double num1[SIZE], num2[SIZE];
    double sum = 0; // sum 作为全局变量，剩去一个循环
    
    //printf("Enter first number of 8 numbers: ");
    for(int i = 0; i < SIZE; i++){
        printf("Enter one number of 8 numbers: ");
        scanf("%lf", &num1[i]);
        //printf("Enter next number: ");
    }
    for(int j = 0; j < SIZE; j++){
        sum += num1[j];
        num2[j] = sum;
    }
    for(int k = 0; k < SIZE; k++)
        printf("%5.0lf", num1[k]);

    printf("\n");
    for(int k = 0; k < SIZE; k++)
        printf("%5.0lf", num2[k]);

    return 0;
}


// 6.15
#include <stdio.h>
//#include <string.h>
#define SIZE 255

int main(void)
{
    char str[SIZE];
    int i = 0;

    printf("Enter a string: ");
    scanf("%c", &str[i]);
    // while(str[i] != '\n'){
    //     i++;
    //     scanf("%c", &str[i]); 
    // }
    while(str[i++] != '\n')
        scanf("%c", &str[i]);
   
    //for(i = strlen(str)-2; i >= 0; i--)
    for(i -= 2; i >= 0; i--)
        printf("%c", str[i]);

    // while(i > 0) {
    //     printf("%c", string[i - 1]);
    //     i--;
    // }
        
    return 0;
}


// 6.16
#include <stdio.h>
#define DA_ROI 0.1
#define DE_ROI 0.05
#define DA_START_INVEST 100
#define DE_START_INVEST 100

int main(void)
{
    float da_invest = DA_START_INVEST;
    float de_invest = DE_START_INVEST;
    int year = 0;

    while(da_invest >= de_invest){
        da_invest += DA_ROI * DA_START_INVEST;
        de_invest *= (1 + DE_ROI);
        year++;
        printf("Year: %d, Da: %.3f, De: %.3f\n",
                     year, da_invest, de_invest);
    }
    printf("After %d years, Daphne: %.3f, Deirdre: %.3f",
            year, da_invest, de_invest);
                    
    return 0;
}


// 6.17
#include <stdio.h>
#define RAT 0.08
#define WITHDRAW_MONEY 10
#define MONEY 100

int main(void)
{
    float money = MONEY;
    int year = 0;

    while(money > 0){
        money *= (1 + RAT);
        money -= WITHDRAW_MONEY;
        year++;
        printf("year: %d, money: %.2f\n", year, money);   //测试
    }               
    printf("After %d years, money is running out.", year);

    return 0;
}


// 6.18
#include <stdio.h>
#define DUNBAR_NUM 150
#define FRIEND_NUM 5

int main(void)
{
    int friend_num = FRIEND_NUM;
    int week;

    for(week = 1; friend_num < DUNBAR_NUM; week++){
        friend_num -= week;
        friend_num *= 2;
        printf("week: %d, friend number: %d\n", week, friend_num);  //测试
    }        
    printf("After %d weeks, PHD Rabnud's friend numbers\
 is over Dunbar's number.", week - 1);

    return 0;
}