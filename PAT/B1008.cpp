#include <iostream>
using namespace std;

class Solutions{
public:
    void reverse(int arr[],int prev,int back)
    {
        int tmp;
        while(prev<back)
        {
            tmp = arr[back];
            arr[back] = arr[prev];
            arr[prev] = tmp;
            ++prev;
            --back;
        }
    }

    void print(int arr[],int prev,int back)
    {
        for(int i=prev;i<back;++i)
        {
            cout << arr[i];
            if(i!=back-1)
                cout << ' ';
        }
    }
};

int main()
{
    Solutions s;
    int size,number;
    cin >> size >> number;
    int a[100];
    for(int i=0;i<size;++i)
        cin >> a[i];
    number = number%size;
    s.reverse(a,0,size-1-number);
    s.reverse(a,size-number,size-1);
    s.reverse(a,0,size-1);
    s.print(a,0,size);
}