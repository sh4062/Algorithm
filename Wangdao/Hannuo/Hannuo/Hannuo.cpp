#include <iostream>

using namespace std;

void TowersofHanoi(int n,char x,char y,char z)
{

        if(n)
        {
            TowersofHanoi(n-1,x,z,y);//��n-1�����Ӵ�x�ƶ���z
            cout << "From" << x << "To" << y << endl;//����n�������ƶ���y
            TowersofHanoi(n-1,z,y,x);//��z�ϵ������ƶ���y
        }
}

int main()
{
    TowersofHanoi(3,'A','B','C');
    return 0;
}