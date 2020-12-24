// 2.1
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


// 4.1
#include <stdio.h>

int main(void)
{
    char first_name[20];
    char last_name[20];

    printf("Enter your first name: ");
    scanf("%s", first_name);

    //getchar();

    printf("Enter your last name: ");
    scanf("%s", last_name);

    printf("%s, %s\n", last_name, first_name);

    return 0;
}


// 4.2
#include <stdio.h>
#include <string.h>

int main(void)
{
    char first_name[20];
    char last_name[20];
    int length_name, width;

    length_name = strlen(first_name) + strlen(last_name);
    width = length_name + 3;

    printf("Enter your first name: ");
    scanf("%s", first_name);

    printf("Enter your last name: ");
    scanf("%s", last_name);

    printf("\"%s %s\"\n", first_name, last_name);
    printf("\"%20s %20s\"\n", first_name, last_name);
    printf("\"%-20s %-20s\"\n", first_name, last_name);
    printf("\"%s %s\"\n", first_name, last_name);

    return 0;
}


// 4.3
#include <stdio.h>
#include <string.h>

int main(void)
{
    float num;

    printf("Enter a float number: ");
    scanf("%f", &num);
    printf("输入%f\n", num);
    printf("输入%e\n", num);

    return 0;
}


// 4.4
#include <stdio.h>
#include <string.h>

int main(void)
{

    float height;
    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your height(cm): ");
    scanf("%f", &height);
    printf("%s, you are %.2fm tall.\n", name, height / 100);

    return 0;
}


// 4.5
#include <stdio.h>
#include <string.h>

int main(void)
{
    float download_speed;
    float file_size;
    float download_time;

    printf("Enter your speed of downloading: ");
    scanf("%f", &download_speed);
    printf("Enter your file size: ");
    scanf("%f", &file_size);

    download_time = file_size / download_speed;

    printf("At %.2f megabits per second, a file of %.2f megabytes\n\
downloads in %.2f seconds.", download_speed, file_size, download_time);

    return 0;
}


// 4.6
#include <stdio.h>
#include <string.h>

int main(void)
{
    char first_name[40];
    char last_name[40];
    int fn_size, ln_size;

    printf("Enter your name(姓、名之间用空格分开): ");
    scanf("%s %s", &first_name, &last_name);

    fn_size = strlen(first_name);
    ln_size = strlen(last_name);

    printf("%s %s\n", first_name, last_name);
    printf("%*d %*d\n", fn_size, fn_size, ln_size, ln_size);

    printf("%s %s\n", first_name, last_name);
    printf("%-*d %-*d\n", fn_size, fn_size, ln_size, ln_size);
    
    return 0;
}


// 5.1
#include <stdio.h>
#define MIN_PRE_HOUR 60

int main(void)
{
    int time, hour, minute;

    printf("Enter the time(minute): ");
    scanf("%d", &time);
    while(time > 0){
        hour = time / MIN_PRE_HOUR;
        minute = time % MIN_PRE_HOUR;
        printf("%d = %dh%dm\n", time, hour, minute);
        printf("Enter the time(minute): ");
        scanf("%d", &time);
    }
    return 0;
}


// 5.2
#include <stdio.h>
#define MIN_PRE_HOUR 60

int main(void)
{
    int num;
    int count = 0;

    printf("Enter a number: ");
    scanf("%d", &num);
    while(count++ <= 10){
        printf("%d\t", num + count - 1);
    }
    return 0;
}


// 5.3
#include <stdio.h>
#define MIN_PRE_HOUR 60

int main(void)
{
    const int scale = 7;
    int days;
    int week, day;

    printf("Enter the number of days: ");
    scanf("%d", &days);
    while(days > 0){
        week = days / scale;
        day = days % scale;
        printf("%d days are %d weeks, %d days.\n", days, week, day);
        printf("Enter the number of days (<=0 to quit): ");
        scanf("%d", &days);
    }
    printf("bey!");

    return 0;
}


// 5.8
#include <stdio.h>
#define MIN_PRE_HOUR 60

int main(void)
{
    int first_operand, second_operand;
    int result;

    printf("The program computes moduli.\n");
    printf("Enter an integer to serve as the second operand: ");
    scanf("%d", &second_operand);
    printf("Now enter the first operand: ");
    scanf("%d", &first_operand);
    while(first_operand > 0){
        result = first_operand % second_operand;
        printf("%d %% %d is %d\n", first_operand, second_operand, result);
        printf("Enter next number for first operand (<= 0 to quit): ");
        scanf("%d", &first_operand);
    } 
    printf("Done");

    return 0;
}


// 5.9
#include <stdio.h>
#define MIN_PRE_HOUR 60

void Temperatures(double temp);

int main(void)
{
    double temp;

    printf("Enter huashi-temperature(℉): ");
    while(scanf("%lf", &temp) == 1){
        Temperatures(temp);
        printf("Enter huashi-temperature(℉)(enter 'q' or not ngumber to quit): ");
    }
    printf("Done");

    return 0;
}

void Temperatures(double temp)
{
    const double scale = 5.0 / 9.0;
    const double plus_adjust = 273.16;
    const double minus_adjust = 32.0;
    double sheshi_temp, kaishi_temp;

    sheshi_temp = scale * (temp - minus_adjust);
    kaishi_temp = sheshi_temp + plus_adjust;

    printf("Temperature is %.2lf℉, %.2f °C,  %.2f‎K\n",
            temp, sheshi_temp, kaishi_temp);

}


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
    double sum = 0;

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
#include <string.h>
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


//7.1
#include <stdio.h>
#define STOP '#'
#define BLANK ' '

int main(void)
{
    char ch;
    long n_chars = 0L;
    int n_blanks = 0;
    int n_lines = 0;

    printf("Enter text to be analyzed (# to quit):\n");
    while((ch = getchar()) != '\#'){
        if(ch == BLANK)
            n_blanks++;
        else if(ch == '\n')
            n_lines++;
        else
            n_chars++;
    }
    printf("blanks: %d, lines: %d, other chars: %ld\n",
            n_blanks, n_lines, n_chars);

    return 0;
}


//7.2
#include <stdio.h>
#define STOP '#'
#define SIZE 8

int main(void)
{
    char ch;
    long count = 0L;

    printf("Enter text to be analyzed (# to quit):\n");
    while((ch = getchar()) != STOP){
        if(ch == '\n')
            break;
        count++;
        printf("%c:%-5d", ch, ch);
        if(count % SIZE == 0)
            printf("\n");
    }
    printf("\nBey");

    return 0;
}


//7.3
#include <stdio.h>
#define STOP 0

int main(void)
{
    int num;
    int ct_even = 0, ct_odd = 0;
    float sum_even = 0, sum_odd = 0;
    float mean_even, mean_odd;

    printf("Enter integer to be analyzed: ");
    // while(scanf("%d", &num) == 1){
    //     if(0 == num) 
    //         break;
    while(scanf("%d", &num) == 1 && num != 0){
        if(num % 2 == 0)
        {
            ct_even++;
            sum_even += num;
        }
        else
        {
            ct_odd++;
            sum_odd += num;
        }
        printf("please enter the next number(0 to quit): ");
    }
    if(ct_even > 0)
        mean_even = sum_even / (float)ct_even;
    printf("Number of even：%d， Mean：%g\n", ct_even, ct_even ? mean_even : 0);
    if(ct_odd > 0)
        mean_odd = sum_odd / (float)ct_odd;
    printf("Number of odd: %d, Mean: %g\n", ct_odd, ct_odd ? mean_odd : 0);

    printf("Done");

    return 0;
}


// 7.4
#include <stdio.h>
#define STOP '#'

int main(void)
{
    char ch;
    int count = 0;
    printf("Enter text:\n");
    while((ch = getchar()) != STOP){
        if(ch == '.'){
            putchar('!');
            count++;
        }
        else if(ch == '!'){
            printf("!!");
            count++;
        }
        else
        {
            putchar(ch);
        }
        
    }
    printf("\nExchanged %d times.\n", count);

    return 0;
}


// 7.5
#include <stdio.h>
#define STOP '#'

int main(void)
{
    char ch;
    int count = 0;
    printf("Enter text:\n");
    while((ch = getchar()) != STOP){
        switch(ch){
            case '.': 
                putchar('!');
                count++;
                 break;
            case '!':
                printf("!!");
                count++;
                break;
            default:
                putchar(ch);
        }
        
    }
    printf("\nExchanged %d times.\n", count);

    return 0;
}


// 7.6 -- 法1
#include <stdio.h>
#define STOP '#'

int main(void)
{
    char ch, pre_ch;
    int count = 0;
    printf("Enter text(# to quit):\n");
    while((ch = getchar()) != STOP){
        // if(ch == 'i'){
        //     if(pre_ch == 'e')
        //         count++;
        // }
        if(ch == 'i' && pre_ch == 'e')
            count++;
            
        pre_ch = ch;
    }
    printf("\n\"ei\" appeared %d times.", count);

    return 0;
}


// 7.6 -- 法2
#include <stdio.h>
#include <stdbool.h>
#define STOP '#'

int main(void)
{
    char ch;
    int count = 0;
    bool in_ei = false;
    printf("Enter text(# to quit):\n");
    while((ch = getchar()) != STOP){
        if(ch == 'e')
            in_ei = true;
        else if(ch == 'i' && in_ei){
            count++;
            in_ei = false;
        }        
    }
    printf("\n\"ei\" appeared %d times.", count);

    return 0;
}


// 7.7
#include <stdio.h>
#define SALARY_PER_HOUR 10
#define TIME_BASE 40
#define OVERTIME 1.5
#define BREAK1 300
#define BREAK2 450
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25

int main(void)
{
    double hours;
    double gross, tax, net;

    printf("Enter your work hours in a week: ");
    scanf("%lf", &hours);
    if(hours > TIME_BASE)
        hours = TIME_BASE + (hours - TIME_BASE) * OVERTIME;
    gross = hours * SALARY_PER_HOUR;
    if(gross < BREAK1)
        tax = gross * RATE1;
    else if(gross < BREAK2)
        tax = BREAK1 * RATE1 + (gross - BREAK1) * RATE2;
    else
        tax = BREAK1 * RATE1 + (BREAK2 - BREAK1) * RATE2\
            + (gross - BREAK2) * RATE3;
    net = gross - tax;
    printf("Gross: %.2lf, tax: %.2lf, net: %.2lf", gross, tax, net);

    return 0;
}


// 7.8 -- 型1：只计算1次正确输入后的各值
#include <stdio.h>
#include <stdbool.h>
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
    int num;
    bool is_1_to_5 = false; // 这里的标志位必须为false,以防用户一开始就输入非数字
    double pay_rate;
    double hours;
    double gross, tax, net;

    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $8.75/hr         2) $9.33/hr\n");
    printf("3) $10.00/hr        4) $11.20/hr\n");
    printf("5) quit\n");
    printf("******************************************************************\n");
    //读取正确输入，直达是1-5之间才退出循环
    while(scanf("%d", &num) == 1){
        is_1_to_5 = true;   //每次循环标志位置为true
        switch(num){
            case 1: pay_rate = PAY_RATE1; break;
            case 2: pay_rate = PAY_RATE2; break;
            case 3: pay_rate = PAY_RATE3; break;
            case 4: pay_rate = PAY_RATE4; break;
            case 5: break;
            default: 
                printf("\nPlease enter the right number!\n");
                printf("*****************************************************************\n");
                printf("Enter the number corresponding to the desired pay rate or action:\n");
                printf("1) $8.75/hr         2) $9.33/hr\n");
                printf("3) $10.00/hr        4) $11.20/hr\n");
                printf("5) quit\n");
                printf("******************************************************************\n");
                is_1_to_5 = false;
        }
        // 1-5标志位，是1-5则break跳出
        if(is_1_to_5)
            break;
        //否则，将标志位复位至true,进行下一次while循环  
        //is_1_to_5 = true;   因为进入循环第一句就是将其置为true,故这里可以省略       
    }
    if(is_1_to_5){
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
        printf("Gross: %.2lf, tax: %.2lf, net: %.2lf", gross, tax, net);
    }       
 
    return 0;
}



// 7.8 -- 型2（法1）：循环计算正确输入后的各值
#include <stdio.h>
#include <stdbool.h>
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
    int num;
    bool is_1_to_5 = false; // 这里的标志位必须为false,以防用户一开始就输入非数字
    double pay_rate;
    double hours;
    double gross, tax, net;
    
    while(1){
        printf("\n*****************************************************************\n");
        printf("Enter the number corresponding to the desired pay rate or action:\n");
        printf("1) $8.75/hr         2) $9.33/hr\n");
        printf("3) $10.00/hr        4) $11.20/hr\n");
        printf("5) quit\n");
        printf("******************************************************************\n");
        //读取正确输入，直达是1-5之间才退出循环
        while(scanf("%d", &num) == 1){  //经过scanf筛选，进入循环的肯定是数字，排除了非数字字符
            is_1_to_5 = true;   //每次循环标志位置为true
            switch(num){
                case 1: pay_rate = PAY_RATE1; break;
                case 2: pay_rate = PAY_RATE2; break;
                case 3: pay_rate = PAY_RATE3; break;
                case 4: pay_rate = PAY_RATE4; break;
                case 5: break;
                default: 
                    printf("\nPlease enter the right number!\n");
                    printf("*****************************************************************\n");
                    printf("Enter the number corresponding to the desired pay rate or action:\n");
                    printf("1) $8.75/hr         2) $9.33/hr\n");
                    printf("3) $10.00/hr        4) $11.20/hr\n");
                    printf("5) quit\n");
                    printf("******************************************************************\n");
                    is_1_to_5 = false;
            }
            // 1-5标志位，是1-5则break跳出
            if(is_1_to_5)
                break;
            //否则，将标志位复位至true,进行下一次while循环  
            //is_1_to_5 = true;   因为进入循环第一句就是将其置为true,故这里可以省略       
        }
        if(is_1_to_5 && num != 5){  //从数字里再筛选出1-4，排除了5
            is_1_to_5 = false;  //一定要将标志位设为最初定义时的状态，以便进行新一轮外侧循环
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
        else
            break;       
    }

    return 0;
}


// 7.8 -- 型2 (法2)：循环计算正确输入后的各值
#include <stdio.h>
#include <stdbool.h>
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
    int num;
    double pay_rate;
    double hours;
    double gross, tax, net;

    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $8.75/hr         2) $9.33/hr\n");
    printf("3) $10.00/hr        4) $11.20/hr\n");
    printf("5) quit\n");
    printf("******************************************************************\n");
  
    while(scanf("%d", &num) == 1){
        switch(num){
            case 1: pay_rate = PAY_RATE1; break;
            case 2: pay_rate = PAY_RATE2; break;
            case 3: pay_rate = PAY_RATE3; break;
            case 4: pay_rate = PAY_RATE4; break;
        }
        if(num > 0 && num < 5){
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

            printf("*****************************************************************\n");
            printf("Enter the number corresponding to the desired pay rate or action:\n");
            printf("1) $8.75/hr         2) $9.33/hr\n");
            printf("3) $10.00/hr        4) $11.20/hr\n");
            printf("5) quit\n");
            printf("******************************************************************\n");
        }
        else if(5 == num)
            break;
        else
        {
            printf("\nPlease enter the right number!\n");

            printf("*****************************************************************\n");
            printf("Enter the number corresponding to the desired pay rate or action:\n");
            printf("1) $8.75/hr         2) $9.33/hr\n");
            printf("3) $10.00/hr        4) $11.20/hr\n");
            printf("5) quit\n");
            printf("******************************************************************\n");
        }
        
    }
 
    return 0;
}


// 7.8 -- 型2 (法3) 使用goto更方便
#include <stdio.h>
#include <stdbool.h>
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
    int num;
    double pay_rate;
    double hours;
    double gross, tax, net;

    printpart:   
    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $8.75/hr         2) $9.33/hr\n");
    printf("3) $10.00/hr        4) $11.20/hr\n");
    printf("5) quit\n");
    printf("******************************************************************\n");
  
    while(scanf("%d", &num) == 1){
        switch(num){
            case 1: pay_rate = PAY_RATE1; break;
            case 2: pay_rate = PAY_RATE2; break;
            case 3: pay_rate = PAY_RATE3; break;
            case 4: pay_rate = PAY_RATE4; break;
            case 5: return 0; //这里用break不行，因为此处在两个包围里：switch、while,break只能跳出switch,而我们要直接跳出两层包围
            default: goto printpart;
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
        goto printpart;       
    }
 
    return 0;
}


// 7.9
#include <stdbool.h>

int main(void)
{
    int num;
    int prime;
    bool is_prime = true;

    printf("Enter a integer: ");
    scanf("%d", &num);
    // for(prime = 1; prime <= num; prime++){
    //     is_prime = true;   //千万千万要记住：进入下一次循环之前必须将标志位复位！
    for(prime = 1; is_prime = true; prime <= num; prime++)  //初始化可以合到一起
        for(int j = 2; j * j <= prime; j++){
            if(prime % j == 0){
                is_prime = false;
                break;
            }
        }
        if(is_prime)
            printf("%3d", prime);        
    }

    return 0;
}



// 7.10
#include <stdio.h>
#define BASEPAY1 17850
#define BASEPAY2 23900
#define BASEPAY3 29750
#define BASEPAY4 14875
#define RATE1 0.15
#define RATE2 0.28

int main(void)
{
    int type;
    double income;
    double basepay;
    double tax;

    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired tax type or action:\n");
    printf("1) 单身             2) 户主\n");
    printf("3) 已婚，共有       4) 已婚，离异\n");
    printf("5) quit\n");
    printf("******************************************************************\n");

    while(scanf("%d", &type) == 1){
        switch(type){
            case 1: basepay = BASEPAY1; break;
            case 2: basepay = BASEPAY2; break;
            case 3: basepay = BASEPAY3; break;
            case 4: basepay = BASEPAY4; break;    
        }
        if(type > 0 && type < 5){
            printf("Enter your income: ");
            scanf("%lf", &income);
            printf("\n");
            if(income <= basepay)
                tax = income * RATE1;
            else
                tax = BASEPAY1 * RATE1 + (income - BASEPAY1) * RATE2;
            printf("Your tax is %.2lf: ", tax);

            printf("\n*****************************************************************\n");
            printf("Enter the number corresponding to the desired tax type or action:\n");
            printf("1) 单身             2) 户主\n");
            printf("3) 已婚，共有       4) 已婚，离异\n");
            printf("5) quit\n");
            printf("******************************************************************\n"); 
        }
        else if(5 == type)
            break;
        else{
            printf("Please enter right number\n");

            printf("\n*****************************************************************\n");
            printf("Enter the number corresponding to the desired tax type or action:\n");
            printf("1) 单身             2) 户主\n");
            printf("3) 已婚，共有       4) 已婚，离异\n");
            printf("5) quit\n");
            printf("******************************************************************\n");                  
        }
    }
    return 0;
}


// 7.11
#include <stdio.h>
#define ARTICHOKE 2.05
#define BEET 1.15
#define CARROT 1.09
#define BASE_PAY 100
#define DISCOUNT_RATE 0.05
#define BASE_WEIGHT1 5
#define BASE_WEIGHT2 20
#define BASE_SHIPPING1 6.5
#define BASE_SHIPPING2 14
#define ADJUST_SHIPPING 0.5

int main(void)
{
    char ch;
    double weight, total_weight,  artichoke_weight = 0, beet_weight = 0, carrot_weight = 0;
    double vegetable_pay, discount, shipping_pay, total_pay;

    printf("*************************************************************************\n");
    printf("Enter Enter the letter corresponding to the desired vegetables or action:\n");
    printf("a 洋蓟             b 甜菜\n");
    printf("c 胡萝ト           q 退出\n");
    printf("*************************************************************************\n");
    //菜单
    while((ch = getchar()) != 'q'){
        if(ch == '\n')  //消除前面输入a/b/c/q后按的回车键，以便后面获得干净的输入值。又因为后面是scanf()函数，故这里的代码可以省略。如果后面是getchar()函数必须要这段代码。
             continue;
        printf("Enter again weight of the vegetable you want: ");
        scanf("%lf", &weight);
        while(getchar() != '\n')    //滤掉输入重量后面的所有字符
            continue;
        switch(ch){
            case 'a': artichoke_weight += weight; break;
            case 'b': beet_weight += weight; break;
            case 'c': carrot_weight += weight; break;
            default: printf("%c is not a valid choice.\n", ch);
        }
        printf("\nYou have ordered:\n");
        printf("洋蓟: %.1lf 磅， 甜菜: %.1lf 磅，胡萝卜: %.1lf 磅\n",
                artichoke_weight, beet_weight, carrot_weight);
        
        printf("\n***********************************************************************\n");
        printf("Enter Enter the letter corresponding to the desired vegetables or action:\n");
        printf("a 洋蓟             b 甜菜\n");
        printf("c 胡萝ト           q 退出\n");
        printf("*************************************************************************\n");
    }
    //开始计算蔬菜费用
    vegetable_pay = artichoke_weight * ARTICHOKE + beet_weight * BEET + carrot_weight * CARROT;
    if(vegetable_pay >= BASE_PAY){
        discount = vegetable_pay * DISCOUNT_RATE;
        //vegetable_pay -= discount;
    }
    else
        discount = 0;        
    //计算运费
    total_weight = artichoke_weight + beet_weight + carrot_weight;
    if(total_weight <= BASE_WEIGHT1)
        shipping_pay = BASE_SHIPPING1;
    else if(total_weight > 5 && total_weight < 20)
        shipping_pay = BASE_SHIPPING2;
    else
       shipping_pay = BASE_SHIPPING2 + (total_weight - BASE_WEIGHT2) * ADJUST_SHIPPING;
    //计算费用总额
    total_pay = vegetable_pay - discount + shipping_pay;
    //输出
    printf("蔬菜种类      洋蓟      甜菜      胡萝卜\n");
    printf("售价          2.05      1.15       1.09\n");
    printf("订购重量(磅)  %g        %g        %g\n",
            artichoke_weight, beet_weight, carrot_weight);
    printf("\n蔬菜费用: %.2lf, 折扣: %.2lf, 运费和包装费: %.2lf\n总费用: %.2lf\n",
            vegetable_pay, discount, shipping_pay, total_pay);
    printf("welcome again!");
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


// 10.1
#include<stdio.h>
#define YEARS 5     //年数
#define MONTHS 12   //一年中发的月数

int main(void)
{
    const float rain[YEARS][MONTHS] =
    {
        { 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },
        { 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },
        { 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 },
        { 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },
        { 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 }
    };
    int year, month;
    float subtot, total;
    const float (*ptr) [MONTHS] = rain;

    printf(" YEAR       RAINFALL(inches)\n");
    for(year = 0, total = 0; year < YEARS; year++){
        for(month = 0, subtot = 0; month < MONTHS; month++)
            subtot += *(*(ptr + year) + month);
        printf("%5d %15.1f\n", 2010 + year, subtot);
        total += subtot;
    }
    printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
    printf("MONTHLY AVERAGE:\n\n");
    printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct ");
    printf(" Nov  Dec\n");

    for(month = 0; month < MONTHS; month++){
        for(year = 0, subtot = 0; year < YEARS; year++)
            subtot += *(*(ptr + year) + month);
        printf("%4.1f ", subtot / YEARS);
    }
    printf("\n");

    return 0;
}


// 10.2
#include<stdio.h>
void copy_arr(double target[], double sour[], int n);
void copy_ptr(double * target, double * sour, int n);
void copy_ptrs(double * target, double * sour, double * sour_end);

int main(void)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];

    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);
    
    return 0;
}

void copy_arr(double target[], double sour[], int n)
{
    for(int i = 0; i < n; i++){
        target[i] = sour[i];
        printf("%4.1lf", target[i]);
    }
    putchar('\n');
}

void copy_ptr(double * target, double * sour, int n)
{
    //法1
    // for(int i = 0; i < n; i++){
    //     *target = *sour;
    //     printf("%4.1lf", *target);
    //     target++;;
    //     sour++;
    // }
    //法2
    // for(double * p = sour; p < sour + n; p++){
    //     *target = *p;
    //     printf("%4.1lf", *target);
    // }
    //法3
    for(int i = 0; i < n; i++){
        *(target + i) = *(sour + i);
        printf("%4.1lf", *(target + i));
    }
    putchar('\n');
}

void copy_ptrs(double * target, double * sour, double * sour_end)
{
    for(double * i = sour; i < sour_end; i++){
        *target = *i;
        printf("%4.1lf", *target);
    }
}


// 10.3
#include<stdio.h>
#define LEN 12
int largest_num(const int * arr, int n);

int main(void)
{
   const int list[LEN] = {1, 2, 34, 465, 5, 3, 454, 3, 5, 9, 433, 10};

   printf("The largest number is: %d", largest_num(list, LEN));

   return 0;
}

int largest_num(const int * arr, int n)
{
    int max;

    max = *arr;
    for(int i = 0; i < n; i++){
        if(*(arr + i) > max)
            max = *(arr + i);
    }

    return max;
}


// 10.4
#include<stdio.h>
int get_max_index(const int * arr, int n);

int main(void)
{
   const int list[12] = {100000000, 2, 34, 465, 5, 3, 454, 3, 5, 9, 433, 10};

   printf("The index of largest number is: %d", get_max_index(list, 12));

   return 0;
}

int get_max_index(const int * arr, int n)
{
    int index, max;

    max = *arr;
    for(int i = 0; i < n; i++){
        if(*(arr + i) >= max){
            max = *(arr + i);
            index = i;
        }  
    }

    return index;
}


// 10.6 
#include<stdio.h>
#define LEN 12
void sort_reverse(double * arr, int n);

int main(void)
{
   double list[LEN] = { 1, 5, 3, 8, 12, 6, 0, 45, 9, 34, 45,67 };

   sort_reverse(list, LEN);
   for(int i = 0; i < LEN; i++)
        printf("%4g", list[i]);

   return 0;
}

void sort_reverse(double * arr, int n)
{
    int temp;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(*(arr + j) < *(arr + j + 1)){
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    
    }
}



// 10.7 - 法一 在第二题的基础上
#include<stdio.h>
#define ROWS 4
#define COLS 3
void copy_ptr(double * t, double * s, int n);

int main(void)
{
   double source[ROWS][COLS] = { {1, 5, 3}, {8, 12, 6}, {0, 45, 9}, {34, 45,67} };
   double target[ROWS][COLS];

   for(int i = 0; i < ROWS; i++)
       copy_ptr(*(target + i), *(source + i), COLS);

   for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++)
            printf("%4g", target[i][j]);
        putchar('\n');
   } 

   return 0;
}

void copy_ptr(double * t, double * s, int n)
{
    for(int i = 0; i < n; i++)
        *(t + i) = *(s + i);
}



// 10.7 - 法二 重新编写二维数组复制函数
#include<stdio.h>
#define ROWS 4
#define COLS 3
void copy_ptr2d(double (*t)[COLS], double (*s)[COLS], int rows);

int main(void)
{
   double source[ROWS][COLS] = { {1, 5, 3}, {8, 12, 6}, {10, 45, 9}, {34, 5, 13} };
   double target[ROWS][COLS];

   copy_ptr2d(target, source, ROWS);

   for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++)
            printf("%4g", target[i][j]);
        putchar('\n');
   } 

   return 0;
}

void copy_ptr2d(double (*t)[COLS], double (*s)[COLS], int rows)
{
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < COLS; j++)
            *(*(t + i) + j) = *(*(s + i) + j);
            //t[i][j] = s[i][j];
    }
}


// 10.8
#include<stdio.h>
#define LEN 7
void copy_ptr(double * t, double * s, int n);

int main(void)
{
   double source[LEN] = { 1, 5, 3, 8, 12, 6, 45 };
   double target[3];

   //copy_ptr(target, &source[2], 3);
   copy_ptr(target, source + 2, 3);
   for(int i = 0; i < 3; i++)
        printf("%4g", target[i]);

   return 0;
}

void copy_ptr(double * t, double * s, int n)
{
    for(int i = 0; i < n; i++)
        *(t + i) = *(s + i);
}



// 10.9
#include<stdio.h>
#define ROWS 3
#define COLS 5
void copy_array(int rows, int cols, double target[rows][cols], double source[rows][cols]);
void show_array(int rows, int cols, double arr[rows][cols]);

int main(void)
{
    double arr[ROWS][COLS] =
    {
        { 4.3, 4.3, 4.3, 3.0, 2.0 },
        { 8.5, 8.2, 1.2, 1.6, 2.4 },
        { 9.1, 8.5, 6.7, 4.3, 2.1 }
    };
    double tar[ROWS][COLS];

    copy_array(ROWS, COLS, tar, arr);
    show_array(ROWS, COLS, arr);
    putchar('\n');
    show_array(ROWS, COLS, tar);
}

void copy_array(int rows, int cols, double target[rows][cols], double source[rows][cols])
{
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++)
            target[i][j] = source[i][j];
    }
}

void show_array(int rows, int cols, double arr[rows][cols])
{
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++)
            printf("%4.1lf", arr[i][j]);
        putchar('\n');
    }
}


// 10.12
#include<stdio.h>
#define YEARS 5     //年数
#define MONTHS 12   //一年中发的月数
float year_average(float arr[][MONTHS], int years);
float month_average(float (*arr)[MONTHS], int years);


int main(void)
{
    float rain[YEARS][MONTHS] =
    {
        { 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },
        { 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },
        { 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 },
        { 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },
        { 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 }
    };

    year_average(rain, YEARS);
    month_average(rain, YEARS);

    return 0;
}

float year_average(float arr[][MONTHS], int years)
{
    float subtot = 0;
    float total = 0;
    int year;

    printf(" YEAR       RAINFALL(inches)\n");
    for(year = 0; year < years; year++){
        subtot = 0;
        for(int month = 0; month < MONTHS; month++)
            subtot += arr[year][month];
        printf("%5d %15.1f\n", 2010 + year, subtot);
        total += subtot;
    }
    printf("\nThe yearly average is %.1f inches.\n\n", total / years);
}

float month_average(float (*arr)[MONTHS], int years)
{
    float subtot;

    printf("MONTHLY AVERAGE:\n\n");
    printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct ");
    printf(" Nov  Dec\n");
    
    for(int month = 0; month < MONTHS; month++){
        subtot = 0;
        for(int year = 0; year < years; year++)
            subtot += arr[year][month];
        printf("%4.1f ", subtot / (float)years);
    }
}


// 10.13
#include<stdio.h>
#define ROWS 3
#define COLS 5
void get_arr2d(double t[][COLS]);
void average_rows(double (*arr)[COLS], int rows);
double get_max(double (*arr)[COLS], int rows);

int main(void)
{
   double array[ROWS][COLS];
   double max;

   get_arr2d(array);
   //打印验证
   putchar('\n');
   for(int i = 0; i < ROWS; i++){
       for(int j = 0; j < COLS; j++)
            printf("%4g", array[i][j]);
        putchar('\n');
   } 
   average_rows(array, ROWS);
   max = get_max(array, ROWS);
   printf("\n\nThe largest number is: %g", max);

   return 0;
}

//想将二维数组传回，可以放在形参中，而不用 return
void get_arr2d(double t[][COLS])
{
    double num;

    for(int j = 0; j < ROWS; j++){   
        printf("Enter five numbers: ");
        for(int i = 0; i < COLS; i++){
            scanf("%lf", &num);
            t[j][i] = num;
        }
    }
}

//计算每行平均值
void average_rows(double (*arr)[COLS], int rows)
{
    double total = 0, subtotal;
    int row;

    printf("\nAVERAGE every ROW:\n\n");
    for(row = 0; row < ROWS; row++){
        subtotal = 0;
        for(int col = 0; col < COLS; col++)
            subtotal += arr[row][col];
        total += subtotal;
        printf("%2d：%.1lf\n", row, subtotal / COLS);
    }
    printf("\nThe average of all numbers: %.1lf: ", total / (rows * COLS));
}

//找出最大值
double get_max(double (*arr)[COLS], int rows)
{
    double max;

    max = **arr;
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < COLS; col++){
            if(arr[row][col] > max)
                max = arr[row][col];
        }
    }
    return max;
}



// 10.14
#include<stdio.h>
#define ROWS 3
#define COLS 5
void get_arr2d(int row, int col, double t[row][col]);
void average_rows(int row, int col, double t[row][col]);
double get_max(int row, int col, double t[row][col]);

int main(void)
{
   double array[ROWS][COLS];
   double max;

   get_arr2d(ROWS, COLS, array);
   //打印验证
   putchar('\n');
   for(int i = 0; i < ROWS; i++){
       for(int j = 0; j < COLS; j++)
            printf("%4g", array[i][j]);
        putchar('\n');
   } 
   average_rows(ROWS, COLS, array);
   max = get_max(ROWS, COLS, array);
   printf("\n\nThe largest number is: %g", max);

   return 0;
}

//想将二维数组传回，可以放在形参中，而不用 return
void get_arr2d(int row, int col, double t[row][col])
{
    double num;

    for(int j = 0; j < row; j++){   
        printf("Enter five numbers: ");
        for(int i = 0; i < col; i++){
            scanf("%lf", &num);
            t[j][i] = num;
        }
    }
}

//计算每行平均值
void average_rows(int row, int col, double t[row][col])
{
    double total = 0, subtotal;
    int i;

    printf("\nAVERAGE every ROW:\n\n");
    for(i = 0; i < row; i++){
        subtotal = 0;
        for(int j = 0; j < col; j++)
            subtotal += t[i][j];
        total += subtotal;
        printf("%2d：%.1lf\n", i, subtotal / col);
    }
    printf("\nThe average of all numbers: %.1lf: ", total / (row * col));
}

//找出最大值
double get_max(int row, int col, double t[row][col])
{
    double max;

    max = **t;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(t[i][j] > max)
                max = t[i][j];
        }
    }
    return max;
}



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



















