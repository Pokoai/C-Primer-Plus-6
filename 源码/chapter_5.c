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