//打印日历
//握草我都不知道我写的是啥了 不过应该对
#include <stdio.h>
/*判断是平年还是闰年*/
int IsLeap(int year)
{
    if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}
/*计算今年的第一天是星期几*/
int FirstWeeday(int year)
{
    int days = (year - 1) * 365 + (year - 1) / 4 - (year - 100) / 100 + (year - 1) / 400;
    return days % 7;
}
/*打印星期*/
void PrintWeedTitl()
{
    int i;
    for (i = 0; i < 7; i++)
    {
        if (i == 0)
        {
            printf("  Sun  ");
        }
        if (i == 1)
        {
            printf("Mon  ");
        }
        if (i == 2)
        {
            printf("Tue  ");
        }
        if (i == 3)
        {
            printf("Wed  ");
        }
        if (i == 4)
        {
            printf("Thu  ");
        }
        if (i == 5)
        {
            printf("Fri  ");
        }
        if (i == 6)
        {
            printf("Sat  ");
        }
    }
}
/*打印月份*/
void PrintMonTitl(int month)
{
    switch (month)
    {
    case 0:
        printf("Jan");
        break;
    case 1:
        printf("Feb");
        break;
    case 2:
        printf("Mar");
        break;
    case 3:
        printf("Apr");
        break;
    case 4:
        printf("May");
        break;
    case 5:
        printf("Jun");
        break;
    case 6:
        printf("Jul");
        break;
    case 7:
        printf("Aug");
        break;
    case 8:
        printf("Sep");
        break;
    case 9:
        printf("Oct");
        break;
    case 10:
        printf("Nov");
        break;
    case 11:
        printf("Dec");
        break;
    default:
        break;
    }
}
/*格式化输出日历*/
void PrintYear(int year)
{
    int m, i, j, d, dd, f;
    char c = ' ';
    int MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (IsLeap(year))
        MONTH[1] = 29;
    int firstwed = FirstWeeday(year);
    int firstwed7 = firstwed;
    for (int j = 0; j < 7; j++)
        firstwed7 += MONTH[j];
    firstwed7 = firstwed7 % 7;
    printf("|======================The Calendar of Year: %d==========================|\n", year);

    for (m = 0; m < 6; m++)
    {
        printf("|");
        PrintMonTitl(m);
        printf("                                  ");
        PrintMonTitl(m + 6);
        printf("                                  ");
        printf("|");
        printf("\n");
        printf("|");
        PrintWeedTitl();
        PrintWeedTitl();
        printf("|");
        printf("\n");
        printf("|");
        int cnt = 0;
        for (d = 1, dd = 1; d <= MONTH[m]; d++)
        {

            if (d == 1)
            {
                for (i = 0; i < firstwed; i++)
                {
                    printf("%5c", c);
                }
                printf("%5d", d);
            }
            else
            {
                printf("%5d", d);
            }

            if ((firstwed + d - 1) % 7 == 6 || d == MONTH[m])

            {
                if (d == MONTH[m] && firstwed + MONTH[m] <= 35)
                {
                    if (35 - firstwed - MONTH[m] >= 0)
                    {
                        if (35 - firstwed - MONTH[m] != 7)
                            for (i = 0; i < 35 - firstwed - MONTH[m]; i++)
                            {
                                printf("%5c", c);
                            }
                    }
                    else
                    {
                        for (i = 0; i < 42 - firstwed - MONTH[m]; i++)
                        {
                            printf("%5c", c);
                        }
                    }
                }
                while (dd <= MONTH[m + 6])
                {

                    if (dd == 1)
                    {
                        for (i = 0; i < firstwed7; i++)
                            printf("%5c", c);
                        printf("%5d", dd);
                    }

                    else
                    {
                        if (cnt < 1)
                            printf("%5d", dd);
                        if (dd == MONTH[m + 6])
                            cnt++;
                    }
                    if (dd == MONTH[m + 6])
                        break;

                    if ((firstwed7 + dd - 1) % 7 == 6)
                    {
                        dd++;
                        break;
                    }
                    dd++;
                }
                if (dd != MONTH[m + 6])
                {

                    printf("    |");
                    printf("\n");
                    printf("|");
                }
                else if (dd == MONTH[m + 6])
                {

                    if (35 - firstwed7 - MONTH[m + 6] >= 0 && d == MONTH[m] && firstwed + MONTH[m] <= 35)
                    {
                        for (i = 0; i < 35 - firstwed7 - MONTH[m + 6]; i++)
                        {
                            printf("%5c", c);
                        }
                        printf("    |");
                    }
                    else if (35 - firstwed7 - MONTH[m + 6] >= 0 && d == MONTH[m] && firstwed + MONTH[m] > 35 && firstwed7 + MONTH[m + 6] <= 35)
                    {
                        for (i = 0; i < 7; i++)
                            printf("%5c", c);
                        for (i = 0; i < 42 - firstwed - MONTH[m]; i++)
                        {
                            printf("%5c", c);
                        }
                        printf("    |");
                    }
                    else if (35 - firstwed7 - MONTH[m + 6] >= 0 && d < MONTH[m])
                    {
                        for (i = 0; i < 35 - firstwed7 - MONTH[m + 6]; i++)
                        {
                            printf("%5c", c);
                        }
                        printf("    |");
                        printf("\n");
                        printf("|");
                    }
                    else if (35 - firstwed7 - MONTH[m + 6] < 0 && d == MONTH[m])
                    {
                        printf("    |");
                        printf("\n");
                        printf("|");
                        for (i = 0; i < 7; i++)
                        {
                            printf("%5c", c);
                        }
                        printf("%5d", dd);
                        for (i = 0; i < 42 - firstwed7 - MONTH[m + 6]; i++)
                        {
                            printf("%5c", c);
                        }

                        printf("    |");
                    }
                }
            }
        }
        cnt = 0;

        if (dd < MONTH[m + 6])
        {

            for (i = 0; i < 7; i++)
            {
                printf("%5c", c);
            }

            while (dd <= MONTH[m + 6])
            {
                printf("%5d", dd);
                dd++;
            }

            if (35 - firstwed7 - MONTH[m + 6] >= 0)
            {
                for (i = 0; i < 35 - firstwed7 - MONTH[m + 6]; i++)
                {
                    printf("%5c", c);
                }
                printf("    |");
            }
            else
            {
                for (i = 0; i < 42 - firstwed7 - MONTH[m + 6]; i++)
                {
                    printf("%5c", c);
                }
                printf("    |");
            }
        }

        if (dd >= MONTH[m + 6] && d == MONTH[m])
            dd = 1;
        firstwed = (firstwed + MONTH[m]) % 7;
        firstwed7 = (firstwed7 + MONTH[m + 6]) % 7;
        printf("\n");
    }
    printf("|======================The Calendar of Year: %d==========================|\n", year);
}

int main()
{
    int year = 0000;
    // printf("Input year\n");
    // scanf("%d",&year);
    PrintYear(year);
}