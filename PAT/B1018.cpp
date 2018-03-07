#include<iostream>
using namespace std;
int change(char c){
    if(c == 'B') return 0;
    if(c == 'C') return 1;
    if(c == 'J') return 2;
}

int main(){
    char mp[3] = {'B', 'C', 'J'};
    int n;
    cin>>n;
    int A[3] = {0},B[3] = {0};
    int Aw[3] = {0}, Bw[3] = {0};
    char c1,c2;
    int k1,k2;
    for(int i = 0;i < n;i++){
        //getchar();
        cin>>c1>>c2;
        k1 = change(c1);
        k2 = change(c2);
        if((k1 + 1)%3 ==k2){
            A[0]++;
            B[2]++;
            Aw[k1]++;
        } else if (k1 == k2){
            A[1]++;
            B[1]++;
        } else {
            A[2]++;
            B[0]++;
            Bw[k2]++;
        }
    }
    cout<<A[0]<<" "<<A[1]<<" "<<A[2]<<endl;
    cout<<B[0]<<" "<<B[1]<<" "<<B[2]<<endl;;
    int id1 = 0, id2 = 0;
    for(int i = 0;i<3;i++){
        if(Aw[i]>Aw[id1]) id1 = i;
        if(Bw[i]>Bw[id2]) id2 = i;
    }
    cout<<mp[id1]<<" "<<mp[id2]<<endl;

}