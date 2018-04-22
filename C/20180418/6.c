//输入年月日，输出该日期是当年的第几天。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int dayofyear(int year, int month, int day)
{
    int sum, i = 0;
    switch (month)
    {
    case 12:
        i = i + 30;
    case 11:
        i = i + 31;
    case 10:
        i = i + 30;
    case 9:
        i = i + 31;
    case 8:
        i = i + 31;
    case 7:
        i = i + 30;
    case 6:
        i = i + 31;
    case 5:
        i = i + 30;
    case 4:
        i = i + 31;
    case 3:
        i = i + 28;
    case 2:
        i = i + 31;
    case 1:;
    default:;
    }
    sum = i + day;
    if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && (month > 2))
        sum = sum + 1;
    return sum;
}

//输入两个日期（年 月 日 年 月 日）， 输出这两个日期之间差多少天。
//sum = delt(year1 year2)  - dayofyear(date1)  + dayofyear(date2)
int is_leap_year(int y)
{
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        return 1;
    else
        return 0;
}
int sum(int year, int month, int day, int year2, int month2, int day2)
{ //就假定1>2了

    int d = 0;
    if (is_leap_year(year))
        d += 366 - dayofyear(year, month, day);
    else
        d += 365 - dayofyear(year, month, day);
    for (int i = year + 1; i < year2; i++)
    {
        if (is_leap_year(i))
            d += 366;
        else
            d += 365;
    }

    d -= dayofyear(year, month, day);
    d += dayofyear(year2, month2, day2);
    return d;
}

//3）输入一个日期，输出该日期是星期几。
///400就是其中闰年的个数，四年一闰，百年不闰，四百年再闰，所以4年的个数减去100年的个数在加上400年的个数就是其中闰年的个数了；
int FirstWeeday(int year) //某年第一天星期几
{
    int days = (year - 1) * 365 + (year - 1) / 4 - (year - 100) / 100 + (year - 1) / 400;
    return days % 7;
}
int Weeday(int year, int month, int day)
{
    int s = dayofyear(year, month, day);
    int t = FirstWeeday(year);
    return (s + t) % 7;
}

//4输入 一个日期 和一个整数 n，输出从该日期起经过n天以后的日期。
//date -> tomorrow of the date
struct Date
{
    int year;
    int month;
    int day;
};
int days(int year, int month)
{
    if (is_leap_year(year) && month == 2)
        return 29;
    if (month == 2)
        return 28;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    return 31;
}
struct Date nextDay(struct Date d)
{
    if (d.day == days(d.year, d.month))
    {
        d.day = 1;
        d.month = (d.month) + 1;
        if (d.month == 1)
            d.year++;
    }
    else
        d.day++;
    return d;
}
struct Date nextNDay(struct Date d, int n)
{
    while (n--)
    {
        d = nextDay(d);
    }

    return d;
}
void output(struct Date x)
{
 printf("%04d-%02d-%02d\n",x.year,x.month,x.day);
}
//（5） 输入一个年份,月份，输出该月份的日历。 见7
int main(void)
{
    int month, year, day;
    struct Date a;
    struct Date b;
    printf("Input the year, the month and the day:\n");
    scanf("%d %d %d", &year, &month, &day);
    //******
    a.year=year;
    a.month=month;
    a.day=day;
    b= nextNDay(a,100);
    output(b);
    
}