#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int maxn=10000;
int n,k;
struct Customer{
    int arrive; //到达时间
    int process; //服务时间
    int start;  //客户开始被服务的时间
    int finish; //客户的结束时间
    int wait; //客户的等待时间
    bool operator<(const Customer tmp)const{
        return arrive<tmp.arrive;
    }

}cus[maxn];
struct Window{
    int finish_time;
    bool operator<(const Window tmp)const{
        return finish_time>tmp.finish_time;
    }
};
int main()
{
    int h,m,s,t;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d:%d:%d %d",&h,&m,&s,&t);
        cus[i].arrive=h*3600+m*60+s;
        if(t>60)
            t=60; //样例中其实也没有超过60分钟的数据，题目说了是假设
        cus[i].process=t*60;
    }
    priority_queue<Window>q;
    Window w;
    for(int i=0;i<k;i++){
        w.finish_time=8*3600;
        q.push(w);
    }
    sort(cus,cus+n);
    Window ww;
    for(int i=0;i<n;i++){
        w=q.top();
        q.pop();
        if(cus[i].arrive<w.finish_time){
            cus[i].wait=w.finish_time-cus[i].arrive;
            cus[i].start=w.finish_time;
            cus[i].finish=cus[i].start+cus[i].process;
            ww.finish_time=cus[i].finish;
            q.push(ww);
        }
        else{
            cus[i].start=cus[i].arrive;
            cus[i].wait=0;
            cus[i].finish=cus[i].start+cus[i].process;
            ww.finish_time=cus[i].finish;
            q.push(ww);
        }
    }
    double sum=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        /*
        一开始和P1014搞混了，以为如果是17点之前还没被服务，就不考虑
        后来发现题目中明确说了，是17点之后到的才不考虑
        */
        if(cus[i].arrive<=17*3600){
            sum+=cus[i].wait;
            cnt++;
        }
    }
    if(cnt==0)
        printf("0.0\n"); //去掉这个也能AC，说明样例没有出现cnt为0的情况
    else{
        double minutes=sum/60.0/cnt;
        printf("%.1lf\n",minutes);
    }
    printf("%d\n",cnt);


    return 0;
}