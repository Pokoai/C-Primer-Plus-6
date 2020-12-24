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