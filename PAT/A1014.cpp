//1014. Waiting in Line (30)
#include <bits/stdc++.h>
using namespace std;
vector<int> ct(1111, 0); //processing time of the K customers

vector<int> res(1111, 0);
vector<queue<int>> q(21);
vector<int> times(21, 0);

int main()
{
    int N, M, K, Q; //4 positive integers: N (<=20, number of windows), M (<=10, the maximum capacity of each line inside the yellow line),
    //K (<=1000, number of customers), and Q (<=1000, number of customer queries).
    cin >> N >> M >> K >> Q;
    for (int i = 1; i <= K; i++)
    {
        cin >> ct[i];
    }

    for (int i = 0; i <= N; i++)
    {
        while (q[i].empty() == false)
            q[i].pop();
    }
    //q[0].push(1);
    //8-17 9*60=540
    int countc = 1; //人数
    int countq = 0;
    bool flag = 0; //是否有位置
    for (int t = 0; t < 540; t++)
    {
        for (int i = 0; i < N; i++) //出队
        {
            // if(q[i].size()>0){
            // int tmp = q[i].front();
            // if (times[i] + ct[tmp] == t)
            // {
            //     times[i] = times[i] + ct[tmp];
            //     res[tmp] = t;
            //     q[i].pop();
            // }}
            for (int j = 0; j < q[i].size(); j++)
            {
                int tmp = q[i].front();
                if (res[tmp] == t)
                { //如果当前队伍的人服务结束了
                    q[i].pop();
                    countq--;
                    //times[i] = times[i] + ct[tmp];
                    // res[tmp] = t;
                    if (!q[i].empty())
                    { //并且计算当前队伍下一个人的结束时间
                        int tmp2 = q[i].front();

                        res[tmp2] = t + ct[tmp2]; //结束时间为当前时间+顾客的服务时间
                    }
                }
            }
        }
        flag = 0;
        for (int i = 0; i < N; i++) //check
        {
            if (q[i].size() < M)
            {
                flag = 1;
            }
        }

        while (countc <= K && flag && countq < N * M)
        { //选择最小的队列进入
            int minq = 0;
            for (int i = 0; i < N; i++)
            {

                if (q[minq].size() > q[i].size())
                    minq = i;
            }
            if (q[minq].size() == 0)
                res[countc] = t + ct[countc];
            if (q[minq].size() < M && countc <= K) //入队
            {
                q[minq].push(countc);
                countc++;
                countq++;
            }
            flag = 0; //check
            for (int i = 0; i < N; i++)
            {
                if (q[i].size() < M)
                {
                    flag = 1;
                }
            }
        }
    }

    for (int i = 0; i < Q; i++)
    {
        int tmp;
        cin >> tmp;
        if (res[tmp] == 0)
            puts("Sorry"); //值为0说明没有被开始服务，只能Sorry
        else
        {
            int hour, min;
            hour = 8 + res[tmp] / 60;
            min = res[tmp] % 60;
            printf("%02d:%02d\n", hour, min); //把时间转换为标准格式并输出
        }
    }

    return 0;
}