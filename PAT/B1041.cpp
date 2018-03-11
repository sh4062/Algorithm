#include<iostream>
#include <fstream> 
using namespace std;
const int maxn = 1005;
struct student{
    long long id;
    int eseat;
}student[maxn];
int main(){
    ifstream mf("./1.txt");
    //ofstream of("./2.txt");
    int n,m,seat,eseat;
    long long id;
    mf>>n;
    //cout<<n;
    for(int i = 0;i < n;i++){
        mf>>id>>seat>>eseat;
        student[seat].id = id;
        student[seat].eseat = eseat;}
    mf>>m;
    for(int i = 0;i < m;i++){
    mf>>seat;
    cout<<student[seat].id<<" "<<student[seat].eseat<<endl;
    }
    mf.close();

}