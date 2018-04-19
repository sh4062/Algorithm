//1016. Phone Bills (25)
#include <bits/stdc++.h>
using namespace std;
struct Call
{
    char name[21];
    int month;
    int date;
    int hour;
    int min;
    int total;
    bool operator<(const Call &C) const
    {
        int tmp = strcmp(name, C.name);
        if (tmp != 0)
            return tmp < 0;
        else
            return total < C.total;
    } //比较函数，按照姓名先后，时间小大的顺序排序
    char status[10];
};                         //电话记录结构体
int charge[24];            //存放每小时的电话费用
vector<Call> all_calls;    //所有的电话记录
vector<Call> format_calls; //整理后的电话记录
int chargeByTime(int time)
{ //计算t0初始时间到指定时间time的总费用
    int hours = time / 60;
    int min = time % 60;
    int money = 0;
    int i;
    for (i = 0; i < hours; i++)
    {
        money += charge[i % 24] * 60;
    }
    money += charge[i % 24] * min;
    return money;
}
double calCost(Call s, Call t)
{
    //这里有个技巧，当要算s到t时间的电话费用时，都从t0时间开始算起，这样的话就会开始都是整小时数，方便计算和函数编写
    return (double)(chargeByTime(t.total) - chargeByTime(s.total)) / 100;
}
int calLast(Call s, Call t)
{
    return (t.date - s.date) * 24 * 60 + (t.hour - s.hour) * 60 + (t.min - s.min);
} //计算通话持续时间
int main()
{
    int t = 24;
    for (int i = 0; i < t; i++)
    {
        cin >> charge[i];
    }
    int n;
    cin >> n;
    while (n--)
    {
        Call c_tmp;
        scanf("%s%d:%d:%d:%d%s", c_tmp.name, &c_tmp.month, &c_tmp.date, &c_tmp.hour, &c_tmp.min, c_tmp.status);
        c_tmp.total = c_tmp.date * 24 * 60 + c_tmp.hour * 60 + c_tmp.min;
        all_calls.push_back(c_tmp);
    }                                         //读入通话记录并转化当前通话的时刻
    sort(all_calls.begin(), all_calls.end()); //先排序，按照姓名，再按照时间排序
                                              // for(auto i :all_calls ){
                                              //     cout<<i.name<<" "<<i.month<<'\n';
                                              // }
    bool haveonline = false;
    char curname[21]; //当前用户
    char online[10] = "on-line";
    char offline[10] = "off-line";
    //------------------------整理的过程，很关键--------------
    for (int i = 0; i < all_calls.size(); i++)
    {
        if (haveonline == false && strcmp(all_calls[i].status, online) == 0)
        {                                         //如果用户没有上线，并且当前记录为上线的话
            format_calls.push_back(all_calls[i]); //把当前记录放入format_calls
            haveonline = true;                    //并置haveonline为已上线
            strcpy(curname, all_calls[i].name);   //并记录当前用户的名字
        }
        else if (haveonline == true && strcmp(all_calls[i].status, online) == 0)
        { //如果用户已经上线，并且当前记录为上线的话，则按后者的计算，这是为了应对A用户上线，再接着是B用户上线，前者A上线记录作废；或是两次都是A用户上线，以后者计算
            format_calls.pop_back();
            format_calls.push_back(all_calls[i]); //需要先把之前上线的记录拿掉，放入更新后的
            haveonline = true;
            strcpy(curname, all_calls[i].name); //名字也要为更新后的
        }
        else if (haveonline == true && strcmp(all_calls[i].status, offline) == 0 && strcmp(curname, all_calls[i].name) == 0)
        {                                         //如果用户已上线，并且当前记录是下线，说明是一个电话记录完成
            format_calls.push_back(all_calls[i]); //把下线记录放入format_calls
            haveonline = false;                   //并把haveonline置为非上线
        }
    }
    if (strcmp((*(format_calls.end() - 1)).status, online) == 0)
    { //如果碰到下线记录，当时用户名不匹配，比如遇到A上线，B下线的记录，则说明A的记录不完整，需要把A上线的记录从format_calls中删去
        format_calls.pop_back();
    }
    double totalcost = 0;
    char kong[21] = "";
    strcpy(curname, kong);

    //------------------------格式化输出，也很重要-----------------
    for (int i = 0; i < format_calls.size(); i += 2)
    {
        if (strcmp(format_calls[i].name, curname) != 0)
        {
            if (strcmp(curname, kong) != 0)
            {                                                                     //碰到了非第一个用户的新用户
                printf("Total amount: $%.2f\n", totalcost);                       //输出前一个用户的总费用
                totalcost = 0;                                                    //并把totalcost重新置为0
                printf("%s %02d\n", format_calls[i].name, format_calls[i].month); //输出新用户的头部信息
            }
            else //curname==""，也就是是第一个用户，所以不用输出上一个用户的totalcost
            {
                printf("%s %02d\n", format_calls[i].name, format_calls[i].month);
            }
            strcpy(curname, format_calls[i].name); //把新用户的名称记录
        }
        printf("%02d:%02d:%02d", format_calls[i].date, format_calls[i].hour, format_calls[i].min);
        printf(" ");
        printf("%02d:%02d:%02d", format_calls[i + 1].date, format_calls[i + 1].hour, format_calls[i + 1].min);
        printf(" ");
        printf("%d", calLast(format_calls[i], format_calls[i + 1])); //输出当前记录持续时间
        printf(" ");
        printf("$%.2f\n", calCost(format_calls[i], format_calls[i + 1])); //输出当前记录费用
        totalcost += calCost(format_calls[i], format_calls[i + 1]);       //累计到总费用中
    }
    printf("Total amount: $%.2f\n", totalcost);
}