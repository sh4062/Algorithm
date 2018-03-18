#include <iostream>
using namespace std;

int main()
{
    //freopen("F://input.txt","r",stdin);
    int N, M;
    cin >> N >> M;
    for ( int i = 0; i < N; i++ ) {
        int G2;
        cin >> G2;
        int sum = 0;
        int maxm = 0, minm = 110;
        int num = 0;
        for ( int j = 1; j < N; j++ ) {
            int s;
            cin >> s;
            if ( 0 <= s && M >= s ) {
                ++num;
                sum += s;
                if ( maxm < s ) maxm = s;
                if ( minm > s ) minm = s;
            }
        }
        sum -= maxm;
        sum -= minm;
        num -= 2;
        sum /= num;
        //四舍五入取整法要记住 
        sum = (double)(sum + G2) / 2 + 0.5;
        cout << sum << endl;
    }
    return 0;
}