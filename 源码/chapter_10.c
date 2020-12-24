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