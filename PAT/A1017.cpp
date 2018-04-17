//1017. Queueing at Bank (25)
#include <bits/stdc++.h>
using namespace std;
struct customer
{
    int hh;
    int mm;
    int ss;
    int pt;
    // customer(int h,int m,int s,int p){hh = h,mm=m,ss = s,pt = p;};
    int st;
    int sst;
} customers[10005];

vector<int> res(10005);
bool cmp(customer a, customer b)
{
    if (a.hh != b.hh)
        return a.hh < b.hh;
    else if (a.mm != b.mm)
        return a.mm < b.mm;
    else
        return a.ss < b.ss;
}
queue<customer> q;
int main()
{
    int N, K;
    cin >> N >> K;
    int h, m, s, p;
    vector<int> server(K + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        customer tmp;
        scanf("%02d:%02d:%02d %d", &tmp.hh, &tmp.mm, &tmp.ss, &tmp.pt);
        tmp.st = tmp.hh * 60 * 60 + tmp.mm * 60 + tmp.ss;
        customers[i] = tmp;
    }
    sort(customers + 1, customers + 1 + N, cmp);
    // for (int i = 1; i <= N; i++)
    // {
    //     cout << customers[i].hh << " " << customers[i].mm << " " << customers[i].pt << '\n';
    // }
    double sumt = 0;
    int countc = 1;
    int countq = 0;
    double compc = 0;
    int indext = 0;
    for (indext = 1; indext <= N; indext++){
        if(customers[indext].st>17*3600)break;
    }
    //cout<<indext<<'\n';
    for (int t = 0 + 8 * 60 * 60; t <= 10*540*60+8*60*60,compc<indext-1; t++)
    {
        
        for (int i = 1; i <= K; i++) //出队
        {
            if (res[server[i]] == t)
            {
                server[i] = 0;
                countq--;
            }
        }

        while (countc <= N && countq < K && customers[countc].st <= t) //入队
        {   

            

            customers[countc].sst = t;
            sumt += double(t - customers[countc].st) / 60;
            compc++;

            int index = 1;
            for (index; index <= K; index++)
            {
                if (server[index] == 0)
                    break;
            }

            res[countc] = customers[countc].sst + customers[countc].pt * 60;
            server[index] = countc;
            countq++;
            countc++;
        }
    }
    printf("%.1f", sumt / compc);
    //printf("%.1f", compc);
}