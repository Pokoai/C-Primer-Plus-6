// 9.10复习题-9
#include<stdio.h>
#define TOP 10
#define LOW 1

int main(void)
{
    int result;
    
    show_menu();
    while((result = get_choice(LOW, TOP)) != 4){
        printf("I like choice %d.\n", result);
        show_menu();
    }
    printf("Bey!\n");
    
    return 0;
}

void show_menu(void)
{
    printf("Please choice one of the following:\n");
    printf("1) copy     2) move\n");
    printf("3) remove   3) quit\n");
    printf("Enter the number of your choice: ");
}

int get_choice(int low, int top)
{
    int ans;
    int is_integer;
    
    while((is_integer = scanf("%d", &ans)) == 1 && (ans < low || ans > top)){
        printf("%d is not a valid choice; tyr choice again\n", ans);
        show_menu();
    }
    if(!is_integer){
        printf("Non-numeric input.");
        ans = 4;
    }
    
    return ans;
}


// 9.1
#include<stdio.h>
double min(double x, double y);

int main(void)
{
    double num1, num2;

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    printf("The minist number is %g", min(num1, num2));
}

double min(double x, double y)
{
    return x < y ? x : y;
}



// 9.2
#include<stdio.h>
void chline(ch, i, j);

int main(void)
{
    char ch;
    int row, column;

    printf("Enter a character: ");
    ch = getchar();
    printf("Enter two integer: ");
    scanf("%d %d", &row, &column);
    chline(ch, row, column);
}

void chline(ch, i, j)
{
    for(int row = 0; row < i; row++){
        for(int column = 0; column < j; column++)
            putchar(ch);
        putchar('\n');
    }
}



// 9.5
#include<stdio.h>
void larger_of(double * num1, double * num2);

int main(void)
{
    double num1, num2;

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    printf("num1 = %g, num2 = %g\n", num1, num2);
    larger_of(&num1, &num2);
    printf("num1 = %g, num2 = %g", num1, num2);
}

// void larger_of(double * num1, double * num2)
// {
//     if(*num1 >= *num2)
//         *num2 = *num1;
//     else
//         *num1 = *num2;
// }

void larger_of(double * num1, double * num2)
{
    *num1 > *num2 ? (*num2 = *num1) : (*num1 = *num2) 
}



// 9.6
#include<stdio.h>
void sort_of(double * num1, double * num2, double * num3);

int main(void)
{
    double num1, num2, num3;

    printf("Enter three numbers: ");
    scanf("%lf %lf %lf", &num1, &num2, &num3);
    printf("num1 = %g, num2 = %g, num3 = %g\n", num1, num2, num3);
    sort_of(&num1, &num2, &num3);
    printf("num1 = %g, num2 = %g, num3 = %g\n", num1, num2, num3);
}

void sort_of(double * num1, double * num2, double * num3)
{
    double max, min, sum;

    sum = *num1 + *num2 + *num3;
    //找出最大值
    *num1 > *num2 ? (max = *num1) : (max = *num2);
    if(*num3 > max)
        max = *num3;
    //找出最小值
    *num1 < *num2 ? (min = *num1) : (min = *num2);
    if(*num3 < min)
        min = *num3;
    *num1 = min;
    *num3 = max;
    *num2 = sum - max - min;
}



// 9.7
#include<stdio.h>
//#include<ctype.h>
int letter_location(char ch);

int main(void)
{
    char ch;
    int res;

    printf("Enter a character: ");
    while((ch = getchar()) != EOF){ 
        // ch = getchar();
        // res = letter_location(ch);
        if(-1 == (res = letter_location(ch)))
            printf("%c is not a letter.\n", ch);
        else
            printf("%c: %d\n", ch, res + 1);
        printf("Enter a character: ");
        while(getchar() != '\n')
            continue;
    }

}

int letter_location(char ch)
{
    int ans;
    
    if(ch >= 'a' && ch <= 'z' )
        ans = ch - 'a';
    else if(ch >= 'A' && ch <= 'Z')
        ans = ch - 'A';
    else
        ans = -1;

    return ans;
}

//或者直接用 ctype.h 函数
// int letter_location(char ch)
// {
//     int ans;

//     if(isalpha(ch))
//         ans = tolower(ch) - 'a' + 1;
//     else 
//         ans = -1;
//     return ans;
// }