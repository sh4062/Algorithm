//1022. Digital Library (30)
#include <bits/stdc++.h>
using namespace std;

struct book
{
    int id;
    string title;
    string author;
    //vector<string> keywords;
    string keywords;
    string publisher;
    int year;
};
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    string tmps;
    getline(cin, tmps);

    int n;
    n = stoi(tmps);

    vector<book> res;

    int a;
    while (n--)
    {
        book tmp;

        getline(cin, tmps);
        tmp.id = stoi(tmps);
        getline(cin, tmp.title);

        getline(cin, tmp.author);
        //vector<string> keywords;
        // string tmps;
        getline(cin, tmp.keywords);
        getline(cin, tmp.publisher);
        getline(cin, tmps);
        tmp.year = stoi(tmps);
        res.push_back(tmp);
    }
    // map<int,string>mapp[5];
    // for (auto i:res){
    //     mapp[0][i.id] = i;
    // }
    int q;
    int qq;
    char *qss;
    cin >> q;
    getchar();
    set<int> out;
    while (q--)
    {

        scanf("%d:", &qq);
        getchar();
        string qs;
        getline(cin, qs);

        for (auto i : res)
        {
            if (qq == 5)
            {
                if (i.year == stoi(qs))
                {
                    out.insert(i.id);
                    //cout << i.id<<'\n';
                }
            }
            else if (qq == 4)
            {
                if (i.publisher.compare(qs) == 0)
                {
                    //cout << i.id<<'\n';
                    out.insert(i.id);
                }
            }
            else if (qq == 2)
            {
                if (i.author.compare(qs) == 0)
                {
                    // cout << i.id<<'\n';
                    out.insert(i.id);
                }
            }
            else if (qq == 1)
            {
                if (i.title.compare(qs) == 0)
                {
                    //cout << i.id<<'\n';
                    out.insert(i.id);
                }
            }
            else if (qq == 3)
            {
                if (i.keywords.find(qs) != -1)
                {
                    // cout << i.id<<'\n';
                    out.insert(i.id);
                }
            }
        }
        printf("%d: ",qq);
        cout<<qs<<'\n';
        if (out.size() == 0)
        {
            cout << "Not Found" << endl;
        }
        else
        {
            for (auto i : out)
               printf("%07d\n",i);
        }
        out.clear();
    }
}